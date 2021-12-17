/*
 * ****************************************************
 * File:	gpio.h
 * Project:	RF communication with STM32 and nRF24L01+
 * MCU:		STM32L011K4
 * Others:	nRF24L01+
 * Author:	Theocharis Ketoglou
 * Date:	12/12/2021
 * ****************************************************
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "CMSIS/stm32l0xx.h"


#define CSN_PIN_EN()	(CLEAR_BIT(GPIOA->ODR, GPIO_ODR_OD4))
#define CSN_PIN_DIS()	(SET_BIT(GPIOA->ODR, GPIO_ODR_OD4))
#define CE_ACTIVATE()	(SET_BIT(GPIOB->ODR, GPIO_ODR_OD1))
#define CE_DEACTIVATE()	(CLEAR_BIT(GPIOB->ODR, GPIO_ODR_OD1))
#define	LED_ON()		(SET_BIT(GPIOB->ODR, GPIO_ODR_OD3))
#define	LED_OFF()		(CLEAR_BIT(GPIOB->ODR, GPIO_ODR_OD3))
#define LED_CHANGE()	(GPIOB->ODR ^= GPIO_ODR_OD3)

/**
 * 	@function init_gpio
 *
 *	@brief Simple function initialize the pins of
 *	STM MCU.
 *
 * 	@return void
 */
void init_gpio(void);

#endif /* GPIO_H_ */
