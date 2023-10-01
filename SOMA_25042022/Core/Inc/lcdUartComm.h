/*
 * lcdUartComm.h
 *
 *  Created on: May 22, 2022
 *      Author: Administrator
 */

#ifndef INC_LCDUARTCOMM_H_
#define INC_LCDUARTCOMM_H_

#include "stm32f4xx_hal.h"

void StartLcdUartReceiveProc(void);
void LcdUartReceiveCallback(UART_HandleTypeDef *huart);
void EsimationLcdUartComm(void);

#endif /* INC_LCDUARTCOMM_H_ */
