/*
 * display.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Admin
 */
#include "display.h"

uint8_t segmentNumberCathode[10]={
	0x3f,
	0x06,
	0x5b,
	0x4f,
	0x66,
	0x6d,
	0x7d,
	0x07,
	0x7f,
	0x4f
};

uint8_t segmentNumberAnode[10]={
	0xc0,
	0xf9,
	0xa4,
	0xb0,
	0x99,
	0x92,
	0x82,
	0xf8,
	0x80,
	0x90
};

void display7SEG(int number){
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (segmentNumberAnode[number]>>0)&0x01);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (segmentNumberAnode[number]>>1)&0x01);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (segmentNumberAnode[number]>>2)&0x01);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (segmentNumberAnode[number]>>3)&0x01);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (segmentNumberAnode[number]>>4)&0x01);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (segmentNumberAnode[number]>>5)&0x01);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (segmentNumberAnode[number]>>6)&0x01);
}
int index_led = 0;
int led_buffer[MAX_LED] = {1,2};
void update7SEG(int index){
	switch(index){
	case 0:
		// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, ON);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, OFF);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, OFF);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, OFF);
		display7SEG(led_buffer[0]);
		break;
	case 1:
		// Display the second 7 SEG with led_buffer [1]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, OFF);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, ON);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, OFF);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, OFF);
		display7SEG(led_buffer[1]);
		break;
	case 2:
		// Display the second 7 SEG with led_buffer [2]
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, OFF);
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, OFF);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, ON);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, OFF);
//		display7SEG(led_buffer[2]);
		break;
	case 3:
		// Display the second 7 SEG with led_buffer [3]
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, OFF);
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, OFF);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, OFF);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, ON);
//		display7SEG(led_buffer[3]);
		break;
	default: break;
	}
}
void update7SEGBuffer(int input[MAX_LED]){
	*led_buffer = *input;
	index_led = 0;
	update7SEG(index_led);
}
void led7Run(){
	update7SEG(index_led++);
	if(index_led >= MAX_LED) index_led = 0;
}



