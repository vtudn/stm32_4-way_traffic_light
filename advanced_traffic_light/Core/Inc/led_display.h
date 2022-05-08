/*
 * led_display.h
 *
 *  Created on: Oct 24, 2021
 *      Author: vtudn
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

void UpdateBuffer_7SEG_LEDS(uint8_t idx, uint8_t val);
void ClearPrevious_7SEG_LEDS(uint8_t index);
void Display_7SEG_DATA(uint8_t val);
void SetCurrent_7SEG_LEDS(uint8_t index);
void Driver_7SEG_LEDS(void);

#endif /* INC_LED_DISPLAY_H_ */
