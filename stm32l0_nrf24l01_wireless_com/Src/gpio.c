/*
 * ****************************************************
 * File:	gpio.c
 * Project:	RF communication with STM32 and nRF24L01+
 * MCU:		STM32L011K4
 * Others:	nRF24L01+
 * Author:	Theocharis Ketoglou
 * Date:	12/12/2021
 * ****************************************************
 */

#include "gpio.h"

void init_gpio(void){

	//Enable GPIO clock
	SET_BIT(RCC->IOPENR, RCC_IOPENR_IOPAEN); //Port A clock enable
	SET_BIT(RCC->IOPENR, RCC_IOPENR_IOPBEN); //Port B clock enable

	/*
	 * MODER Register Reset State:
	 * GPIOA_MODER = 0xEBFF FCFF
	 * GPIOx_MODER = 0xFFFF FFFF
	 */

	//IRQ: PA8 (GPI, Push-Pull, High Speed, Pull Up)
	CLEAR_BIT(GPIOA->MODER, (GPIO_MODER_MODE8_1 | GPIO_MODER_MODE8_0));
	SET_BIT(GPIOA->OSPEEDR, GPIO_OSPEEDER_OSPEED8_1);
	SET_BIT(GPIOA->PUPDR, GPIO_PUPDR_PUPD8_0);

	//SPI MOSI: PA7 (AF, Push-Pull, Medium Speed, No pull up/down)(AF0:MOSI)
	CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODE7_0);
	SET_BIT(GPIOA->OSPEEDR, GPIO_OSPEEDER_OSPEED7_0); //Medium speed (2MHz)

	//SPI MISO: PA6 (AF, Push-Pull, Medium Speed, No pull up/down)(AF0:MISO)
	CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODE6_0);
	SET_BIT(GPIOA->OSPEEDR, GPIO_OSPEEDER_OSPEED6_0); //Medium speed (2MHz)

	//SPI SCK: PA5 (AF, Push-Pull, Medium Speed, No pull up/down)(AF0:SCK)
	CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODE5_0);
	SET_BIT(GPIOA->OSPEEDR, GPIO_OSPEEDER_OSPEED5_0); //Medium speed (2MHz)

	//SPI CSN: PA4 (GPO, Push-Pull, Medium Speed,Pull up)
	SET_BIT(GPIOA->MODER, GPIO_MODER_MODE4_0);
	SET_BIT(GPIOA->OSPEEDR, GPIO_OSPEEDER_OSPEED4_0); //Medium speed (2MHz)
	SET_BIT(GPIOA->PUPDR, GPIO_PUPDR_PUPD4_0);

	//CE : PB1 (GPO, Push-Pull, Medium Speed,No pull up/down)
	CLEAR_BIT(GPIOB->MODER, GPIO_MODER_MODE1_1);
	SET_BIT(GPIOB->OSPEEDR, GPIO_OSPEEDER_OSPEED1_0); //Medium speed (2MHz)

	//LED : PB3 (GPO, Push-Pull, Medium Speed,No pull up/down)
	CLEAR_BIT(GPIOB->MODER, GPIO_MODER_MODE3_1);
	SET_BIT(GPIOB->OSPEEDR, GPIO_OSPEEDER_OSPEED3_0); //Medium speed (2MHz)

}
