/*
 * button.c
 *
 *  Created on: Oct 30, 2024
 *      Author: ACER
 */
#include "button.h"

int keyReg0[10] = {NORMAL_STATE};
int keyReg1[10] = {NORMAL_STATE};
int keyReg2[10] = {NORMAL_STATE};
int keyReg3[10] = {NORMAL_STATE};
int TimeOutForKeyPress =  500;
int button_flag[10]; //nhan nhanh
int button_long_pressed_flag[10]; //nhan lau

int isButtonPressed(int index) {
    if (button_flag[index] == 1) {
        button_flag[index] = 0;
        return 1;
    }
    return 0;
}

int isButtonLongPressed(int index) {
    if (button_long_pressed_flag[index] == 1) {
        button_long_pressed_flag[index] = 0;
        return 1;
    }
    return 0;
}

void getKeyInput() {
    for (int i = 0; i < 10; i++) {
        keyReg2[i] = keyReg1[i];
        keyReg1[i] = keyReg0[i];
        keyReg0[i] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13 + i);

        if ((keyReg1[i] == keyReg0[i]) && (keyReg1[i] == keyReg2[i])) {
            if (keyReg2[i] != keyReg3[i]) {
                keyReg3[i] = keyReg2[i];

                if (keyReg3[i] == PRESSED_STATE) {
                    button_flag[i] = 1;
                }
            } else {
            	TimeOutForKeyPress--;
            	if(TimeOutForKeyPress == 0) {
            		TimeOutForKeyPress = 500;
            		if (keyReg3[i] == PRESSED_STATE) {
            			button_flag[i] = 1;
            		}
                }
            }
        }
    }
}
