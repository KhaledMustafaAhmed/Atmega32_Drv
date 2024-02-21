#ifndef  TIMER0_PRIVATE_H_
#define  TIMER0_PRIVATE_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     Version: 1                **************************/
/*********************************************************************************/

/* Different Modes in TIMER0 */
#define NORMAL_MODE     1

/* Max value of TCNT0 REG */
#define TIMER0_MAX_VAL_REG	256

/* different prescaler and clock options  */
#define TIMER0_PRESCALER_1  			1
#define TIMER0_PRESCALER_8			    2
#define TIMER0_PRESCALER_64			    3
#define TIMER0_PRESCALER_256			4
#define TIMER0_PRESCALER_1024		    5





/* ISR TIMER0 OverFlow Interrupt */
void __vector_11(void)  __attribute__((signal));

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
