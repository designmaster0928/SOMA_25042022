/*
 * audioPlay.c
 *
 *  Created on: May 20, 2022
 *      Author: Administrator
 */
#include <string.h>
#include "files.h"
#include "mp3dec.h"
#include "main.h"
#include "audioPlay.h"
#include "sgtl5000.h"
#include "fatfs.h"

#define DEF_I2S2	2 // CODEC chip uses I2S2
extern I2S_HandleTypeDef hi2s2;


typedef struct wavfile_header_s
{
  char    ChunkID[4];     /*  4   */
  int32_t ChunkSize;      /*  4   */
  char    Format[4];      /*  4   */

  char    Subchunk1ID[4]; /*  4   */
  int32_t Subchunk1Size;  /*  4   */
  int16_t AudioFormat;    /*  2   */
  int16_t NumChannels;    /*  2   */
  int32_t SampleRate;     /*  4   */
  int32_t ByteRate;       /*  4   */
  int16_t BlockAlign;     /*  2   */
  int16_t BitsPerSample;  /*  2   */

  char    Subchunk2ID[4];
  int32_t Subchunk2Size;
} wavfile_header_t;


extern PlayState	playState;

#define READBUF_SIZE  1940

uint8_t read_buf [READBUF_SIZE*2];
uint8_t *read_ptr;
int16_t out_buf  [2 * 1152];
int     bytes_left;

//static bool is_init = false;
static bool is_started = false;

static uint32_t i2s_sample_rate = 16000;

#define I2S_BUF_LEN   (1024*4)
#define I2S_BUF_MS    (10)

typedef struct
{
  int16_t left;
  int16_t right;
} i2s_sample_t;

static volatile uint32_t q_in;
static volatile uint32_t q_out;
static volatile uint32_t q_len;
static volatile uint32_t q_buf_len;
static i2s_sample_t q_buf[I2S_BUF_LEN];

const int16_t q_buf_zero[I2S_BUF_LEN*2] = {0, };


static int fillReadBuffer(uint8_t *read_buf, uint8_t *read_ptr, int buf_size, int bytes_left, FILE *infile)
{
  int nRead;

  /* move last, small chunk from end of buffer to start, then fill with new data */
  memmove(read_buf, read_ptr, bytes_left);
  nRead = fread( read_buf + bytes_left, 1, buf_size - bytes_left, infile);
  /* zero-pad to avoid finding false sync word after last frame (from old data in readBuf) */
  if (nRead < buf_size - bytes_left)
  {
    memset(read_buf + bytes_left + nRead, 0, buf_size - bytes_left - nRead);
  }
  return nRead;
}

bool i2sStart(void)
{
  HAL_StatusTypeDef status;
  I2S_HandleTypeDef *p_i2s = &hi2s2;

  q_in  = 0;
  q_out = 0;

  status = HAL_I2S_Transmit_DMA(p_i2s, (uint16_t *)q_buf_zero, q_buf_len*2);
  if (status == HAL_OK)
  {
    is_started = true;
  }

  return is_started;
}

bool i2sStop(void)
{
  is_started = false;

  return true;
}

bool i2sSetSampleRate(uint8_t ch, uint32_t freq)
{
	bool ret = true;

	i2s_sample_rate = freq;

	q_buf_len = (i2s_sample_rate * 1) / (1000/I2S_BUF_MS);
	q_in  = 0;
	q_out = 0;
	q_len = I2S_BUF_LEN / q_buf_len;



	hi2s2.Init.AudioFreq = freq;
	if (HAL_I2S_Init(&hi2s2) != HAL_OK)
	{
		ret = false;
	}

	i2sStart();
	i2sStop();

	sgtl5000_set_freq(freq);

	HAL_Delay(10);

	return ret;
}

void PlayAudioFile(char* fileName, char* fileType)
{
	bool ret = true;

	if (strcmp(fileType, "playWAV") == 0)
	{
		FILE *fp;
		wavfile_header_t header;
		uint32_t r_len;

		printf("FileName      : %s\n", fileName);

		fp = fopen(fileName, "r");
		if (fp == NULL)
		{
			printf("fopen fail : %s\n", fileName);
			SetPlayState(PLAY_NONE);
			return;
		}
		fread(&header, sizeof(wavfile_header_t), 1, fp);

		printf("ChunkSize     : %d\n", header.ChunkSize);
		printf("Format        : %c%c%c%c\n", header.Format[0], header.Format[1], header.Format[2], header.Format[3]);
		printf("Subchunk1Size : %d\n", header.Subchunk1Size);
		printf("AudioFormat   : %d\n", header.AudioFormat);
		printf("NumChannels   : %d\n", header.NumChannels);
		printf("SampleRate    : %d\n", header.SampleRate);
		printf("ByteRate      : %d\n", header.ByteRate);
		printf("BlockAlign    : %d\n", header.BlockAlign);
		printf("BitsPerSample : %d\n", header.BitsPerSample);
		printf("Subchunk2Size : %d\n", header.Subchunk2Size);


		i2sSetSampleRate(DEF_I2S2, header.SampleRate);

		i2sStart();

		r_len = q_buf_len;

		int16_t buf_frame[q_buf_len*2];

		fseek(fp, sizeof(wavfile_header_t), SEEK_SET);

		while(playState == PLAY_STARTED)
		{
			uint32_t buf_len;
			int len;

			buf_len = ((q_len + q_in - q_out) % q_len);
			buf_len = (q_len - buf_len) - 1;

			if (buf_len > 0)
			{
				HAL_GPIO_WritePin(GPIOE, SYS_LOCK_Pin, GPIO_PIN_SET);
				len = fread(buf_frame, r_len, 2*header.NumChannels, fp);

				if (len != r_len*2*header.NumChannels)
				{
					SetPlayState(PLAY_NONE);
					break;
				}

				uint32_t q_offset;

				q_offset = q_in*q_buf_len;

				for (int i=0; i<r_len; i++)
				{
					if (header.NumChannels == 2)
					{
						q_buf[q_offset + i].left  = buf_frame[i*2 + 0];
						q_buf[q_offset + i].right = buf_frame[i*2 + 1];
					}
					else
					{
						q_buf[q_offset + i].left  = buf_frame[i];
						q_buf[q_offset + i].right = buf_frame[i];
					}
				}

				if (((q_in + 1) % q_len) != q_out)
				{
					q_in = (q_in+1) % q_len;
				}
				HAL_GPIO_WritePin(GPIOE, SYS_LOCK_Pin, GPIO_PIN_RESET);
			}
		}

		i2sStop();

		fclose(fp);

		ret = true;
	}

	if (strcmp(fileType, "playMP3") == 0)
	{
		printf("FileName      : %s\n", fileName);

		HMP3Decoder h_dec;
		h_dec = MP3InitDecoder();
		if (h_dec != 0)
		{
			MP3FrameInfo frameInfo;
			FILE *fp;
			fp = fopen(fileName, "r");
			if (fp == NULL)
			{
				printf("fopen fail : %s\n", fileName);
				SetPlayState(PLAY_NONE);
				return;
			}

			//int offset;
			int err;
			int n_read;

			bytes_left = 0;
			read_ptr = read_buf;

			n_read = fillReadBuffer(read_buf, read_ptr, READBUF_SIZE, bytes_left, fp);

			bytes_left += n_read;
			read_ptr = read_buf;

			n_read = MP3FindSyncWord(read_ptr, READBUF_SIZE);
			printf("Offset: %d\n", n_read);

			bytes_left -= n_read;
			read_ptr += n_read;

			n_read = fillReadBuffer(read_buf, read_ptr, READBUF_SIZE, bytes_left, fp);
			bytes_left += n_read;
			read_ptr = read_buf;

			err = MP3GetNextFrameInfo(h_dec, &frameInfo, read_ptr);
			if (err != ERR_MP3_INVALID_FRAMEHEADER)
			{
				printf("samplerate     %d\n", frameInfo.samprate);
				printf("bitrate        %d\n", frameInfo.bitrate);
				printf("nChans         %d\n", frameInfo.nChans);
				printf("outputSamps    %d\n", frameInfo.outputSamps);
				printf("bitsPerSample  %d\n", frameInfo.bitsPerSample);

				i2sSetSampleRate(DEF_I2S2, frameInfo.samprate);

				q_buf_len = frameInfo.outputSamps / frameInfo.nChans;
				q_in  = 0;
				q_out = 0;
				q_len = I2S_BUF_LEN / q_buf_len;

				i2sStart();
			}

			while(playState == PLAY_STARTED)
			{
				if (bytes_left < READBUF_SIZE)
				{
					HAL_GPIO_WritePin(GPIOE, SYS_LOCK_Pin, GPIO_PIN_SET);
					n_read = fillReadBuffer(read_buf, read_ptr, READBUF_SIZE, bytes_left, fp);

					if (n_read == 0 )
					{
						SetPlayState(PLAY_NONE);
						break;
					}
					bytes_left += n_read;
					read_ptr = read_buf;
				}


				n_read = MP3FindSyncWord(read_ptr, bytes_left);
				if (n_read >= 0)
				{
					read_ptr += n_read;
					bytes_left -= n_read;


					//fill the inactive outbuffer
					err = MP3Decode(h_dec, &read_ptr, (int*) &bytes_left, out_buf, 0);
					HAL_GPIO_WritePin(GPIOE, SYS_LOCK_Pin, GPIO_PIN_RESET);
					if (err)
					{
						// sometimes we have a bad frame, lets just nudge forward one byte
						if (err == ERR_MP3_INVALID_FRAMEHEADER)
						{
							read_ptr   += 1;
							bytes_left -= 1;
						}
					}
					else
					{

						uint32_t pre_time;
						uint32_t valid_len;

						pre_time = HAL_GetTick();
						while(1)
						{
							valid_len = (q_len - 1) - ((q_len + q_in - q_out) % q_len);

							if (valid_len > 0)
							{
								break;
							}
							if (HAL_GetTick()-pre_time >= 100)
							{
								break;
							}
						}


						uint32_t q_offset;

						q_offset   = q_in*q_buf_len;

						for (int j=0; j<q_buf_len; j++)
						{
							q_buf[q_offset + j].left  = out_buf[j*2 + 0];
							q_buf[q_offset + j].right = out_buf[j*2 + 1];
						}
						if (((q_in + 1) % q_len) != q_out)
						{
							q_in = (q_in+1) % q_len;
						}
					}
				}
			}
			i2sStop();
			fclose(fp);
		}
	}

}

void HAL_I2S_TxHalfCpltCallback(I2S_HandleTypeDef *hi2s) {

	HAL_GPIO_WritePin(GPIOE, LID_UPDN_Pin, GPIO_PIN_RESET);
}

void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef *hi2s) {
	HAL_GPIO_WritePin(GPIOE, LID_UPDN_Pin, GPIO_PIN_SET);

	uint32_t len;

	if (is_started != true)
	{
		return;
	}

	len = (q_len + q_in - q_out) % q_len;

	if (len > 0)
	{
		HAL_I2S_Transmit_DMA(hi2s, (uint16_t *)&q_buf[q_out*q_buf_len], q_buf_len * 2);

		if (q_out != q_in)
		{
			q_out = (q_out + 1) % q_len;
		}
	}
	else
	{
		HAL_I2S_Transmit_DMA(hi2s, (uint16_t *)q_buf_zero, q_buf_len*2);
	}
}
