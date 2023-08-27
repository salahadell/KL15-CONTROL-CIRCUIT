/*
 * main.c
 *
 *  Created on: Aug 26, 2023
 *      Author: amrfawzy
 */
#include <util/delay.h>
#include "common_macros.h"
#include "std_types.h"
#include "leds.h"
#include "ADC.h"
#include "pwm.h"
#include "timer1.h"
#include "lcd.h"
#include "potentiometer.h"
#include "Timers.h"
#include "EXTI.h"
#include "buzzer.h"

#define OFF_MODE     0
#define READY_MODE   1
#define EGNITE_MODE  2

#define FIVE_SECONDS 5


void clearFlag() ;
void sysInit();

int flag = 0;
int timerison = 0;


void sysInit(){
	SET_GlobalInterrupt();
	Potentimeter_init();
	LCD_Init();
	Set_led_red();
	Buzzer_init();
	PwmInit();
}

int main(){

	uint8 state ;
	sysInit();
	while(1){

		state = ReadPotentiometer();

		switch(state){

		case OFF_MODE :
			letRed_OFF();
			LCD_GOTO_XY(1, 0);
			LCD_WriteString("OFF MODE");
			LCD_WriteString("      ");
			clearFlag();
			Stop_timer();
			letGreen_OFF();
			timerison = 0;
			Buzzer_off();
			break;

		case READY_MODE :

			if(flag==1)
			{
				LCD_GOTO_XY(1, 0);
				LCD_WriteString("TIME OUT");
				LCD_WriteString("      ");
				letRed_OFF();
				Buzzer_on();
				letBlue_OFF();
				Diming();
				//Start Blinking Timer ;
				timerison = 0;
			}

			else if(timerison == 0)
			{
				LCD_GOTO_XY(1, 0);
				LCD_WriteString("READY MODE");
				LCD_WriteString("      ");
				Start_timer(FIVE_SECONDS);
				timerison = 1;
			}
			else{}
			
			break;


		case EGNITE_MODE :
			timerison = 0;
			letRed_ON();
			LCD_GOTO_XY(1, 0);
			LCD_WriteString("IGNITE_MODE");
			LCD_WriteString("      ");
			clearFlag();
			Stop_timer();
			letGreen_OFF();
			Buzzer_off();
			//stop blinking timer
			break;

		default :
			break;
		}
	}

}
void clearFlag(void)
{
	flag = 0;
}

