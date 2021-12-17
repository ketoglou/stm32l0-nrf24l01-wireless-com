/*
 * ****************************************************
 * File:	main.c
 * Project:	RF communication with STM32 and nRF24L01+
 * MCU:		STM32L011K4
 * Others:	nRF24L01+
 * Author:	Theocharis Ketoglou
 * Date:	12/12/2021
 * ****************************************************
 */

//Includes
#include "CMSIS/stm32l0xx.h"
#include "flags.h"
#include "init_system.h"
#include "gpio.h"
#include "nvic.h"
#include "spi.h"
#include "timers.h"
#include "nrf.h"

//Defines
#define MESSAGE_LENGTH	5

//Variables
uint8_t msg[MESSAGE_LENGTH] = { 'H', 'e', 'l', 'l', 'o' };	//Message
uint8_t response;											//Response from nrf handler

//Functions
uint8_t str_cmp(uint8_t *buf1, uint8_t *buf2, uint8_t size);	//Compare two strings


//**************************************************************************************************************************************************************
int main(void){

	init_emb_flash_mem();	//Initialize latency WS
	init_rcc();				//Initialize clock (RCC)
	init_gpio();			//Initialize GPIOs
	init_spi();				//Initialize SPI
	init_timer2();			//Initialize Timer 2 to sample button
	init_external_irq();	//Initialize interrupts from external source
	init_iwdg();			//Initialize WatchDog (Comment in DEBUG mode)

	delay_ms(200);			//Wait for NRF to power on(POwer on reset state)

	nrf_initialize(); 		//Initialize nRF

	while(1){

		//COMMENT TRANSMITTER OR RECEIVER

		//Transmitter
		//---------------------
		//nrf_transmit(msg,MESSAGE_LENGTH);
		//delay_ms(1000);
		//response = nrf_handler();
		//---------------------

		//Receiver
		//---------------------
		nrf_receive(MESSAGE_LENGTH);
		response = nrf_handler();
		if(response & DATA_RECEIVED){
			if(str_cmp(payload_data,msg,MESSAGE_LENGTH))
				LED_CHANGE();
		}
		//---------------------

		//Clear WatchDog (Comment in DEBUG mode)
		CLRWDT();
	}
}

//**************************************************************************************************************************************************************

//Return 1 if strings match, else return 0
uint8_t str_cmp(uint8_t *buf1, uint8_t *buf2, uint8_t size){

	for(uint8_t i=0;i<size;i++){
		if(buf1[i] != buf2[i])
			return 0;
	}

	return 1;
}

//**************************************************************************************************************************************************************
