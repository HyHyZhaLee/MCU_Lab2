/*
 * display.h
 *
 *  Created on: Oct 8, 2023
 *      Author: Admin
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "main.h"
#define ON	0
#define OFF	1
#define MAX_LED	4
#define MAX_LED_MATRIX	8


extern int led_buffer[MAX_LED];
extern uint8_t matrix_buffer[MAX_LED_MATRIX];
void led7Run();
void ledMatrixRun();

#endif /* INC_DISPLAY_H_ */
