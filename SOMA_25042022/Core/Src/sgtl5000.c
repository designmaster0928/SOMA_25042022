/*
 * sgtl5000.c
 *
 *  Created on: May 13, 2022
 *      Author: Administrator
 */

#include "sgtl5000.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c2;

CHIP_ID 		chip_id;
CHIP_DIG_POWER 	chip_dig_power;
CHIP_DAC_VOL 	chip_dac_vol;
CHIP_I2S_CTRL 	chip_i2s_ctrl;
CHIP_PAD_STRENGTH	chip_pad_strength;
CHIP_ANA_ADC_CTRL 	chip_ana_adc_ctrl;
CHIP_LINREG_CTRL 	chip_lingeg_ctrl;
CHIP_ANA_HP_CTRL 	chip_ana_hp_ctrl;
CHIP_REF_CTRL 		chip_ref_ctrl;
CHIP_LINE_OUT_CTRL 	chip_line_out_ctrl;
CHIP_ANA_POWER 		chip_ana_power;
CHIP_LINE_OUT_VOL 	chip_line_out_vol;
CHIP_CLK_TOP_CTRL 	chip_clk_top_ctrl;
CHIP_ANA_STATUS 	chip_ana_status;
CHIP_ANA_TEST1 		chip_ana_test1;
CHIP_ANA_TEST2 		chip_ana_test2;
CHIP_SHORT_CTRL 	chip_short_ctrl;
DAP_CONTROL 		dap_control;
DAP_PEQ 			dap_peq;
DAP_BASS_ENHANCE 	dap_bass_enhance;
DAP_BASS_ENHANCE_CTRL 	dap_bass_enhance_ctrl;
DAP_AUDIO_EQ 		dap_audio_eq;
DAP_FILTER_COEF_ACCESS	dap_filter_coef_access;
DAP_SGTL_SURROUND 	dap_sgtl_surround;
DAP_COEF_WR_B0_MSB 	dap_coef_wr_b0_msb;
DAP_COEF_WR_B0_LSB 	dap_coef_wr_b0_lsb;
DAP_AUDIO_EQ_BASS_BAND0 	dap_audio_eq_bass_band0;
DAP_AUDIO_EQ_BAND1 	dap_audio_eq_band1;
DAP_AUDIO_EQ_BAND2 	dap_audio_eq_band2;
DAP_AUDIO_EQ_BAND3 	dap_audio_eq_band3;
DAP_AUDIO_EQ_TREBLE_BAND4 	dap_audio_eq_treble_band4;
DAP_AVC_CTRL 		dap_avc_ctrl;
DAP_AVC_ATTACK 		dap_avc_attack;
DAP_AVC_DECAY 		dap_avc_decay;
DAP_COEF_WR_B2_LSB 	dap_coef_wr_b2_lsb;
CHIP_PLL_CTRL		chip_pll_ctrl;
CHIP_CLK_CTRL		chip_clk_ctrl;
CHIP_ADCDAC_CTRL	chip_adcdac_ctrl;
CHIP_ANA_CTRL		chip_ana_ctrl;
CHIP_MIC_CTRL 		chip_mic_ctrl;
CHIP_SSS_CTRL 		chip_sss_ctrl;


uint16_t sgtl5000_read(uint16_t reg){
	uint8_t buff[2];

	buff[1]=0xff & reg;
	buff[0]=0xff & reg>>8;

	HAL_I2C_Master_Transmit(&hi2c2,WRITE_ADDRESS,buff,2,0xFF);
	HAL_Delay(1);
	HAL_I2C_Master_Receive(&hi2c2, READ_ADDRESS, buff, 2, 0xFF);
	HAL_Delay(1);
	return (uint16_t)buff[0]<<8 | buff[1];

}

void sgtl5000_write(uint16_t reg, uint16_t data){

	uint8_t buff[4];

	buff[3]=0xff & data;
	buff[2]=0xff & data>>8;
	buff[1]=0xff & reg;
	buff[0]=0xff & reg>>8;


	uint8_t ret = HAL_I2C_Master_Transmit(&hi2c2,WRITE_ADDRESS,buff,4,0xFF);

	HAL_Delay(1);
}



void sgtl5000_set_volume(uint8_t vol){

	sgtl5000_write(CHIP_ANA_HP_CTRL_ADD, (uint16_t)vol<<8 | vol );
}

void sgtl5000_set_freq(uint32_t freq){
	switch(freq)
	{
		case 32000:
			sgtl5000_write(CHIP_CLK_CTRL_ADD, 0x0000);  // 48k kHz, 256*Fs
		case 48000:
			sgtl5000_write(CHIP_CLK_CTRL_ADD, 0x0008);  // 48k kHz, 256*Fs
		case 96000:
			sgtl5000_write(CHIP_CLK_CTRL_ADD, 0x000C);  // 48k kHz, 256*Fs
		default:
			sgtl5000_write(CHIP_CLK_CTRL_ADD, 0x0004);  // 44.1k kHz, 256*Fs
	}
}

void sgtl5000_start_play(void){
	chip_ana_ctrl.data = sgtl5000_read(CHIP_ANA_CTRL_ADD);
	chip_ana_ctrl.MUTE_HP = 0x0000; //unmute amp
	chip_ana_ctrl.MUTE_LO = 0x0000; //unmute headphone
	chip_ana_ctrl.MUTE_ADC = 0x0001; //mute microphone
	sgtl5000_write(CHIP_ANA_CTRL_ADD, chip_ana_ctrl.data);
}

void sgtl5000_stop_play(void){
	chip_ana_ctrl.data = sgtl5000_read(CHIP_ANA_CTRL_ADD);
	chip_ana_ctrl.MUTE_HP = 0x0001; //unmute amp
	chip_ana_ctrl.MUTE_LO = 0x0001; //unmute headphone
	chip_ana_ctrl.MUTE_ADC = 0x0001; //mute microphone
	sgtl5000_write(CHIP_ANA_CTRL_ADD, chip_ana_ctrl.data);
}

void sgtl5000_start_receive(void){

	chip_ana_ctrl.data = sgtl5000_read(CHIP_ANA_CTRL_ADD);
	chip_ana_ctrl.MUTE_HP = 0x0001; //mute amp
	//chip_ana_ctrl.MUTE_LO = 0x0001; //mute headphone
	chip_ana_ctrl.MUTE_ADC = 0x0000; //unmute microphone

	sgtl5000_write(CHIP_ANA_CTRL_ADD, chip_ana_ctrl.data);

}
void sgtl5000_init(void){

	sgtl5000_write(CHIP_ANA_POWER_ADD, 0x4060);  // VDDD is externally driven with 1.8V
	sgtl5000_write(CHIP_LINREG_CTRL_ADD, 0x006C);  // VDDA & VDDIO both over 3.1V
	sgtl5000_write(CHIP_REF_CTRL_ADD, 0x01F2); // VAG=1.575, normal ramp, +12.5% bias current
	sgtl5000_write(CHIP_LINE_OUT_CTRL_ADD, 0x0F22); // LO_VAGCNTRL=1.65V, OUT_CURRENT=0.54mA
	sgtl5000_write(CHIP_SHORT_CTRL_ADD, 0x4446);  // allow up to 125mA
	sgtl5000_write(CHIP_ANA_CTRL_ADD, 0x0137);  // enable zero cross detectors
	sgtl5000_write(CHIP_ANA_POWER_ADD, 0x40FF); // power up: lineout, hp, adc, dac
	sgtl5000_write(CHIP_DIG_POWER_ADD, 0x0073); // power up all digital stuff
	HAL_Delay(400);

	sgtl5000_write(CHIP_LINE_OUT_VOL_ADD, 0x1D1D); // default approx 1.3 volts peak-to-peak
	sgtl5000_write(CHIP_CLK_CTRL_ADD, 0x0004);  // 44.1k kHz, 256*Fs
	sgtl5000_write(CHIP_I2S_CTRL_ADD, 0x0130); // SCLK=32*Fs, 16bit, I2S format



	// Example 1: I2S_IN -> DAP -> DAC -> LINEOUT, HP_OUT
	chip_sss_ctrl.data=sgtl5000_read(CHIP_SSS_CTRL_ADD);
	//chip_sss_ctrl.DAP_MIX_SELECT=0x0001; // bits 7:6
	// Route I2S_IN to DAP
	chip_sss_ctrl.DAP_SELECT=0x0001; // bits 7:6
	// Route DAP to DAC
	chip_sss_ctrl.DAC_SELECT=0x0003; // bits 5:4
	//chip_sss_ctrl.I2S_SELECT=0x0001; // bits 5:4
	chip_sss_ctrl.I2S_SELECT=0x0000; // bits 1:0

	sgtl5000_write(CHIP_SSS_CTRL_ADD,chip_sss_ctrl.data);
	// Select DAC as the input to HP_OUT
	chip_ana_ctrl.data=sgtl5000_read(CHIP_ANA_CTRL_ADD);
	//chip_ana_ctrl.SELECT_ADC = 0x0001; // bit 2

	chip_ana_ctrl.SELECT_HP = 0x0000; // bit 6
	sgtl5000_write(CHIP_ANA_CTRL_ADD,chip_ana_ctrl.data);




	// Enable DAP block
	// NOTE: DAP will be in a pass-through mode if none of DAP
	// sub-blocks are enabled.
	dap_control.data= sgtl5000_read(DAP_CONTROL_ADD);
	dap_control.DAP_EN=1;
	//dap_control.MIX_EN=1;
	sgtl5000_write(DAP_CONTROL_ADD,dap_control.data); // bit 0

	sgtl5000_write(DAP_MAIN_CHAN_ADD,0xFFFF); // bit 0
	sgtl5000_write(DAP_MIX_CHAN_ADD,0xFFFF); // bit 0

	dap_avc_ctrl.data = sgtl5000_read(DAP_AVC_CTRL_ADD);
	dap_avc_ctrl.EN=1;
	sgtl5000_write(DAP_AVC_CTRL_ADD,dap_avc_ctrl.data);
	//---------------- Input Volume Control---------------------
	// Configure ADC left and right analog volume to desired default.
	// Example shows volume of 0dB
	sgtl5000_write( CHIP_ANA_ADC_CTRL_ADD, 0x0000);
	// Configure MIC gain if needed. Example shows gain of 20dB
	chip_mic_ctrl.data = sgtl5000_read(CHIP_MIC_CTRL_ADD);
	chip_mic_ctrl.GAIN = 0x0001;
	sgtl5000_write(CHIP_MIC_CTRL_ADD, chip_mic_ctrl.data);
	// LINEOUT and DAC volume control

	chip_ana_ctrl.data = sgtl5000_read(CHIP_ANA_CTRL_ADD);

	chip_ana_ctrl.MUTE_LO = 0x0000;
	chip_ana_ctrl.MUTE_HP = 0x0000; //unmute amp
	sgtl5000_write (CHIP_ANA_CTRL_ADD, chip_ana_ctrl.data);
	// bit 8
	// Configure DAC left and right digital volume. Example shows
	// volume of 0dB
	sgtl5000_write(CHIP_DAC_VOL_ADD, 0x3C3C);

	chip_adcdac_ctrl.data = sgtl5000_read(CHIP_ADCDAC_CTRL_ADD);
	chip_adcdac_ctrl.DAC_MUTE_LEFT=0x0000;// bit 2
	chip_adcdac_ctrl.DAC_MUTE_RIGHT=0x0000;// bit 3
	sgtl5000_write(CHIP_ADCDAC_CTRL_ADD,chip_adcdac_ctrl.data);


	// Unmute ADC
	//chip_ana_ctrl.data = sgtl5000_read(CHIP_ANA_CTRL_ADD);
	//chip_ana_ctrl.MUTE_ADC= 0x0000;

	//write(CHIP_ANA_CTRL_ADD,chip_ana_ctrl.data);

}

