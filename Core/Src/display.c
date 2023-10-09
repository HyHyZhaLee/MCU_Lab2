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
int led_buffer[MAX_LED] = {1,2,3,4};
void update7SEG(int index){
	switch(index){
	case 0:
		// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, ON);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, OFF);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, OFF);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, OFF);
		display7SEG(led_buffer[0]);
		break;
	case 1:
		// Display the second 7 SEG with led_buffer [1]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, OFF);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, ON);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, OFF);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, OFF);
		display7SEG(led_buffer[1]);
		break;
	case 2:
		// Display the second 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, OFF);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, OFF);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, ON);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, OFF);
		display7SEG(led_buffer[2]);
		break;
	case 3:
		// Display the second 7 SEG with led_buffer [3]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, OFF);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, OFF);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, OFF);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, ON);
		display7SEG(led_buffer[3]);
		break;
	default: break;
	}
}


int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x18,0x24,0x24,0x42,0x7e,0x42,0x42,0x42};

void displayLEDMATRIX (int index){
	int state[8];
	for(int i = 0; i<MAX_LED_MATRIX; i++){
	   if (matrix_buffer[index]>>i & 1) state[i] = 0;
	   else state[i] = 1;
	}
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, state[0]);//0
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, state[1]);//1
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, state[2]);//2
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, state[3]);//3
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, state[4]);//4
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, state[5]);//5
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, state[6]);//6
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, state[7]);//7
}

void updateLEDMatrix (int index ){
	switch (index){
		case 0:
				HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 0);//0
				HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);//1
				HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);//2
				HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);//3
				HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);//4
				HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);//5
				HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);//6
				HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);//7
				displayLEDMATRIX(index);
				break;
		case 1:
				HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);//0
				HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 0);//1
				HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);//2
				HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);//3
				HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);//4
				HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);//5
				HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);//6
				HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);//7
				displayLEDMATRIX(index);
				break;
		case 2:
				HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);//0
				HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);//1
				HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 0);//2
				HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);//3
				HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);//4
				HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);//5
				HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);//6
				HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);//7
				displayLEDMATRIX(index);
				break;
		case 3:
				HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);//0
				HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);//1
				HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);//2
				HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 0);//3
				HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);//4
				HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);//5
				HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);//6
				HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);//7
				displayLEDMATRIX(index);
				break;
		case 4:
				HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);//0
				HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);//1
				HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);//2
				HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);//3
				HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 0);//4
				HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);//5
				HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);//6
				HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);//7
				displayLEDMATRIX(index);
				break;
		case 5:
				HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);//0
				HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);//1
				HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);//2
				HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);//3
				HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);//4
				HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 0);//5
				HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);//6
				HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);//7
				displayLEDMATRIX(index);
				break;
		case 6:
				HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);//0
				HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);//1
				HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);//2
				HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);//3
				HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);//4
				HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);//5
				HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 0);//6
				HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);//7
				displayLEDMATRIX(index);
				break;
		case 7:
				HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);//0
				HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);//1
				HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);//2
				HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);//3
				HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);//4
				HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);//5
				HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);//6
				HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 0);//7
				displayLEDMATRIX(index);
				break;
	}
}

void led7Run(){
	update7SEG(index_led++);
	if(index_led >= MAX_LED) index_led = 0;
}

void ledMatrixRun(){
	updateLEDMatrix(index_led_matrix++);
	if(index_led_matrix >= MAX_LED_MATRIX) index_led_matrix = 0;
}


