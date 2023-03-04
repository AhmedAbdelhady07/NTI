/*
 * EXTI_int.h
 *
 *  Created on: Feb 7, 2023
 *      Author: DELL
 */

#ifndef EXTI_EXTI_INT_H_
#define EXTI_EXTI_INT_H_

typedef enum
{
	EXTT_INT0 = 6,
	EXTT_INT1,
	EXTT_INT2 = 5
}EXTI_t;
typedef enum
{
	EXTT_TRIG_LOW_LEVEL,
	EXTT_TRIG_ANY_CHANGE,
	EXTT_TRIG_FALLING_EDGE,
	EXTT_TRIG_RAISING_EDGE
}Sense_t;
/****************      Public Macros     ****************/


/***************   Function Prototypes   ****************/
void M_EXTI_void_enable				(EXTI_t Copy_u8IntID , Sense_t Copy_u8Sence);
void M_EXTI_void_disable			(EXTI_t Copy_u8IntID);
void M_EXTI_void_setCallBack		(void (*ptrfn)(void), EXTI_t Copy_u8IntID);

#endif /* EXTI_EXTI_INT_H_ */
