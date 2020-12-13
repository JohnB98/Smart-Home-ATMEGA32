/*
 * SmartHome_Slave.c
 *
 * Created: 09-Dec-20 8:29:45 PM
 * Author : Jean
 */ 

#include "DIO.h"
#include "LCD.h"
#include "SPI.h"
#include "ADC.h"
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DC_Motor.h"

void Temp_Send();

int main(void)
{
	unsigned char Cmd = 0;
    DIO_Init();
	LCD_Init();
	SPI_Init(Slave);
	ADC_Init();
	DC_Init();
    while (1) 
    {
		Temp_Send();
		Cmd = SPITxRx(11);
		switch(Cmd){
			case 1:
			LCD_String("Living Room");
			LCD_StringPos("Lights ON",2,0);
			DIO_Write(DIO_ChannelC1,STD_High);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 2:
			LCD_String("Living Room");
			LCD_StringPos("Lights OFF",2,4);
			DIO_Write(DIO_ChannelC1,STD_Low);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 3:
			LCD_String("Bedroom Lights");
			LCD_StringPos("ON",2,7);
			DIO_Write(DIO_ChannelC2,STD_High);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 4:
			LCD_String("Bedroom Lights");
			LCD_StringPos("OFF",2,7);
			DIO_Write(DIO_ChannelC2,STD_Low);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 5:
			LCD_String("Kitchen Lights");
			LCD_StringPos("ON",2,7);
			DIO_Write(DIO_ChannelC3,STD_High);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 6:
			LCD_String("Kitchen Lights");
			LCD_StringPos("OFF",2,7);
			DIO_Write(DIO_ChannelC3,STD_Low);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 7:
			LCD_String("Motor ON");
			LCD_StringPos("Clockwise",2,0);
			DC_On(1);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 8:
			LCD_String("Motor ON");
			LCD_StringPos("Anti-Clockwise",2,0);
			DC_On(2);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 9:
			LCD_String("Motor OFF");
			DC_Off();
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
		}
    }
}

void Temp_Send(){
	unsigned short temp = Temp_Read(1);
	temp /= 4;
	SPITxRx(temp) == 10;
}
