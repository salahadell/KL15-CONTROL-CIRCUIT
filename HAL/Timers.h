/*
 * Timers.h
 *
 * Created: 8/26/2023 3:31:58 PM
 *  Author: Mohamed Abdelsamie
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

/**************************************************************************
*							FILE INCLUDES
**************************************************************************/
#include "Timer1.h"
#include "std_types.h"
#ifndef F_CPU
#define F_CPU	16000000UL
#endif

/**************************************************************************
*							DEFINES
**************************************************************************/
#define PRESCALER_VALUE				F_CPU256
#define TIMER_MODE					CTC_MODE
#define COMPARE_VALUE				62500

/*
 * Function name: Start_timer
 *
 *	Input params: Timer value needed
 *  output params: NONE
 */ 
void Start_timer(uint8 timer_val);

/*
 * Function name: Stop_timer
 *
 *	Input params: NONE
 *  output params: NONE
 */ 
void Stop_timer(void);

void Timer1_ISR(void);

#endif /* TIMERS_H_ */
