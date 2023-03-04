/*******************************************************************/
/*************** Name      : Abdallah Ahmed   **********************/
/*************** Date      : ٢٣‏/٠٢‏/٢٠٢٣  	      **********************/
/*************** SWC       : Smart_home  **********************/
/*************** File Name : MOTOR_prg.c     **********************/
/*************** Version   : 1.0        	  **********************/
/*******************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "MOTOR_int.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/TIMER/TIMER_int.h"

void H_MOTOR_void_init	(void)
{
	// init timer0
	M_TIMER0_void_init();
	M_TIMER0_void_start();

	// config motor direction pins
//	M_DIO_void_setPinDir(PORTC_ID,PIN5, OUTPUT);
//	M_DIO_void_setPinDir(PORTC_ID,PIN6, OUTPUT);

	// PWM PIN
	M_DIO_void_setPinDir(PORTB_ID,PIN3, OUTPUT);

	// motor is stopped
	M_TIMER0_void_setPhaseCorrectPWM(0);
}
void H_MOTOR_void_run	(u8 Copy_u8Duty)
{
	// forward direction
//	M_DIO_void_setPinVal(PORTC_ID,PIN5, HIGH);
//	M_DIO_void_setPinVal(PORTC_ID,PIN6, LOW);

	if(Copy_u8Duty <= 100)
	{
		M_TIMER0_void_setPhaseCorrectPWM(Copy_u8Duty);
	}
}
