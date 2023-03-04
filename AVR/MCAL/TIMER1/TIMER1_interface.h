/*
 * TIMER1_int.h
 *
 *  Created on: Feb 14, 2023
 *      Author: DELL
 */

#ifndef TIMER1_TIMER1_INT_H_
#define TIMER1_TIMER1_INT_H_

// Public Macros
#define TIMER1_ICU_FALLING_TRIGG	0
#define TIMER1_ICU_RISING_TRIGG		1

void M_TIMER1_void_init				(void);	//	mode = normal, prescaler
void M_TIMER1_void_start			(void); //  start
void M_TIMER1_void_stop				(void); //  stop
void M_TIMER1_ICU_void_init			(void); //	setup initial trigger for ICU
void M_TIMER1_ICU_void_IntEnable	(void);
void M_TIMER1_ICU_void_IntDisable	(void);
void M_TIMER1_ICU_void_setTrigg		(u8 	Copy_u8TriggID);
void M_TIMER1_ICU_void_setCallBack	(void (* ptrfun)(void));
u16  M_TIMER1_ICU_u16_takeReading	(void);

#endif /* TIMER1_TIMER1_INT_H_ */
