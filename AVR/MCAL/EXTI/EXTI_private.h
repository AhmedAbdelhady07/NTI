/*
 * EXTI_pvt.h
 *
 *  Created on: Feb 7, 2023
 *      Author: DELL
 */

#ifndef EXTI_EXTI_PVT_H_
#define EXTI_EXTI_PVT_H_

/*************  MCUCR Register  *************/
// Control trigger for IN0, IN1
#define	MCUCR_REG		(*((volatile u8 *)0x55))

/*************  MCUSCR Register  *************/
// Control trigger for IN2
#define	MCUSCR_REG		(*((volatile u8 *)0x54))

/*************  GICR Register  *************/
// PIE for enable IN0, IN1, IN2
#define	GICR_REG		(*((volatile u8 *)0x5B))

/*************  GIFR Register  *************/
// Flags for IN0, IN1, IN2
#define	GIFR_REG		(*((volatile u8 *)0x5A))

/*************  MCUCR Bits  *************/
#define	ISC00_BIT		0
#define	ISC01_BIT		1
#define	ISC10_BIT		2
#define	ISC11_BIT		3

/*************  MCUSCR Bits  *************/
#define	ISC2_BIT		6

/*************  GICR Bits  *************/
#define	INT2_BIT		5
#define	INT0_BIT		6
#define	INT1_BIT		7

/****************      Public Macros     ****************/
#define EXTI_INT0_TRIG_MASK			0b11111100 // 0xFC
#define EXTI_INT1_TRIG_MASK			0b11110011 // 0xF3

#endif /* EXTI_EXTI_PVT_H_ */
