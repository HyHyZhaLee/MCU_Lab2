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

extern int led_buffer[MAX_LED];

void update7SEGBuffer(int input[MAX_LED]);
void led7Run();

#endif /* INC_DISPLAY_H_ */
