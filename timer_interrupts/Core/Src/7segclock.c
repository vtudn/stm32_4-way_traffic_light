/*
 * 7segclock.c
 *
 *  Created on: Oct 9, 2021
 *      Author: vtudn
 */

#include "main.h"
#include "7segclock.h"

#define NUMBER_OF_CLOCKS 4

uint8_t Buffer_7seg[NUMBER_OF_CLOCKS];
uint8_t Conv_7seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void Buffer_Update_7seg(uint8_t idx, uint8_t val){
	// update value
	if (idx < NUMBER_OF_CLOCKS && val < 10)
		Buffer_7seg[idx] = val;
}

void Driver_7seg(uint8_t idx){
	uint8_t temp = Conv_7seg[Buffer_7seg[idx]];

	// choose clock
	switch (idx){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;

	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;

	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;

	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		break;

	case 4: // halting case: all clocks OFF
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;

	default:
		break;
	}

	if (temp & 0x01){
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);
	} else {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);
	}

	if (temp & 0x02){
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);
	} else {
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);
	}

	if (temp & 0x04){
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);
	} else {
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 1);
	}

	if (temp & 0x08){
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);
	} else {
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);
	}

	if (temp & 0x10){
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);
	} else {
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);
	}

	if (temp & 0x20){
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);
	} else {
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);
	}

	if (temp & 0x40){
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);
	} else {
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);
	}
}

