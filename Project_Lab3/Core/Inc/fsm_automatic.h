/*
 * fsm_automatic.h
 *
 *  Created on: Oct 30, 2024
 *      Author: ACER
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"

//biến trạng thái đèn giao thông chiều dọc và ngang
extern int status_traffic_ver;
extern int status_traffic_hor;

void fsm_traffic_ver();
void fsm_traffic_hor();
void fsm_automatic();

#endif /* INC_FSM_AUTOMATIC_H_ */
