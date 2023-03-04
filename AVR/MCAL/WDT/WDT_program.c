/*
 * WDT_prg.c
 *
 *  Created on: Feb 15, 2023
 *      Author: DELL
 */
#include <avr/interrupt.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "WDT_pvt.h"
#include "WDT_int.h"

void M_WDT_void_enable		(void)
{
	SET_BIT(WDTCR_REG, WDTCR_REG_WDE_bit);
}
void M_WDT_void_disable		(void)
{
	WDTCR_REG |= (1 << WDTCR_REG_WDE_bit) | (1 << WDTCR_REG_WDTOE_bit);
	WDTCR_REG = 0x00;
}
void M_WDT_void_sleep		(u8 Copy_u8TimeOut)
{
	if(Copy_u8TimeOut <= WDT_TIMEOUT_2_1_S)
	{
		WDTCR_REG &= 0b11111000;
		WDTCR_REG |= Copy_u8TimeOut;
	}
}
void M_WDT_void_refresh		(void)
{
	asm("WDR");
}
