/*
 * ****************************************************
 * File:	timers.h
 * Project:	RF communication with STM32 and nRF24L01+
 * MCU:		STM32L011K4
 * Others:	nRF24L01+
 * Author:	Theocharis Ketoglou
 * Date:	12/12/2021
 * ****************************************************
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "CMSIS/stm32l0xx.h"

/**
 * 	@function init_timer2
 *
 *	@brief Initialize Timer 2
 *
 * 	@return void
 */
void init_timer2(void);

#endif /* TIMERS_H_ */
