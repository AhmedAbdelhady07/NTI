/*
 * TIMER_int.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Ahmed Abdelhady
 */

#ifndef TIMER_TIMER_INT_H_
#define TIMER_TIMER_INT_H_

/***************************** Public Macros ************************************/
#define TIMER0_OVF_INT_ID			0
#define TIMER0_CMP_INT_ID			1

/***************************** Public Functions Prototypes ******************************/
void M_TIMER0_void_init					(void);// Set timer modes, Set OC0
void M_TIMER0_void_start				(void);// Set Prescaler
void M_TIMER0_void_stop					(void);// No CLK
void M_TIMER0_void_setTime				(u32 Copy_u32Times_ms);
void M_TIMER0_void_enableInt			(u8 Copy_u8IntID);
void M_TIMER0_void_disableInt			(u8 Copy_u8IntID);
void M_TIMER0_void_setCallBack			(void (* ptrfn) (void), u8 Copy_u8IntID);
void M_TIMER0_void_setFastPWM			(u8 Copy_u8Duty);
void M_TIMER0_void_setPhaseCorrectPWM	(u8 Copy_u8Duty);

#endif /* TIMER_TIMER_INT_H_ */
