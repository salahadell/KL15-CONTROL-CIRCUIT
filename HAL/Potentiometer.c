/*
 * Potentiometer.c
 *
 * Created: 8/26/2023 3:20:39 PM
 *  Author: Lenovo
 */ 

#include "Potentiometer.h"
#include "lcd.h"

#define	NULL    ((void*)0)

void Potentimeter_init(){
	
	//-----------------------------
	//1) Initialize ADC
	//-----------------------------
	ADC_Config_t ADC_Config;
	ADC_Config.ADC_MODE = ADC_MODE_SINGLE_CONVERSION;
	ADC_Config.ADC_PRESCALER = ADC_PRESCALER_128;
	ADC_Config.ADC_Result_Presentation = ADC_Result_Presentation_RIGHT;
	ADC_Config.ADC_VREF = ADC_VREF_AVCC;
	ADC_Config.IRQ_Enable = ADC_IRQ_DISABLE;
	ADC_Config.P_CallBack = NULL;
	ADC_init(&ADC_Config);
	
	//-----------------------------
	//2) Initialize Potentiometer
	//-----------------------------
	DIO_SetPinDir(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
}

state ReadPotentiometer(){
	
	uint16 ADC_Data;
	state mystate;
	
	ADC_ReadData(ADC1, &ADC_Data, Polling_ENABLE);
	LCD_GOTO_XY(2, 0);
	if(ADC_Data > 100)
	{
		LCD_intgerToString(ADC_Data);
	}
	else
	{
		LCD_intgerToString(ADC_Data);
		LCD_Writechar(' ');
	}
	if((ADC_Data > 0) && (ADC_Data <= 50)){
		mystate=off;
	}
	else if((ADC_Data > 50) && (ADC_Data <= 100)){
		 mystate=ready;
	}
	else{
		mystate=ignition;
	}	
	return mystate;
}
