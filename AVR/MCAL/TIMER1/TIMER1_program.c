/*
 * TIMER1_prg.c
 *
 *  Created on: Feb 14, 2023
 *      Author: DELL
 */
#include <avr/interrupt.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER1_pvt.h"
#include "TIMER1_config.h"
#include "TIMER1_int.h"


static void (* Arr_CallBack[4])(void) = {NULL};

// Public Function Definition
//	mode = normal, prescaler
void M_TIMER1_void_init				(void)
{
	// SET MODE  AS NORMAL
	CLR_BIT(TCCR1A_REG, TCCR1A_REG_WGM10_BIT);
	CLR_BIT(TCCR1A_REG, TCCR1A_REG_WGM11_BIT);

	CLR_BIT(TCCR1B_REG, TCCR1B_REG_WGM12_BIT);
	CLR_BIT(TCCR1B_REG, TCCR1B_REG_WGM13_BIT);
}
void M_TIMER1_void_start			(void)
{
	// SET PRESCALLER AS 256
	CLR_BIT(TCCR1B_REG, TCCR1B_REG_CS10_BIT);
	CLR_BIT(TCCR1B_REG, TCCR1B_REG_CS11_BIT);
	SET_BIT(TCCR1B_REG, TCCR1B_REG_CS12_BIT);
}
void M_TIMER1_void_stop			(void)
{
	// SET PRESCALLER AS 0
	CLR_BIT(TCCR1B_REG, TCCR1B_REG_CS10_BIT);
	CLR_BIT(TCCR1B_REG, TCCR1B_REG_CS11_BIT);
	CLR_BIT(TCCR1B_REG, TCCR1B_REG_CS12_BIT);
	TCNT1L_REG = 0;
}
//	setup initial trigger for ICU
void M_TIMER1_ICU_void_init			(void)
{
	// SET initial trigger = Rising
	SET_BIT(TCCR1B_REG, TCCR1B_REG_ICES1_BIT);
}
void M_TIMER1_ICU_void_IntEnable	(void)
{
	SET_BIT(TIMSK_REG, TIMSK_REG_TICIE1_BIT);
}
void M_TIMER1_ICU_void_IntDisable	(void)
{
	CLR_BIT(TIMSK_REG, TIMSK_REG_TICIE1_BIT);
}
void M_TIMER1_ICU_void_setTrigg		(u8 	Copy_u8TriggID)
{
	switch(Copy_u8TriggID)
	{
	case TIMER1_ICU_FALLING_TRIGG:
		CLR_BIT(TCCR1B_REG, TCCR1B_REG_ICES1_BIT);
		break;
	case TIMER1_ICU_RISING_TRIGG:
		SET_BIT(TCCR1B_REG, TCCR1B_REG_ICES1_BIT);
		break;
	default: // do nothing
		break;
	}
}
u16  M_TIMER1_ICU_u16_takeReading	(void)
{
	return ICR1L_REG;
}
void M_TIMER1_ICU_void_setCallBack	(void (* ptrfun)(void))
{
	if(ptrfun != NULL)
	{
		Arr_CallBack[0] = ptrfun;
	}
}

ISR(TIMER1_CAPT_vect)
{
	if(Arr_CallBack[0] != NULL)
	{
		Arr_CallBack[0]();
	}
}
