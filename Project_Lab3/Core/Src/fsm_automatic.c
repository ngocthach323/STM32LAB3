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

void fsm_traffic_ver() {
	switch (status_traffic_ver) {
		case INIT_VER:
			setTimer(0, 1000); //count down
			status_traffic_ver = RED_VER;
			break;
		case RED_VER:
			red_led_ver();
			led_buffer_ver[0] = time_red_ver_temp / 10;
			led_buffer_ver[1] = time_red_ver_temp % 10;

			if (timer_flag[0] == 1) {
				time_red_ver_temp--;
				if (time_red_ver_temp == 0) {
					time_red_ver_temp = time_red_ver;
					status_traffic_ver = GREEN_VER;
				}
				setTimer(0, 1000);
			}
			break;
		case GREEN_VER:
			green_led_ver();
			led_buffer_ver[0] = time_green_ver_temp / 10;
			led_buffer_ver[1] = time_green_ver_temp % 10;

			if (timer_flag[0] == 1) {
				time_green_ver_temp--;
				if (time_green_ver_temp == 0) {
					time_green_ver_temp = time_green_ver;
					status_traffic_ver = YELLOW_VER;
				}
				setTimer(0, 1000);
			}
			break;
		case YELLOW_VER:
			yellow_led_ver();
			led_buffer_ver[0] = time_yellow_ver_temp / 10;
			led_buffer_ver[1] = time_yellow_ver_temp % 10;

			if (timer_flag[0] == 1) {
				time_yellow_ver_temp--;
				if (time_yellow_ver_temp == 0) {
					time_yellow_ver_temp = time_yellow_ver;
					status_traffic_ver = RED_VER;
				}
				setTimer(0, 1000);
			}
			break;
	}
}

void fsm_traffic_hor() {
	switch (status_traffic_hor) {
		case INIT_HOR:
			setTimer(1, 1000); //count down
			status_traffic_hor = GREEN_HOR;
			break;
		case GREEN_HOR:
			green_led_hor();
			led_buffer_hor[0] = time_green_hor_temp / 10;
			led_buffer_hor[1] = time_green_hor_temp % 10;

			if (timer_flag[1] == 1) {
				time_green_hor_temp--;
				if (time_green_hor_temp == 0) {
					time_green_hor_temp = time_green_hor;
					status_traffic_hor = YELLOW_HOR;
				}
				setTimer(1, 1000);
			}
			break;
		case YELLOW_HOR:
			yellow_led_hor();
			led_buffer_hor[0] = time_yellow_hor_temp / 10;
			led_buffer_hor[1] = time_yellow_hor_temp % 10;

			if (timer_flag[1] == 1) {
				time_yellow_hor_temp--;
				if (time_yellow_hor_temp == 0) {
					time_yellow_hor_temp = time_yellow_hor;
					status_traffic_hor = RED_HOR;
				}
				setTimer(1, 1000);
			}
			break;
		case RED_HOR:
			red_led_hor();
			led_buffer_hor[0] = time_red_hor_temp / 10;
			led_buffer_hor[1] = time_red_hor_temp % 10;

			if (timer_flag[1] == 1) {
				time_red_hor_temp--;
				if (time_red_hor_temp == 0) {
					time_red_hor_temp = time_red_hor;
					status_traffic_hor = GREEN_HOR;
				}
				setTimer(1, 1000);
			}
			break;
	}
}

void fsm_automatic() {
	if (status_system == AUTO) {
	    fsm_traffic_ver();
	    fsm_traffic_hor();
	}
	else return;
}
