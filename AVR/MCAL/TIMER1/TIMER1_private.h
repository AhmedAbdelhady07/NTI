/*
 * TIMER1_pvt.h
 *
 *  Created on: Feb 14, 2023
 *      Author: DELL
 */

#ifndef TIMER1_TIMER1_PVT_H_
#define TIMER1_TIMER1_PVT_H_

#define TCNT1L_REG					(*((volatile u16 * ) 0x4C))
#define TCCR1A_REG					(*((volatile u8  * ) 0x4F))
#define TCCR1B_REG					(*((volatile u8  * ) 0x4E))
#define ICR1L_REG					(*((volatile u16 * ) 0x46))
#define TIMSK_REG					(*((volatile u8  * ) 0x59)) // PIEs

// TCCR1A_REG
// COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10
#define TCCR1A_REG_WGM10_BIT			0
#define TCCR1A_REG_WGM11_BIT			1
#define TCCR1A_REG_FOC1B_BIT			2
#define TCCR1A_REG_FOC1A_BIT			3
#define TCCR1A_REG_COM1B0_BIT			4
#define TCCR1A_REG_COM1B1_BIT			5
#define TCCR1A_REG_COM1A0_BIT			6
#define TCCR1A_REG_COM1A1_BIT			7

// TCCR1B_REG
// ICNC1 ICES1 � WGM13 WGM12 CS12 CS11 CS10
#define TCCR1B_REG_CS10_BIT				0
#define TCCR1B_REG_CS11_BIT				1
#define TCCR1B_REG_CS12_BIT				2
#define TCCR1B_REG_WGM12_BIT			3
#define TCCR1B_REG_WGM13_BIT			4
#define TCCR1B_REG_ICES1_BIT			6
#define TCCR1B_REG_ICNC1_BIT			7
// TIMSK_REG
#define TIMSK_REG_TICIE1_BIT			5

#endif /* TIMER1_TIMER1_PVT_H_ */
