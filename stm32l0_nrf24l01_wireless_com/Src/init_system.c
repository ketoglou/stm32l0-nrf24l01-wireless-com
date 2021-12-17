/*
 * ****************************************************
 * File:	init_system.c
 * Project:	RF communication with STM32 and nRF24L01+
 * MCU:		STM32L011K4
 * Others:	nRF24L01+
 * Author:	Theocharis Ketoglou
 * Date:	12/12/2021
 * ****************************************************
 */

#include "init_system.h"

//**************************************************************************************************************************************************************

void init_emb_flash_mem(void){

	/*
	 *  ART ACCELARATOR PREFETCH ENABLE
	 *  LATENCY = 1 WS
	 */
	SET_BIT(FLASH->ACR, FLASH_ACR_LATENCY);
	SET_BIT(FLASH->ACR, FLASH_ACR_PRFTEN);

}

//**************************************************************************************************************************************************************

void init_rcc(void){


	//MSI => 2MHz clock
	SET_BIT(RCC->CR, RCC_CR_MSION); //MSI ON
	while(!READ_BIT(RCC->CR, RCC_CR_MSIRDY)); //Wait for MSI clock to be ready
	while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS)); //Wait for MSI to be the system clock

}

//**************************************************************************************************************************************************************

void init_iwdg(void){

	//Unlock IWDG_PR, IWDG_RLR registers
	WRITE_REG(IWDG->KR, 0x5555UL);

	//Set prescaler to 16 => 32kHz/16 = 2kHz
	WRITE_REG(IWDG->PR, 0x02UL);

	//Set reload counter to 500
	//With 2kHz clock we have 500/2000 = 0.25 sec = 250 ms
	WRITE_REG(IWDG->RLR, 500);

	//Start the watchdog
	WRITE_REG(IWDG->KR, 0xCCCCUL);
}

//**************************************************************************************************************************************************************
