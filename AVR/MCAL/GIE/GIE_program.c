/*
 * GIE_prg.c
 *
 *  Created on: Feb 7, 2023
 *      Author: DELL
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_pvt.h"
#include "GIE_config.h"
#include "GIE_int.h"
void M_GIE_void_enable		(void)
{
	// Method 1:
	//SET_BIT(SREG_REG, I_BIT);
	// Method 2:
	asm("SEI");
}
void M_GIE_void_disable		(void)
{
	// Method 1:
	//CLR_BIT(SREG_REG, I_BIT);
	// Method 2:
	asm("CLI");
}
