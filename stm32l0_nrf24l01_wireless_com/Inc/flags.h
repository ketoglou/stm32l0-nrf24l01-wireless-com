/*
 * ****************************************************
 * File:	flags.h
 * Project:	RF communication with STM32 and nRF24L01+
 * MCU:		STM32L011K4
 * Others:	nRF24L01+
 * Author:	Theocharis Ketoglou
 * Date:	12/12/2021
 * ****************************************************
 */

#ifndef FLAGS_H_
#define FLAGS_H_

#include <stdint.h>

//Flag enumeration
typedef struct{
	uint8_t f0 : 1;
	uint8_t f1 : 1;
	uint8_t f2 : 1;
	uint8_t f3 : 1;
	uint8_t f4 : 1;
	uint8_t f5 : 1;
	uint8_t f6 : 1;
	uint8_t f7 : 1;
	uint8_t f8 : 1;
	uint8_t f9 : 1;
	uint8_t f10 : 1;
	uint8_t f11 : 1;
	uint8_t f12 : 1;
	uint8_t f13 : 1;
	uint8_t f14 : 1;
	uint8_t f15 : 1;
} flag;

flag flag0;

/*	--flag0--
 * 	f0: Used in delay_ms function
 * 	f1: Used when an interrupt happen
 * 	f2: Used in nrf RX/TX to start only when no RX/TX is pedding
 * 	f3:
 * 	f4:
 * 	f5:
 * 	f6:
 * 	f7:
 * 	f8:
 * 	f9:
 * 	f10:
 * 	f11:
 * 	f12:
 * 	f13:
 * 	f14:
 * 	f15:
 * 	...
 * 	f31:
 */



#endif /* FLAGS_H_ */
