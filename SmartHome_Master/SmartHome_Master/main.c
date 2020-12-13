/*
* SmartHome_Master.c
*
* Created: 08-Dec-20 5:50:48 PM
* Author : Jean
*/

#include "DIO.h"
#include "LCD.h"
#include "UART.h"
#include "SPI.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>

void Temp_Dis();

int main(void)
{
	DIO_Init();
	LCD_Init();
	Uart_Init();
	SPI_Init(Master);
	UartSendString("UART ON");
	SlaveEN();
	unsigned char Command;
	LCD_StringPos("Welcome John",1,0);
	LCD_StringPos("Temperature:",2,0);
	while (1)
	{
		Temp_Dis();
		Command = UartReceive();
		if (Command == '1')
		{
			UartSendString("Sent 1");
			SPITxRx(1) == 11;
			_delay_ms(200);
		}
		if (Command == '2')
		{
			UartSendString("Sent 2");
			SPITxRx(2) == 11;
			_delay_ms(200);
		}
		if (Command == '3')
		{
			UartSendString("Sent 3");
			SPITxRx(3) == 11;
			_delay_ms(200);
		}
		if (Command == '4')
		{
			UartSendString("Sent 4");
			SPITxRx(4) == 11;
			_delay_ms(200);
		}
		if (Command == '5')
		{
			UartSendString("Sent 5");
			SPITxRx(5) == 11;
			_delay_ms(200);
		}
		if (Command == '6')
		{
			UartSendString("Sent 6");
			SPITxRx(6) == 11;
			_delay_ms(200);
		}
		if (Command == '7')
		{
			UartSendString("Sent 7");
			SPITxRx(7) == 11;
			_delay_ms(200);
		}
		if (Command == '8')
		{
			UartSendString("Sent 8");
			SPITxRx(8) == 11;
			_delay_ms(200);
		}
		if (Command == '9')
		{
			UartSendString("Sent 9");
			SPITxRx(9) == 11;
			_delay_ms(200);
		}
		Temp_Dis();
	}
}

void Temp_Dis(){
	unsigned char temp = SPITxRx(10);
	char temperature[5];
	itoa(temp,temperature,10);
	LCD_StringPos(temperature,2,14);
	_delay_ms(500);
}

