/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     Version: 1                **************************/
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h" 
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_register.h"

static void(*TIMER0_OVF_CallbackFunc)(void) = NULL;
static u32 TIMER0_u32preloadValu = 0 ;
static u32 TIMER0_u32Counter = 0;
static u32 TIMER0_32ISROverFlowCounterCheck = 0;

void TIMER0_Init(void)
{
#if TIMER0_MODE == NORMAL_MODE
	CLEAR_BIT(TCCR0,TCCR0_WGM00);
	CLEAR_BIT(TCCR0,TCCR0_WGM01);
#else
#error "Wrong Configurations options For Timer0 Mode"
#endif
}

u8 TIMER0_Start(u32 reqTime , void(*CallBackFuncNotification)(void))
{
	u8 Local_u8ErrorState = OK;
	f32 Local_f32OVC;
	if(CallBackFuncNotification != NULL)
	{
		switch (TIMER0_MODE)
		{
		case NORMAL_MODE:
			TIMER0_OVF_CallbackFunc = CallBackFuncNotification;
			Local_f32OVC = ((f32)reqTime / TIMER0_OVT);
			TIMER_SetTIMER0OVFTime(Local_f32OVC);
			#if TIMER0_CK == TIMER0_PRESCALER_1
			CLEAR_BIT(TCCR0, TCCR0_CS02);
			CLEAR_BIT(TCCR0, TCCR0_CS01);
			SET_BIT(TCCR0, TCCR0_CS00);
			#elif TIMER0_CK == TIMER0_PRESCALER_8
			CLEAR_BIT(TCCR0, TCCR0_CS02);
			SET_BIT(TCCR0, TCCR0_CS01);
			CLEAR_BIT(TCCR0, TCCR0_CS00);
			#elif TIMER0_CK == TIMER0_PRESCALER_64
			CLEAR_BIT(TCCR0, TCCR0_CS02);
			SET_BIT(TCCR0, TCCR0_CS01);
			SET_BIT(TCCR0, TCCR0_CS00);
			#elif TIMER0_CK == TIMER0_PRESCALER_256
			SET_BIT(TCCR0, TCCR0_CS02);
			CLEAR_BIT(TCCR0, TCCR0_CS01);
			CLEAR_BIT(TCCR0, TCCR0_CS00);
			#elif TIMER0_CK == TIMER0_PRESCALER_1024
			SET_BIT(TCCR0, TCCR0_CS02);
			CLEAR_BIT(TCCR0, TCCR0_CS01);
			SET_BIT(TCCR0, TCCR0_CS00);
			#endif
			break;
		default:
			Local_u8ErrorState = NOT_OK;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}


	return Local_u8ErrorState;
}

/* Enable Overflow timer0 interrupt */
void TIMER0_EnOVFNotification(void)
{
	SET_BIT(TIMSK, TIMSK_TOIE);
}

/* Disable Overflow timer0 interrupt */
void TIMER0_DISOVFNotification(void)
{
	CLEAR_BIT(TIMSK, TIMSK_TOIE);
}



/* Overflow Timer0 ISR Function */
void __vector_11(void)
{
	if(TIMER0_OVF_CallbackFunc != NULL)
	{
		TIMER0_32ISROverFlowCounterCheck++;
		if(TIMER0_u32Counter == TIMER0_32ISROverFlowCounterCheck)
		{
			TIMER0_32ISROverFlowCounterCheck = 0;
			TCNT0 = TIMER0_u32preloadValu;
			TIMER0_OVF_CallbackFunc();
		}
	}
	else
	{
		/* Do nothing */
	}
}

/*  After calling this function the all config are set but the clock not set yet.*/
static void TIMER_SetTIMER0OVFTime (f32 Local_f32Timer0ctr)
{
	f32 local_f32fraction;
	u32 local_u32preloadvalue;
	if(Local_f32Timer0ctr == 1)
	{
		TIMER0_u32Counter = 1;
		TIMER0_u32preloadValu = 0;
		TCNT0 = 0;
	}
	else if (Local_f32Timer0ctr > 1)
	{
		if(((Local_f32Timer0ctr) - (u32)(Local_f32Timer0ctr)) == 0)
		{
			TIMER0_u32Counter = (u32)(Local_f32Timer0ctr);
			TIMER0_u32preloadValu = 0;
			TCNT0 = 0;
		}
		else
		{
			local_f32fraction = Local_f32Timer0ctr - (u32)(Local_f32Timer0ctr) ;
			local_u32preloadvalue = TIMER0_MAX_VAL_REG * (1 - local_f32fraction);
			TIMER0_u32Counter = (u32)(Local_f32Timer0ctr) + 1;
			TIMER0_u32preloadValu = local_u32preloadvalue;
			TCNT0 = TIMER0_u32preloadValu;
		}
	}
	else if(Local_f32Timer0ctr < 1)
	{
		local_f32fraction = Local_f32Timer0ctr;
		local_u32preloadvalue = TIMER0_MAX_VAL_REG * (1 - local_f32fraction);
		TIMER0_u32Counter = 1;
		TIMER0_u32preloadValu = local_u32preloadvalue;
		TCNT0 = TIMER0_u32preloadValu;
	}
}
