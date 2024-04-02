#ifndef  TIMER_PRIVATE_H_
#define  TIMER_PRIVATE_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     SWC: TIMER                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

/* Number of available timers in AVR Atmega32 */
#define NUM_Of_TIMERS	3

/* Max value of TCNT REGs */
#define TIMER02_MAX_VALUE_REG	255
#define TIMER1_MAX_VALUE_REG	65536

/* initial state of timers */
#define TIMER_ENABLE	1
#define TIMER_DISABLE	2

/* different modes in timer */
#define TIMER_NORMAL_MODE			1
#define TIMER_CTC_MODE				2
#define TIMER_FAST_PWM				3
#define TIMER_PHASE_CORRECT_PWM		4

/* different prescaler and clock options  */
#define TIMER_NO_CLOCK				1
#define TIMER_PRESCALER_1  			2
#define TIMER_PRESCALER_8			3
#define TIMER_PRESCALER_64			4
#define TIMER_PRESCALER_256			5
#define TIMER_PRESCALER_1024		6


/* initial state of interrupts */
#define	TIMER_OVER_FLOW_INTERRUPT_ENABLE	1
#define	TIMER_OVER_FLOW_INTERRUPT_DISABLE	2


/* ISR TIMER0 OverFlow Interrupt */
void __vector_11  __attribute__((signal));

/*************************************************************************************/
/*Static Functions to set the desired time needed in case of normal mode or CTC mode */
/*************************************************************************************/
static void TIMER_SetTIMER0OVFTime (f32 Copy_f32TimerCtr);
static void TIMER_SetTIMER1OVFTime (f32 Copy_f32TimerCtr);
static void TIMER_SetTIMER2OVFTime (f32 Copy_f32TimerCtr);

static void TIMER_SetTIMER0CTCTime (f32 Copy_f32TimerCtr);
static void TIMER_SetTIMER1CTCTime (f32 Copy_f32TimerCtr);
static void TIMER_SetTIMER2CTCTime (f32 Copy_f32TimerCtr);



#endif
