#ifndef  TIMER_CONFIG_H_
#define  TIMER_CONFIG_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     SWC: TIMER                **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

/* Initial state for Timer
 * 1- TIMER_ENABLE
 * 2- TIMER_DISABLE
 */
#define TIMER0_INITIAL_STATE	TIMER_DISABLE

/* Different modes of Timer:
 * 1- TIMER_NORMAL_MODE
 * 2- TIMER_CTC_MODE
 * 3- TIMER_FAST_PWM
 * 4- TIMER_PHASE_CORRECT_PWM
 */
#define TIMER0_MODE	TIMER_NORMAL_MODE

/* Different Clock options and prescaler for Timer:
 * 1- TIMER_NO_CLOCK
 * 2- TIMER_PRESCALER_1
 * 3- TIMER_PRESCALER_8
 * 4- TIMER_PRESCALER_64
 * 5- TIMER_PRESCALER_256
 * 6- TIMER_PRESCALER_1024
 */
#define TIMER0_PRESCALER	TIMER_PRESCALER_8
/* Timer0 overflow time options */
#if TIMER0_PRESCALER == TIMER_PRESCALER_1
#define TIMER0_OVER_FLOW_TIME	32
#elif TIMER0_PRESCALER == TIMER_PRESCALER_8
#define TIMER0_OVER_FLOW_TIME	256
#elif TIMER0_PRESCALER == TIMER_PRESCALER_64
#define TIMER_OVER_FLOW_TIMER	2048
#elif TIMER0_PRESCALER == TIMER_PRESCALER_256
#define TIMER_OVER_FLOW_TIMER	8192
#elif TIMER0_PRESCALER == TIMER_PRESCALER_1024
#define TIMER_OVER_FLOW_TIMER	32768
#endif


/* Enable Or Disable overflow interrupt:
 * 1- TIMER_OVER_FLOW_INTERRUPT_ENABLE
 * 2- TIMER_OVER_FLOW_INTERRUPT_DISABLE
 */
#define TIMER0_OVER_FLOW_INTERRUPT	TIMER_OVER_FLOW_INTERRUPT_ENABLE




#endif
