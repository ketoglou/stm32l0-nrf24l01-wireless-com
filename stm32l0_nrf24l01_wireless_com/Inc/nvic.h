/*
 * ****************************************************
 * File:	nvic.h
 * Project:	RF communication with STM32 and nRF24L01+
 * MCU:		STM32L011K4
 * Others:	nRF24L01+
 * Author:	Theocharis Ketoglou
 * Date:	12/12/2021
 * ****************************************************
 */

#ifndef NVIC_H_
#define NVIC_H_

#include "CMSIS/stm32l0xx.h"

/**
 * 	@function init_external_irq
 *
 *	 @brief Initialize the external interrupts
 *
 * 	@return void
 */
void init_external_irq(void);

/**
 * 	@function delay_ms
 *
 *	 @brief Delay an amount of milliseconds
 *
 * 	@return void
 */
void delay_ms(uint32_t time);

#endif /* NVIC_H_ */
