/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: RTOS               **************************/ 
/************************     SWC: TIMER                **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h" 
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_register.h"

/* Global Pointer to function*/
static void (*TIMER0_pvCallBackFunc)(void) = NULL; 

void TIMER0_voidInit(void)
{
	/*
	 Choose operation mode:
	 1- WGM01 = 0, WGM00 = 0 >> Normal mode >> TOP = 0xFF
	 2- WGM01 = 0, WGM00 = 1 >> PWM, Phase Correct mode >> TOP = 0xFF
	 3- WGM01 = 1, WGM00 = 0 >> CTC mode >> TOP = OCR0
	 4- WGM01 = 1, WGM00 = 1 >> Fast PWM mode >> TOP = 0xFF
	 */
	CLEAR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*
	 interrupt enable for operation mode: set the required bit from TIMSK register
	*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*
	 set compare match value into OCR register.
	*/
	OCR0 = 250;
	/* 
	Set the clock source [Prescaler options] : 
	1- CS02 = 0, CS01 = 0, CS00 = 0 >> No clock source (Timer/Counter stopped)
	2- CS02 = 0, CS01 = 0, CS00 = 1 >> clkI/O/(No prescaling)
	3- CS02 = 0, CS01 = 1, CS00 = 0 >> clkI/O/8 (From prescaler)
	4- CS02 = 0, CS01 = 1, CS00 = 1 >> clkI/O/64 (From prescaler)
	5- CS02 = 1, CS01 = 0, CS00 = 0 >> clkI/O/256 (From prescaler)
	6- CS02 = 1, CS01 = 0, CS00 = 1 >> clkI/O/1024 (From prescaler)
	*/
	CLEAR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLEAR_BIT(TCCR0,TCCR0_CS02);
}

void TIMER0_voidSetCompareMatchValue(u8 Copy_u8CompareValue)
{
	/*
	 set compare match value into OCR register.
	*/
	OCR0 = Copy_u8CompareValue;
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	/*Local Status*/
	u8 Local_u8ErrorStatus = OK;
	/*check if the poiter if point to NULL or not*/
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}


	return Local_u8ErrorStatus;
}

/*ISR For Timer/Counter0 Compare Match*/
void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
	else
	{
		/* Nothing */
	}
}
