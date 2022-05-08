/*
 * input_processing.h
 *
 *  Created on: Oct 24, 2021
 *      Author: vtudn
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

uint8_t red_updating();
uint8_t yel_updating();
uint8_t gre_updating();
uint8_t mode1_sw_updating();

void fsm_for_input_processing_1(void);
void fsm_for_input_processing_2(void);
void fsm_for_input_processing_3(void);
void fsm_for_input_processing_4(void);

#endif /* INC_INPUT_PROCESSING_H_ */
