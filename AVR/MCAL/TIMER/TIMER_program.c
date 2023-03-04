/*
 * TIMER_prg.c
 *
 *  Created on: Feb 8, 2023
 *      Author: DELL
 */
#include <avr/interrupt.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER_pvt.h"
#include "TIMER_config.h"
#include "TIMER_int.h"

/******************  Global Variables ******************/
static void (* Arr_CallBack[2])(void) = {NULL};
static u32 Global_u32NumberOfOVF = 0;
static u32 Global_u32RemainNumberOfOVF = 0;
/****************** Public Function Definition ******************/
void M_TIMER0_void_init				(void)
{
	// Step 1: config Timer mode
#if(TIMER0_MODE == TIMER0_NORMAL_MODE)
	CLR_BIT(TCCR0_REG, TCCR0_WGM00_bit);
	CLR_BIT(TCCR0_REG, TCCR0_WGM01_bit);
	// Step 2: Choose OC0 pin Mode
	#if(TIMER0_OC0_PIN_MODE >= TIMER0_OC0_MODE_DISCONNECTED && TIMER0_OC0_PIN_MODE <= TIMER0_OC0_MODE_SET)
	// Apply mask;
	TCCR0_REG &= TIMER_OC0_MASK;
	// Insert Value;
	TCCR0_REG |= TIMER0_OC0_PIN_MODE << TIMER_OC0_SHIFT;
	#else
		#error("Wrong OC0 Mode")
	#endif

#elif(TIMER0_MODE == TIMER0_CTC_MODE)
	CLR_BIT(TCCR0_REG, TCCR0_WGM00_bit);
	SET_BIT(TCCR0_REG, TCCR0_WGM01_bit);

	// Step 2: Choose OC0 pin Mode
	#if(TIMER0_OC0_PIN_MODE >= TIMER0_OC0_MODE_DISCONNECTED && TIMER0_OC0_PIN_MODE <= TIMER0_OC0_MODE_SET)
	// Apply mask;
	TCCR0_REG &= TIMER_OC0_MASK;
	// Insert Value;
	TCCR0_REG |= TIMER0_OC0_PIN_MODE << TIMER_OC0_SHIFT;
	#else
		#error("Wrong OC0 Mode")
	#endif
#elif(TIMER0_MODE == TIMER0_FAST_PWM_MODE)
	SET_BIT(TCCR0_REG, TCCR0_WGM00_bit);
	SET_BIT(TCCR0_REG, TCCR0_WGM01_bit);
	#if(TIMER0_OC0_PIN_MODE == TIMER0_PWM_NON_INVERTED || TIMER0_OC0_PIN_MODE == TIMER0_PWM_INVERTED)
	TCCR0_REG &= TIMER_OC0_MASK;
	TCCR0_REG |= TIMER0_OC0_PIN_MODE;
	#else
	#error("Wrong OC0 Option")
	#endif
#elif(TIMER0_MODE == TIMER0_PHASE_CORRECT_MODE)
	SET_BIT(TCCR0_REG, TCCR0_WGM00_bit);
	CLR_BIT(TCCR0_REG, TCCR0_WGM01_bit);
	// State 2 : configure OC0 Pin Mode
	#if(TIMER0_OC0_PIN_MODE == TIMER0_PWM_NON_INVERTED || TIMER0_OC0_PIN_MODE == TIMER0_PWM_INVERTED)
	TCCR0_REG &= TIMER_OC0_MASK;
	TCCR0_REG |= TIMER0_OC0_PIN_MODE;
	#else
	#error("Wrong OC0 Option")
	#endif
#else
#error("Wrong Timer Mode")
#endif
}
void M_TIMER0_void_start			(void)
{
#if(TIMER0_PRESCALER >= TIMER0_PRESCALER_NO_CLOCK && TIMER0_PRESCALER <= TIMER0_PRESCALER_EXTCLK_RAISING_EDGE)
	// Apply mask;
	TCCR0_REG &= TIMER_PRESCALER_MASK;
	// Insert Value;
	TCCR0_REG |= TIMER0_PRESCALER;
#else
	#error("Wrong Prescaler Option")
#endif
}
void M_TIMER0_void_stop				(void)
{
	// Apply mask;
	TCCR0_REG &= TIMER_PRESCALER_MASK;
}
void M_TIMER0_void_setTime			(u32 Copy_u32Times_ms)
{
	u32 Local_aPrescaler[] 	= {1,8,64,256,1024};
	// Calculate Tick Time
	f32 Local_f32TickTime 	= (f32)Local_aPrescaler[TIMER0_PRESCALER - 1] / FCPU;
	// Calculate # of Desired ticks
	u32 Local_u32NumberOfDesiredTicks = (Copy_u32Times_ms * 1000) / Local_f32TickTime;
#if(TIMER0_MODE == TIMER0_NORMAL_MODE)
	Global_u32NumberOfOVF 		= Local_u32NumberOfDesiredTicks / 256;
	Global_u32RemainNumberOfOVF = Local_u32NumberOfDesiredTicks % 256;
	if(Global_u32RemainNumberOfOVF != 0)
	{
		TCNT0_REG = 256 - Global_u32RemainNumberOfOVF;
		Global_u32NumberOfOVF++;
	}
#elif(TIMER0_MODE == TIMER0_CTC_MODE)

#endif

}
void M_TIMER0_void_enableInt		(u8 Copy_u8IntID)
{
	// Method 1:
	/*
	switch(Copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		SET_BIT(TIMSK_REG, TIMSK_TOIE0_bit);
		break;
	case TIMER0_CMP_INT_ID:
		SET_BIT(TIMSK_REG, TIMSK_OCIE0_bit);
		break;
	}
	*/
	// Method 2:
	if(Copy_u8IntID >= TIMER0_OVF_INT_ID && Copy_u8IntID <= TIMER0_CMP_INT_ID )
	{
		SET_BIT(TIMSK_REG, Copy_u8IntID);
	}

}
void M_TIMER0_void_disableInt		(u8 Copy_u8IntID)
{
	if(Copy_u8IntID >= TIMER0_OVF_INT_ID && Copy_u8IntID <= TIMER0_CMP_INT_ID )
	{
		CLR_BIT(TIMSK_REG, Copy_u8IntID);
	}
}
void M_TIMER0_void_setCallBack		(void (* ptrfn) (void), u8 Copy_u8IntID)
{
	switch(Copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		Arr_CallBack[TIMER0_OVF_INT_ID] = ptrfn;
		break;
	case TIMER0_CMP_INT_ID:
		Arr_CallBack[TIMER0_CMP_INT_ID] = ptrfn;
		break;
	}
}
void M_TIMER0_void_setFastPWM			(u8 Copy_u8Duty)
{
#if(TIMER0_MODE == TIMER0_FAST_PWM_MODE)
	#if(TIMER0_OC0_PIN_MODE == TIMER0_PWM_NON_INVERTED)
		OCR0_REG =  abs (((Copy_u8Duty * 256) / 100) - 1);
	#elif(TIMER0_OC0_PIN_MODE == TIMER0_PWM_INVERTED)
		OCR0_REG =  255 - ((Copy_u8Duty * 256) / 100) - 1);
	#else
		#error("Wrong OC0 Mode")
	#endif
#endif
}
void M_TIMER0_void_setPhaseCorrectPWM	(u8 Copy_u8Duty)
{
#if(TIMER0_MODE == TIMER0_PHASE_CORRECT_MODE)
	#if(TIMER0_OC0_PIN_MODE == TIMER0_PWM_NON_INVERTED)
		OCR0_REG =  ((Copy_u8Duty * 255) / 100);
	#elif(TIMER0_OC0_PIN_MODE == TIMER0_PWM_INVERTED)
		OCR0_REG =  (255 - (Copy_u8Duty * 255) / 100);
	#else
		#error("Wrong OC0 Mode")
	#endif
#endif
}

ISR(TIMER0_OVF_vect)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter ++;
	if(Local_u32Counter == Global_u32NumberOfOVF)
	{
		// reload TCNT with preload value
		TCNT0_REG = 256 - Global_u32RemainNumberOfOVF;
		// Zero counter
		Local_u32Counter = 0;
		// Action
		if(Arr_CallBack[TIMER0_OVF_INT_ID] != NULL)
		{
			Arr_CallBack[TIMER0_OVF_INT_ID]();
		}
	}
}
ISR(TIMER0_COMP_vect)
{
	if(Arr_CallBack[TIMER0_CMP_INT_ID] != NULL)
	{
		Arr_CallBack[TIMER0_CMP_INT_ID]();
	}
}
