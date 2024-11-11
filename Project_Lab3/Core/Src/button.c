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
int TimeOutForKeyPress =  200;
int button_flag[10];

int isButtonPressed(int index) {
    if (button_flag[index] == 1) {
        button_flag[index] = 0;
        return 1;
    }
    return 0;
}

void getKeyInput() {
    for (int i = 0; i < 10; i++) {
        keyReg2[i] = keyReg1[i];
        keyReg1[i] = keyReg0[i];
        if (i == 0) {
        	//đọc chân button1
        	keyReg0[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
        }
        else if (i == 1) {
        	//đọc chân button2
        	keyReg0[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
        }
        else if (i == 2) {
        	//đọc chân button3
        	keyReg0[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
        }

        if ((keyReg2[i] == keyReg1[i]) && (keyReg1[i] == keyReg0[i])) {
        	if (keyReg0[i] != keyReg3[i]) {
                keyReg3[i] = keyReg0[i];

                if (keyReg0[i] == PRESSED_STATE) {
                	TimeOutForKeyPress = 200;
                    button_flag[i] = 1;
                }
            }
        	else {
        		TimeOutForKeyPress--;
        		if (TimeOutForKeyPress == 0) {
        			keyReg0[i] = NORMAL_STATE;
        		}
        	}

        }
    }
}
