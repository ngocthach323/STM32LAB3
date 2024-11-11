/*
 * traffic_light.h
 *
 *  Created on: Oct 30, 2024
 *      Author: ACER
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"

//đèn giao thông cho chiều dọc
void red_led_ver();
void yellow_led_ver();
void green_led_ver();
//đèn giao thông cho chiều ngang
void red_led_hor();
void yellow_led_hor();
void green_led_hor();
//nhấp nháy đèn cần modify
void toggle_red_led();
void toggle_yellow_led();
void toggle_green_led();
//tắt các đèn không cần modify
void turn_off_yellow_green();
void turn_off_red_green();
void turn_off_red_yellow();

#endif /* INC_TRAFFIC_LIGHT_H_ */
