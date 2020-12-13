/*
 * DC_Motor.c
 *
 * Created: 10-Dec-20 4:08:41 PM
 *  Author: Jean
 */ 
#include "DC_Motor.h"

void DC_Init(){
	OCR1A = 200;
	TCCR1A = (1<<WGM10)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<CS01);
}

void DC_On(unsigned char direction){
	switch(direction){
		case 1:
		DIO_Write(DIO_ChannelC5,STD_High);
		DIO_Write(DIO_ChannelC6,STD_Low);
		break;
		case 2:
		DIO_Write(DIO_ChannelC5,STD_Low);
		DIO_Write(DIO_ChannelC6,STD_High);
		break;
	}
}

void DC_Off(){
	DIO_Write(DIO_ChannelC5,STD_Low);
	DIO_Write(DIO_ChannelC6,STD_Low);
}