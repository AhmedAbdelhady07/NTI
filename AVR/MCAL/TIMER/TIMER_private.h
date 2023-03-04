/*
 * TIMER_pvt.h
 *
 *  Created on: Feb 8, 2023
 *      Author: DELL
 */

#ifndef TIMER_TIMER_PVT_H_
#define TIMER_TIMER_PVT_H_

/*********************** TIMER REGISTER *********************/
#define TCNT0_REG					(*((volatile u8 *)0x52)) // Counter Reg
#define TCCR0_REG					(*((volatile u8 *)0x53)) // Control Reg
#define OCR0_REG					(*((volatile u8 *)0x5C)) // Compare match Reg

#define TIMSK_REG					(*((volatile u8 *)0x59)) // PIEs
#define TIFR_REG					(*((volatile u8 *)0x58)) // Flages

/************* TCCR0 Reg bits ****************/
#define TCCR0_CS00_bit				0
#define TCCR0_CS01_bit				1
#define TCCR0_CS02_bit				2
#define TCCR0_WGM01_bit				3
#define TCCR0_COM00_bit				4
#define TCCR0_COM01_bit				5
#define TCCR0_WGM00_bit				6

/************* TIMSK Reg bits ****************/
#define TIMSK_TOIE0_bit				0 // OVF Interrupt Enable
#define TIMSK_OCIE0_bit				1 // Compare Match Interrupt Enable
#define TIMSK_TOIE1_bit				2
#define TIMSK_OCIE1B_bit			3
#define TIMSK_OCIE1A_bit			4
#define TIMSK_TICIE1_bit			5
#define TIMSK_TOIE2_bit				6
#define TIMSK_OCIE2_bit				7

#define TIMER_PRESCALER_MASK		0b11111000// 0xF8
#define TIMER_OC0_MASK				0b11001111// 0xCF
#define TIMER_OC0_SHIFT				4

/********* Private Macros for Modes ****************/
#define TIMER0_NORMAL_MODE       	0
#define TIMER0_CTC_MODE          	1
#define TIMER0_FAST_PWM_MODE         	2
#define TIMER0_PHASE_CORRECT_MODE	3
/********* Private Macros for Prescaler ****************/
#define TIMER0_PRESCALER_NO_CLOCK            	0
#define TIMER0_PRESCALER_NO_PRESCALER        	1
#define TIMER0_PRESCALER_8                   	2
#define TIMER0_PRESCALER_64                  	3
#define TIMER0_PRESCALER_256                 	4
#define TIMER0_PRESCALER_1024                	5
#define TIMER0_PRESCALER_EXTCLK_FALLING_EDGE 	6
#define TIMER0_PRESCALER_EXTCLK_RAISING_EDGE 	7
/************** OC0 pin mode Options for non PWM ****************/
#define TIMER0_OC0_MODE_DISCONNECTED			0
#define TIMER0_OC0_MODE_TOGGLE      			1
#define TIMER0_OC0_MODE_CLEAR       			2
#define TIMER0_OC0_MODE_SET         			3
/************** OC0 pin mode Options for Fast PWM ****************/
#define TIMER0_PWM_NON_INVERTED       			0b00100000//0x20
#define TIMER0_PWM_INVERTED         			0b00110000//0x30
#endif /* TIMER_TIMER_PVT_H_ */
