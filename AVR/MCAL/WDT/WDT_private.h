/*
 * WDT_pvt.h
 *
 *  Created on: Feb 15, 2023
 *      Author: DELL
 */

#ifndef WDT_WDT_PVT_H_
#define WDT_WDT_PVT_H_

#define WDTCR_REG				(*((volatile u8*) 0x41))

// bits
#define WDTCR_REG_WDE_bit		3	// Watch dog enable
#define WDTCR_REG_WDTOE_bit		4	// Watch turn-off enable


#endif /* WDT_WDT_PVT_H_ */
