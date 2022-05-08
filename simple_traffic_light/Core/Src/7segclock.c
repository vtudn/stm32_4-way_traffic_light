/*
 * 7segclock.c
 *
 *  Created on: Sep 26, 2021
 *      Author: vtudn
 */

#include "main.h"
#include "7segclock.h"

#define NUMBER_OF_CLOCKS 2

uint8_t Buffer_7seg[NUMBER_OF_CLOCKS];
uint8_t Conv_7seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void Buffer_Update_7seg(uint8_t val, uint8_t idx){
	Buffer_7seg[idx] = val;
}

void Driver_7seg(uint8_t idx){
	uint8_t temp = Conv_7seg[Buffer_7seg[idx]];

	// clock 1
	if (idx == 0) {
		if (temp & 0x01){
			HAL_GPIO_WritePin(A_7SEG_GPIO_Port, A_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(A_7SEG_GPIO_Port, A_7SEG_Pin, SET);
		}

		if (temp & 0x02){
			HAL_GPIO_WritePin(B_7SEG_GPIO_Port, B_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(B_7SEG_GPIO_Port, B_7SEG_Pin, SET);
		}

		if (temp & 0x04){
			HAL_GPIO_WritePin(C_7SEG_GPIO_Port, C_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(C_7SEG_GPIO_Port, C_7SEG_Pin, SET);
		}

		if (temp & 0x08){
			HAL_GPIO_WritePin(D_7SEG_GPIO_Port, D_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(D_7SEG_GPIO_Port, D_7SEG_Pin, SET);
		}

		if (temp & 0x10){
			HAL_GPIO_WritePin(E_7SEG_GPIO_Port, E_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(E_7SEG_GPIO_Port, E_7SEG_Pin, SET);
		}

		if (temp & 0x20){
			HAL_GPIO_WritePin(F_7SEG_GPIO_Port, F_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(F_7SEG_GPIO_Port, F_7SEG_Pin, SET);
		}

		if (temp & 0x40){
			HAL_GPIO_WritePin(G_7SEG_GPIO_Port, G_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(G_7SEG_GPIO_Port, G_7SEG_Pin, SET);
		}
	}

	// clock 2
	if (idx == 1){
		if (temp & 0x01){
			HAL_GPIO_WritePin(A2_7SEG_GPIO_Port, A2_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(A2_7SEG_GPIO_Port, A2_7SEG_Pin, SET);
		}

		if (temp & 0x02){
			HAL_GPIO_WritePin(B2_7SEG_GPIO_Port, B2_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(B2_7SEG_GPIO_Port, B2_7SEG_Pin, SET);
		}

		if (temp & 0x04){
			HAL_GPIO_WritePin(C2_7SEG_GPIO_Port, C2_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(C2_7SEG_GPIO_Port, C2_7SEG_Pin, SET);
		}

		if (temp & 0x08){
			HAL_GPIO_WritePin(D2_7SEG_GPIO_Port, D2_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(D2_7SEG_GPIO_Port, D2_7SEG_Pin, SET);
		}

		if (temp & 0x10){
			HAL_GPIO_WritePin(E2_7SEG_GPIO_Port, E2_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(E2_7SEG_GPIO_Port, E2_7SEG_Pin, SET);
		}

		if (temp & 0x20){
			HAL_GPIO_WritePin(F2_7SEG_GPIO_Port, F2_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(F2_7SEG_GPIO_Port, F2_7SEG_Pin, SET);
		}

		if (temp & 0x40){
			HAL_GPIO_WritePin(G2_7SEG_GPIO_Port, G2_7SEG_Pin, RESET);
		} else {
			HAL_GPIO_WritePin(G2_7SEG_GPIO_Port, G2_7SEG_Pin, SET);
		}
	}
}
