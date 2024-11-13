/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: ACER
 */
#include "fsm_manual.h"

int status_system = AUTO;

void fsm_manual() {
	switch(status_system) {
		case AUTO: //đèn hoạt động bình thường
			fsm_automatic();
			//button1
			if (isButtonPressed(0) == 1) {
				status_system = RED_LED;
			}
			break;
		case RED_LED: //thiết lập time cho 4 led red
			status_modify = RED_MODIFY;
			fsm_setting();
			//button3
			if (isButtonPressed(2) == 1) {
				time_red_ver_temp = time_red_ver;
				time_red_hor_temp = time_red_hor;
			}
			//button1
			if (isButtonPressed(0) == 1) {
				status_system = YELLOW_LED;
			}
			break;
		case YELLOW_LED: //thiết lập time cho 4 led yellow
			status_modify = YELLOW_MODIFY;
			fsm_setting();
			//button3
			if (isButtonPressed(2) == 1) {
				time_yellow_ver_temp = time_yellow_ver;
				time_yellow_hor_temp = time_yellow_hor;
				//sau khi check cập nhật lại countdown đèn đỏ
				time_red_ver_temp = time_red_ver;
				time_red_hor_temp = time_red_hor;
			}
			//button1
			if (isButtonPressed(0) == 1) {
				status_system = GREEN_LED;
			}
			break;
		case GREEN_LED: ////thiết lập time cho 4 led green
			status_modify = GREEN_MODIFY;
			fsm_setting();
			//button3
			if (isButtonPressed(2) == 1) {
				time_green_ver_temp = time_green_ver;
				time_green_hor_temp = time_green_hor;
				//sau khi check cập nhật lại countdown đèn đỏ
				time_red_ver_temp = time_red_ver;
				time_red_hor_temp = time_red_hor;
			}
			//button1
			if (isButtonPressed(0) == 1) {
				status_traffic_ver = INIT_VER;
				status_traffic_hor = INIT_HOR;
				status_system = AUTO;
			}
			break;
	}
	//hiển thị led
	if (timer_flag[2] == 1) {
		update_7SEG_ver(idx_vertical);
		idx_vertical++;
		if(idx_vertical == 2) {
			idx_vertical = 0;
		}

		update_7SEG_hor(idx_horizontal);
		idx_horizontal++;
		if (idx_horizontal == 2) {
			idx_horizontal = 0;
		}
		setTimer(2, 500);
	}
}
