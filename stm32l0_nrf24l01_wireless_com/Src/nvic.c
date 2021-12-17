/*
 * ****************************************************
 * File:	nvic.c
 * Project:	RF communication with STM32 and nRF24L01+
 * MCU:		STM32L011K4
 * Others:	nRF24L01+
 * Author:	Theocharis Ketoglou
 * Date:	12/12/2021
 * ****************************************************
 */

#include "nvic.h"
#include "spi.h"
#include "flags.h"
#include "gpio.h"

//Variables
uint32_t ms_time = 0; //Used by delay_ms function

//**************************************************************************************************************************************************************

void init_external_irq(void){

	//Enable System configuration controller
	SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);

	//Enable external interrupt from line 8
	SET_BIT(EXTI->IMR, EXTI_IMR_IM8);
	//Enable interrupt on falling edge from line 8
	SET_BIT(EXTI->FTSR, EXTI_FTSR_FT8);
	//Configure PA8 as interrupt source
	SYSCFG->EXTICR[2] &= (0xFFF0 | SYSCFG_EXTICR3_EXTI8_PA);

	//Enable EXTI4_15 Interrupt
	NVIC_EnableIRQ(EXTI4_15_IRQn);
}

//**************************************************************************************************************************************************************

void SPI1_IRQHandler(void){

	//RX buffer not empty interrupt
	if(READ_BIT(SPI1->SR, SPI_SR_RXNE)){
		SPI_RX_BUFFER[SPI_RX_COUNTER] = SPI1->DR;
		SPI_RX_COUNTER ++;
	}

	//TX buffer empty interrupt
	if(READ_BIT(SPI1->SR, SPI_SR_TXE)){

		if(!SPI_TX_SIZE){
			//Disable NSS pin
			CSN_PIN_DIS();
			//Disable SPI TX interrupt
			CLEAR_BIT(SPI1->CR2, SPI_CR2_TXEIE);
		}else{
			WRITE_REG(SPI1->DR, SPI_TX_BUFFER[SPI_TX_COUNTER]);
			SPI_TX_SIZE --;
			SPI_TX_COUNTER ++;
		}

	}

}

//**************************************************************************************************************************************************************

void EXTI4_15_IRQHandler(void){

	//Interrupt on line 8
	if(READ_BIT(EXTI->PR, EXTI_PR_PIF8)){

		flag0.f1 = 1;

		//Clear flag
		SET_BIT(EXTI->PR, EXTI_PR_PIF8);
	}
}

//**************************************************************************************************************************************************************

void TIM2_IRQHandler(void){

	if(flag0.f0)
		ms_time ++;

	//Clear Timer 2 Flag
	CLEAR_BIT(TIM2->SR, TIM_SR_UIF);
}

//**************************************************************************************************************************************************************

void delay_ms(uint32_t time){
	ms_time = 0;	//Clear time
	flag0.f0 = 1; //Enable count flag
	while(ms_time < time);
	flag0.f0 = 0;	//Disable count flag
}

//**************************************************************************************************************************************************************
