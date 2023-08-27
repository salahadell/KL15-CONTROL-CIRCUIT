/*
 * main.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Shawky
 */

#include "pwm.h"
#include <avr/io.h>

void PwmInit(void)
{

	TCCR0 = 0xFB;
	TCNT0 = 0;
	DIO_SetPinVal(DIO_PORTB,DIO_PIN3,LOGIC_LOW);

}

void PwmSetDutyCycle(uint8 dutycycle)
{

	OCR0 = dutycycle;
}

void Diming(void)
{
	uint8 i;
	DIO_SetPinDir(DIO_PORTB,DIO_PIN3 , DIO_PIN_OUTPUT);
	for(i=0;i<254;i++)
	{
		PwmSetDutyCycle(i);
		_delay_ms(10);
	}
	_delay_ms(10);
	for(i=255;i>0;i--)
	{
		PwmSetDutyCycle(i);
		_delay_ms(10);
	}
	DIO_SetPinDir(DIO_PORTB,DIO_PIN3 , DIO_PIN_INPUT);

}

void PwmDenit(void)
{
	TCCR0 = 0;
	TCNT0 = 0;
}


