/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>

#include "at_ble_api.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BT_WIFI_IRQN_Pin GPIO_PIN_4
#define BT_WIFI_IRQN_GPIO_Port GPIOE
#define BT_WIFI_IRQN_EXTI_IRQn EXTI4_IRQn
#define SD_DETECTS_Pin GPIO_PIN_5
#define SD_DETECTS_GPIO_Port GPIOE
#define LID_UPDN_Pin GPIO_PIN_6
#define LID_UPDN_GPIO_Port GPIOE
#define HP_SPKR_SDA_Pin GPIO_PIN_0
#define HP_SPKR_SDA_GPIO_Port GPIOF
#define HP_SPKR_SCL_Pin GPIO_PIN_1
#define HP_SPKR_SCL_GPIO_Port GPIOF
#define BT_WIFI_SPI_CS_Pin GPIO_PIN_6
#define BT_WIFI_SPI_CS_GPIO_Port GPIOF
#define BT_WIFI_SPI_SCK_Pin GPIO_PIN_7
#define BT_WIFI_SPI_SCK_GPIO_Port GPIOF
#define BT_WIFI_SPI_MISO_Pin GPIO_PIN_8
#define BT_WIFI_SPI_MISO_GPIO_Port GPIOF
#define BT_WIFI_SPI_MOSI_Pin GPIO_PIN_9
#define BT_WIFI_SPI_MOSI_GPIO_Port GPIOF
#define BT_WIFI_CHIP_EN_Pin GPIO_PIN_0
#define BT_WIFI_CHIP_EN_GPIO_Port GPIOC
#define LED_PWM_R_Pin GPIO_PIN_0
#define LED_PWM_R_GPIO_Port GPIOA
#define BT_TX_Pin GPIO_PIN_2
#define BT_TX_GPIO_Port GPIOA
#define BT_RX_Pin GPIO_PIN_3
#define BT_RX_GPIO_Port GPIOA
#define SD_SPI3_CS_Pin GPIO_PIN_4
#define SD_SPI3_CS_GPIO_Port GPIOA
#define LED_PWM_W2400_Pin GPIO_PIN_6
#define LED_PWM_W2400_GPIO_Port GPIOA
#define BT_WIFI_RESETN_Pin GPIO_PIN_1
#define BT_WIFI_RESETN_GPIO_Port GPIOB
#define DBG_UART_RX_Pin GPIO_PIN_7
#define DBG_UART_RX_GPIO_Port GPIOE
#define DBG_UART_TX_Pin GPIO_PIN_8
#define DBG_UART_TX_GPIO_Port GPIOE
#define LED_PWM_B_Pin GPIO_PIN_9
#define LED_PWM_B_GPIO_Port GPIOE
#define WIFI_TX_Pin GPIO_PIN_10
#define WIFI_TX_GPIO_Port GPIOB
#define WIFI_RX_Pin GPIO_PIN_11
#define WIFI_RX_GPIO_Port GPIOB
#define I2S_LRCLK_Pin GPIO_PIN_12
#define I2S_LRCLK_GPIO_Port GPIOB
#define I2S_CLK_Pin GPIO_PIN_13
#define I2S_CLK_GPIO_Port GPIOB
#define I2S_SDI_Pin GPIO_PIN_14
#define I2S_SDI_GPIO_Port GPIOB
#define I2S_SDO_Pin GPIO_PIN_15
#define I2S_SDO_GPIO_Port GPIOB
#define LED_PWM_W6500_Pin GPIO_PIN_12
#define LED_PWM_W6500_GPIO_Port GPIOD
#define LED_PWM_G_Pin GPIO_PIN_14
#define LED_PWM_G_GPIO_Port GPIOD
#define I2S_MCLK_Pin GPIO_PIN_6
#define I2S_MCLK_GPIO_Port GPIOC
#define LCD_UART_TX_Pin GPIO_PIN_9
#define LCD_UART_TX_GPIO_Port GPIOA
#define LCD_UART_RX_Pin GPIO_PIN_10
#define LCD_UART_RX_GPIO_Port GPIOA
#define FAN_ON_Pin GPIO_PIN_11
#define FAN_ON_GPIO_Port GPIOA
#define PLAY_OUT_Pin GPIO_PIN_12
#define PLAY_OUT_GPIO_Port GPIOA
#define SD_SPI3_CLK_Pin GPIO_PIN_10
#define SD_SPI3_CLK_GPIO_Port GPIOC
#define SD_SPI3_MISO_Pin GPIO_PIN_11
#define SD_SPI3_MISO_GPIO_Port GPIOC
#define SD_SPI3_MOSI_Pin GPIO_PIN_12
#define SD_SPI3_MOSI_GPIO_Port GPIOC
#define BT_WIFI_SCL_Pin GPIO_PIN_8
#define BT_WIFI_SCL_GPIO_Port GPIOB
#define BT_WIFI_SDA_Pin GPIO_PIN_9
#define BT_WIFI_SDA_GPIO_Port GPIOB
#define SYS_LOCK_Pin GPIO_PIN_0
#define SYS_LOCK_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */
typedef enum {
	PLAY_NONE = 0, PLAY_READY, PLAY_STARTED,
} PlayState;

void SetPlayState(PlayState playstate);
void StartPlayAudioFile(char *filename);

// UDP Client
#define MAIN_WLAN_SSID        "824 can fix your computer" /* < Destination SSID */
#define MAIN_WLAN_AUTH        M2M_WIFI_SEC_WPA_PSK /* < Security manner */
#define MAIN_WLAN_PSK         "Starks@824" /* < Password for Destination SSID */
//
//
//#define MAIN_WIFI_M2M_PRODUCT_NAME        "NMCTemp"
//#define MAIN_WIFI_M2M_SERVER_IP           0xC0A8027A /* 192.168.2.122 */
//#define MAIN_WIFI_M2M_SERVER_PORT         (3333)
////#define MAIN_WIFI_M2M_REPORT_INTERVAL     (1000)
////
//#define MAIN_WIFI_M2M_BUFFER_SIZE          1460
//
///** UDP MAX packet count */
//#define MAIN_WIFI_M2M_PACKET_COUNT         10
//
/** Application settings **/
#define APP_WIFI_STATION	1		// 1..5
#define APP_PACKET_COUNT	33		// 33 UDP packets of 1136 bytes each
#define APP_BUFFER_SIZE		1134
//
//#define APP_NUMBER_OF_RUN	2

// BLE WIFI PROVISIONING
/** Wi-Fi Settings */

#define M2M_DEVICE_NAME				"WINC3400_00:00"
#define MAC_ADDRESS					{0xf8, 0xf0, 0x05, 0x45, 0xD4, 0x84}
/***********************************************************************
 * DEFAULT SSID CREDENTIALS CONFIGURATIONS OF THE PEER ACCESS POINT *
 ************************************************************************/
#define DEFAULT_SSID				"DEMO_AP"
#define DEFAULT_AUTH				M2M_WIFI_SEC_WPA_PSK
#define	DEFAULT_KEY					"12345678"

#define WEP_KEY_INDEX				M2M_WIFI_WEP_KEY_INDEX_1
#define WEP_KEY						"1234567890"
#define WEP_KEY_SIZE				sizeof(WEP_KEY)

#define WEP_CONN_PARAM     { WEP_KEY_INDEX, WEP_KEY_SIZE, WEP_KEY}

#define AUTH_CREDENTIALS   { M2M_802_1X_USR_NAME, M2M_802_1X_PWD }

// SMTP
/** Using IP address. */
#define IPV4_BYTE(val, index)           ((val >> (index * 8)) & 0xFF)

/** All SMTP defines */
#define MAIN_SMTP_BUF_LEN               1024
#define MAIN_GMAIL_HOST_NAME            "smtp.gmail.com"
#define MAIN_GMAIL_HOST_PORT            465
#define MAIN_SENDER_RFC                 "<yugansh1992@gmail.com>" /* Set Sender Email Address */
#define MAIN_RECIPIENT_RFC              "<yugansh@volentech.com>"  /* Set Recipient Email Address */
#define MAIN_EMAIL_SUBJECT              "Hello from SOMA Board!"
#define MAIN_TO_ADDRESS                 "yugansh@volentech.com" /* Set To Email Address */
#define MAIN_FROM_ADDRESS               "yugansh1992@gmail.com" /* Set From Email Address */
#define MAIN_FROM_PASSWORD              "gjxiwhacuorstqdo"              /* Set Sender Email Password */
#define MAIN_EMAIL_MSG                  "This mail is sent from SOMA board-3."
#define MAIN_WAITING_TIME               30000
#define MAIN_RETRY_COUNT                3

/** Using NTP server information */
#define MAIN_WORLDWIDE_NTP_POOL_HOSTNAME        "*.pool.ntp.org"
#define MAIN_ASIA_NTP_POOL_HOSTNAME             "asia.pool.ntp.org"
#define MAIN_EUROPE_NTP_POOL_HOSTNAME           "europe.pool.ntp.org"
#define MAIN_NAMERICA_NTP_POOL_HOSTNAME         "north-america.pool.ntp.org"
#define MAIN_OCEANIA_NTP_POOL_HOSTNAME          "oceania.pool.ntp.org"
#define MAIN_SAMERICA_NTP_POOL_HOSTNAME         "south-america.pool.ntp.org"

typedef enum {
	SocketInit = 0, SocketConnect, SocketWaiting, SocketComplete, SocketError
} eSocketStatus;

typedef enum {
	SMTP_INACTIVE = 0,
	SMTP_INIT,
	SMTP_HELO,
	SMTP_AUTH,
	SMTP_AUTH_USERNAME,
	SMTP_AUTH_PASSWORD,
	SMTP_FROM,
	SMTP_RCPT,
	SMTP_DATA,
	SMTP_MESSAGE_SUBJECT,
	SMTP_MESSAGE_TO,
	SMTP_MESSAGE_FROM,
	SMTP_MESSAGE_CRLF,
	SMTP_MESSAGE_BODY,
	SMTP_MESSAGE_DATAEND,
	SMTP_QUIT,
	SMTP_ERROR
} eSMTPStatus;

/* Initialize error handling flags for smtp state machine */
typedef enum {
	MAIN_EMAIL_ERROR_FAILED = -1,
	MAIN_EMAIL_ERROR_NONE = 0,
	MAIN_EMAIL_ERROR_INIT,
	MAIN_EMAIL_ERROR_HELO,
	MAIN_EMAIL_ERROR_AUTH,
	MAIN_EMAIL_ERROR_AUTH_USERNAME,
	MAIN_EMAIL_ERROR_AUTH_PASSWORD,
	MAIN_EMAIL_ERROR_FROM,
	MAIN_EMAIL_ERROR_RCPT,
	MAIN_EMAIL_ERROR_DATA,
	MAIN_EMAIL_ERROR_MESSAGE,
	MAIN_EMAIL_ERROR_QUIT
} eMainEmailError;

extern uint8_t systemVolume;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
