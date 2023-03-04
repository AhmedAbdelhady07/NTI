/*
 * EXTI_prg.c
 *
 *  Created on: Feb 7, 2023
 *      Author: DELL
 */
#include <avr/interrupt.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_pvt.h"
#include "EXTI_config.h"
#include "EXTI_int.h"

/******************  Global Variables ******************/
static void (* Arr_CallBack[3])(void) = {NULL};

/****************  Function Definition  ****************/
void M_EXTI_void_enable				(EXTI_t Copy_u8IntID , Sense_t Copy_u8Sense)
{
	if((Copy_u8IntID >= EXTT_INT2) && (Copy_u8IntID <= EXTT_INT1) && (Copy_u8Sense >= EXTT_TRIG_LOW_LEVEL) && (Copy_u8Sense <= EXTT_TRIG_RAISING_EDGE))
	{
		// Configure sense
		switch(Copy_u8IntID)
		{
		case EXTT_INT0:
			// Applying Mask
			MCUCR_REG &= EXTI_INT0_TRIG_MASK;
			// Insert Value
			MCUCR_REG |= Copy_u8Sense;
			break;
		case EXTT_INT1:
			// Applying Mask
			MCUCR_REG &= EXTI_INT1_TRIG_MASK;
			// Insert Value
			MCUCR_REG |= (Copy_u8Sense << ISC10_BIT);
			break;
		case EXTT_INT2:
			// Applying Mask
			CLR_BIT(MCUSCR_REG, ISC2_BIT);
			// Insert Value
			MCUSCR_REG |= (GET_BIT(Copy_u8Sense, 0) << ISC2_BIT);
			break;
		}
		// Enable PIE
		SET_BIT(GICR_REG, Copy_u8IntID);
	}
}
void M_EXTI_void_disable			(EXTI_t Copy_u8IntID)
{
	if(Copy_u8IntID >= EXTT_INT2 && Copy_u8IntID <= EXTT_INT1)
	{
		CLR_BIT(GICR_REG, Copy_u8IntID);
	}
}
void M_EXTI_void_setCallBack		(void (*ptrfn)(void), EXTI_t Copy_u8IntID)
{
	switch(Copy_u8IntID)
	{
	case EXTT_INT0:
		Arr_CallBack[0] = ptrfn;
		break;
	case EXTT_INT1:
		Arr_CallBack[1] = ptrfn;
		break;
	case EXTT_INT2:
		Arr_CallBack[2] = ptrfn;
		break;
	}
}

ISR(INT0_vect)
{
	if(Arr_CallBack[0] != NULL)
	{
		Arr_CallBack[0]();
	}

}
ISR(INT1_vect)
{
	if(Arr_CallBack[1] != NULL)
	{
		Arr_CallBack[1]();
	}
}
ISR(INT2_vect)
{
	if(Arr_CallBack[2] != NULL)
	{
		Arr_CallBack[2]();
	}
}
