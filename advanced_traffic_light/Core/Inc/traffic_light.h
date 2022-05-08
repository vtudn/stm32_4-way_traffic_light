/*
 * traffic_light.h
 *
 *  Created on: Nov 1, 2021
 *      Author: vtudn
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

void traffic_light_init(void);
void traffic_light_update1(uint32_t red_cnt, uint32_t yel_cnt, uint32_t gre_cnt);
void traffic_light_update2(uint32_t red_cnt, uint32_t yel_cnt, uint32_t gre_cnt);

#endif /* INC_TRAFFIC_LIGHT_H_ */
