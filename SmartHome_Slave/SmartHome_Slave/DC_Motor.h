/*
 * DC_Motor.h
 *
 * Created: 10-Dec-20 4:08:26 PM
 *  Author: Jean
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include <avr/io.h>
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void DC_Init();
void DC_On(unsigned char direction);
void DC_Off();

#endif /* DC_MOTOR_H_ */