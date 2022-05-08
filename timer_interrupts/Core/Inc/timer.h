/*
 * timer.h
 *
 *  Created on: Oct 30, 2021
 *      Author: vtudn
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIMER_CYCLE 10
#define NUMBER_OF_TIMER 2

uint32_t	timer_counter	[NUMBER_OF_TIMER];
uint8_t		timer_flag		[NUMBER_OF_TIMER];

void timer_set(uint8_t idx, uint32_t duration);
void timer_run();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_TIMER_H_ */
