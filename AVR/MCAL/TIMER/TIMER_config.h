/*
 * TIMER_config.h
 *
 *  Created on: Feb 8, 2023
 *      Author: DELL
 */

#ifndef TIMER_TIMER_CONFIG_H_
#define TIMER_TIMER_CONFIG_H_

/*
 * Please Choose:
 * 			* TIMER_MODE:
 * 						TIMER0_NORMAL_MODE
 * 						TIMER0_CTC_MODE
 * 						TIMER0_FAST_PWM_MODE
 * 						TIMER0_PHASE_CORRECT_MODE
 *
 *			* TIMER_PRESCALER:
 *						TIMER0_PRESCALER_NO_CLOCK
 *						TIMER0_PRESCALER_NO_PRESCALER
 *						TIMER0_PRESCALER_8
 *						TIMER0_PRESCALER_64
 *						TIMER0_PRESCALER_256
 *						TIMER0_PRESCALER_1024
 *						TIMER0_PRESCALER_EXTCLK_FALLING_EDGE
 *						TIMER0_PRESCALER_EXTCLK_RAISING_EDGE
 *
 *			* TIMER_0C0_PIN_MODE:
 *						TIMER0_OC0_MODE_DISCONNECTED
 *						TIMER0_OC0_MODE_TOGGLE
 *						TIMER0_OC0_MODE_CLEAR
 *						TIMER0_OC0_MODE_SET
 *						TIMER0_PWM_NON_INVERTED
						TIMER0_PWM_INVERTED
 *
 */
#define FCPU					16
#define TIMER0_MODE				TIMER0_PHASE_CORRECT_MODE
#define TIMER0_PRESCALER		TIMER0_PRESCALER_8
#define TIMER0_OC0_PIN_MODE		TIMER0_PWM_NON_INVERTED


#endif /* TIMER_TIMER_CONFIG_H_ */
