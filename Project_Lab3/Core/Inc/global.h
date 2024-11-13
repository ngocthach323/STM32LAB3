/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: ACER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led7_segment.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_setting.h"

//define các trạng thái toàn hệ thống
#define AUTO 			1
#define RED_LED 		2
#define YELLOW_LED 		3
#define GREEN_LED 		4

//define trạng thái đèn giao thông mỗi chiều (AUTO)
#define	INIT_VER		5
#define RED_VER			6
#define YELLOW_VER		7
#define GREEN_VER		8

#define	INIT_HOR		9
#define RED_HOR			10
#define YELLOW_HOR		11
#define GREEN_HOR		12

//define trạng thái modify time duration từng led màu
#define RED_MODIFY		13
#define YELLOW_MODIFY	14
#define GREEN_MODIFY	15

//đỏ
extern int time_red_ver;			//time đèn đỏ (auto) của đèn giao thông chiều dọc
extern int time_red_hor;			//time đèn đỏ (auto) của đèn giao thông chiều ngang
extern int time_red_ver_temp;		//biến để countdown đèn đỏ của đèn giao thông chiều dọc
extern int time_red_hor_temp;		//biến để countdown time đèn đỏ của đèn giao thông chiều ngang
//vàng
extern int time_yellow_ver;
extern int time_yellow_hor;
extern int time_yellow_ver_temp;
extern int time_yellow_hor_temp;
//xanh
extern int time_green_ver;
extern int time_green_hor;
extern int time_green_ver_temp;
extern int time_green_hor_temp;

#endif /* INC_GLOBAL_H_ */
