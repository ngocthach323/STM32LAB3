/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: ACER
 */
#include "fsm_automatic.h"

//biến trạng thái đèn giao thông chiều dọc và ngang
int status_traffic_ver = INIT_VER;
int status_traffic_hor = INIT_HOR;
//mảng lưu trữ thời gian từng đèn mỗi chiều
int traffic_buffer_ver[3] = {0, 0, 0};
int traffic_buffer_hor[3] = {0, 0, 0};

void fsm_traffic_ver() {
	switch (status_traffic_ver) {
		case INIT_VER:
			traffic_buffer_ver[0] = time_red_ver * 1000; //lưu time đèn đỏ sáng
			setTimer(0, traffic_buffer_ver[0]);
			setTimer(5, 1000); //count down
			status_traffic_ver = RED_VER;
			break;
		case RED_VER:
			red_led_ver();
			led_buffer_ver[0] = time_red_ver_temp / 10;
			led_buffer_ver[1] = time_red_ver_temp % 10;

			if (timer_flag[5] == 1) {
				time_red_ver_temp--;
				if (time_red_ver_temp == 0) {
					time_red_ver_temp = time_red_ver;
				}
				setTimer(5, 1000);
			}

			if (timer_flag[0] == 1) {
				traffic_buffer_ver[1] = time_green_ver * 1000; //lưu time cho đèn vàng sáng
				setTimer(0, traffic_buffer_ver[1]);
				setTimer(5, 1000);
				status_traffic_ver = GREEN_VER;
			}
			break;
		case GREEN_VER:
			green_led_ver();
			led_buffer_ver[0] = time_green_ver_temp / 10;
			led_buffer_ver[1] = time_green_ver_temp % 10;

			if (timer_flag[5] == 1) {
				time_green_ver_temp--;
				if (time_green_ver_temp == 0) {
					time_green_ver_temp = time_green_ver;
				}
				setTimer(5, 1000);
			}

			if (timer_flag[0] == 1) {
				traffic_buffer_ver[2] = time_yellow_ver * 1000; //lưu time cho đèn đỏ sáng
				setTimer(0, traffic_buffer_ver[2]);
				setTimer(5, 1000);
				status_traffic_ver = YELLOW_VER;
			}
			break;
		case YELLOW_VER:
			yellow_led_ver();
			led_buffer_ver[0] = time_yellow_ver_temp / 10;
			led_buffer_ver[1] = time_yellow_ver_temp % 10;

			if (timer_flag[5] == 1) {
				time_yellow_ver_temp--;
				if (time_yellow_ver_temp == 0) {
					time_yellow_ver_temp = time_yellow_ver;
				}
				setTimer(5, 1000);
			}

			if (timer_flag[0] == 1) {
				traffic_buffer_ver[0] = time_red_ver * 1000; //lưu time cho đèn xanh sáng
				setTimer(0, traffic_buffer_ver[0]);
				setTimer(5, 1000);
				status_traffic_ver = RED_VER;
			}
			break;
	}
}

void fsm_traffic_hor() {
	switch (status_traffic_hor) {
		case INIT_HOR:
			traffic_buffer_hor[0] = time_green_hor * 1000;
			setTimer(1, traffic_buffer_hor[0]);
			setTimer(6, 1000); //count down
			status_traffic_hor = GREEN_HOR;
			break;
		case GREEN_HOR:
			green_led_hor();
			led_buffer_hor[0] = time_green_hor_temp / 10;
			led_buffer_hor[1] = time_green_hor_temp % 10;

			if (timer_flag[6] == 1) {
				time_green_hor_temp--;
				if (time_green_hor_temp == 0) {
					time_green_hor_temp = time_green_hor;
				}
				setTimer(6, 1000);
			}
			if (timer_flag[1] == 1) {
				traffic_buffer_hor[1] = time_yellow_hor * 1000;
				setTimer(1, traffic_buffer_hor[1]);
				setTimer(6, 1000);
				status_traffic_hor = YELLOW_HOR;
			}
			break;
		case YELLOW_HOR:
			yellow_led_hor();
			led_buffer_hor[0] = time_yellow_hor_temp / 10;
			led_buffer_hor[1] = time_yellow_hor_temp % 10;

			if (timer_flag[6] == 1) {
				time_yellow_hor_temp--;
				if (time_yellow_hor_temp == 0) {
					time_yellow_hor_temp = time_yellow_hor;
				}
				setTimer(6, 1000);
			}
			if (timer_flag[1] == 1) {
				traffic_buffer_hor[2] = time_red_hor * 1000;
				setTimer(1, traffic_buffer_hor[2]);
				setTimer(6, 1000);
				status_traffic_hor = RED_HOR;
			}
			break;
		case RED_HOR:
			red_led_hor();
			led_buffer_hor[0] = time_red_hor_temp / 10;
			led_buffer_hor[1] = time_red_hor_temp % 10;

			if (timer_flag[6] == 1) {
				time_red_hor_temp--;
				if (time_red_hor_temp == 0) {
					time_red_hor_temp = time_red_hor;
				}
				setTimer(6, 1000);
			}
			if (timer_flag[1] == 1) {
				traffic_buffer_hor[0] = time_green_hor * 1000;
				setTimer(1, traffic_buffer_hor[0]);
				setTimer(6, 1000);
				status_traffic_hor = GREEN_HOR;
			}
			break;
	}
}

void fsm_automatic() {
	fsm_traffic_ver();
	fsm_traffic_hor();
}
