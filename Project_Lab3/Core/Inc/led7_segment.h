/*
 * led7_segment.h
 *
 *  Created on: Oct 30, 2024
 *      Author: ACER
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "global.h"

//biến dùng để active chân EN trong led7_segment
extern int idx_vertical;
extern int idx_horizontal;
//biến giá trị đầu vào của 7SEG;
extern int led_buffer_ver[2];
extern int led_buffer_hor[2];

//hiển thị led7
void display7SEG_ver(int num);
void display7SEG_hor(int num);
void update_7SEG_ver(int idx_vertical);
void update_7SEG_hor(int idx_horizontal);

#endif /* INC_LED7_SEGMENT_H_ */
