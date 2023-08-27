/*
 * Timers.c
 *
 * Created: 8/26/2023 3:32:45 PM
 *  Author: Mohamed Abdelsamie
 */ 

#include "Timers.h"
uint8 g_timer_counter;	/*	timer counter incremented when interrupt is triggered	*/
uint8 g_timer_value;	/*	amount of times the counter is incremented; set by user	*/
extern int flag ;
/*
 * Function name: Start_timer
 *
 *	Input params: Timer value needed
 *  output params: NONE
 */ 
void Start_timer(uint8 timer_val)
{
	Timer1_ConfigType* timer_configurations = 0;
	/*	configure timer parameters using pre-defined values	*/
	timer_configurations->compare_value = COMPARE_VALUE;
	timer_configurations->mode = TIMER_MODE;
	timer_configurations->prescaler = PRESCALER_VALUE;
	
	Timer1_init(timer_configurations);	/*	initialise timer and start counting a 1 sec delay	*/
	
	g_timer_value = timer_val;		/* set the value to increment timer (number of secs)	*/
	Timer1_setCallBack(Timer1_ISR);	/*	Set timer1 interrupt callback	*/
}

/*
 * Function name: Stop_timer
 *
 *	Input params: NONE
 *  output params: NONE
 */ 
void Stop_timer(void)
{
	Timer1_deInit();	/*	stop timer1 by removing clock source	*/
}

/*
 * Interrupt Service Routine callback for timer1 interrupt
 *
 */ 
void Timer1_ISR(void)
{
	if(g_timer_counter < g_timer_value)
	{
		++g_timer_counter;
	}
	if(g_timer_counter == g_timer_value)
	{
		g_timer_counter = 0;	/*	reset timer counter	*/
		Stop_timer();
		flag = 1 ;
	}
}
