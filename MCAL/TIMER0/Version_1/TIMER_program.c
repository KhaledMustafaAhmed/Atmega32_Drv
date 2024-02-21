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
static void(*TIMER0_COM_CallbackFunc)(void) = NULL;

static u32 TIMER0_u32preloadValu = 0 ;
static u32 TIMER0_u32Counter = 0;
static u32 TIMER0_32ISROverFlowCounterCheck = 0;
static u32 TIMER0_32ISRCompareMatchCounterCheck = 0;


void TIMER0_Init(void)
{
#if TIMER0_MODE == NORMAL_MODE
	CLEAR_BIT(TCCR0,TCCR0_WGM00);
	CLEAR_BIT(TCCR0,TCCR0_WGM01);
    #elif TIMER0_MODE == CTC_MODE
    CLEAR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
#else
#error "Wrong Configurations options For Timer0 Mode"
#endif

#if TIMER0_OC0_STATE == TIMER0_OC0_DISABLE
    CLEAR_BIT(TCCR0,TCCR0_COM00);
	CLEAR_BIT(TCCR0,TCCR0_COM01);
#elif TIMER0_OC0_STATE == TIMER0_OC0_SET
    SET_BIT(TCCR0,TCCR0_COM00);
    SET_BIT(TCCR0,TCCR0_COM01);
#elif TIMER0_OC0_STATE == TIMER0_OC0_CLEAR
    CLEAR_BIT(TCCR0,TCCR0_COM00);
    SET_BIT(TCCR0,TCCR0_COM01);
#elif TIMER0_OC0_STATE == TIMER0_OC0_TOGGLE
    SET_BIT(TCCR0,TCCR0_COM00);
    CLEAR_BIT(TCCR0,TCCR0_COM01);
#else
#error "Wrong TIMER0_OC0_STATE Options"
#endif
}

u8 TIMER0_Start(u32 reqTime , void(*CallBackFuncNotification)(void))
{
	u8 Local_u8ErrorState = OK;
	f32 Local_f32OVC;
	if(CallBackFuncNotification == NULL || reqTime <= 0  )
	{
		if(CallBackFuncNotification == NULL)
		{
			Local_u8ErrorState = NULL_POINTER;

		}
		else
		{
			Local_u8ErrorState = NOT_OK;
		}
	}
	else
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
		            case CTC_MODE:
		            TIMER0_COM_CallbackFunc = CallBackFuncNotification;
		            Local_f32OVC = ((f32)reqTime / TIMER0_OVT);
		            TIMER_SetTIMER0CTCTime(Local_f32OVC);
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

	return Local_u8ErrorState;
}

/* Enable Overflow timer0 interrupt */
void TIMER0_EnNotification(void)
{
    #if TIMER0_INT == TIMER0_OverFlow_INT_ENABLE
	SET_BIT(TIMSK, TIMSK_TOIE);
    #elif TIMER0_INT == TIMER0_CompareMatch_INT_EN
    SET_BIT(TIMSK, TIMSK_OCIE0);
    #else
    #error "Wrong interrupt options"
    #endif
}

/* Disable Overflow timer0 interrupt */
void TIMER0_DISNotification(void)
{
    #if TIMER0_INT == TIMER0_OverFlow_INT_ENABLE
	CLEAR_BIT(TIMSK, TIMSK_TOIE);
    #elif TIMER0_INT == TIMER0_CompareMatch_INT_EN
     CLEAR_BIT(TIMSK, TIMSK_OCIE0);
    #else
    #error "Wrong interrupt options"
    #endif
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

/*Compare Match Timer0 ISR Function*/
void __vector_10(void)
{
    if(TIMER0_COM_CallbackFunc != NULL)
    {
        TIMER0_32ISRCompareMatchCounterCheck++;
        if(TIMER0_u32Counter == TIMER0_32ISRCompareMatchCounterCheck)
        {
            TIMER0_32ISRCompareMatchCounterCheck = 0;
            TIMER0_COM_CallbackFunc();
        }
    }
    else
    {
        /* Do Nothing*/
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

static void TIMER_SetTIMER0CTCTime (f32 Copy_f32TimerCtr)
{
    f32 local_f32fraction;
    if(Copy_f32TimerCtr == 1)
    {
        TIMER0_u32Counter = 1;
        OCR0 = 0xff;
    }
    else if(Copy_f32TimerCtr > 1)
    {
        if(Copy_f32TimerCtr - ((u32)(Copy_f32TimerCtr)))
        {
            TIMER0_u32Counter = (u32)(Copy_f32TimerCtr);
            OCR0 = 0xff;
        }
        else
        {
            local_f32fraction = TIMER0_MAX_VAL_REG * ((u32)(Copy_f32TimerCtr) - Copy_f32TimerCtr);
            TIMER0_u32Counter = (u32)(Copy_f32TimerCtr);
            OCR0 = (u32)(local_f32fraction);
        }
    }
    else if(Copy_f32TimerCtr < 1)
    {
        local_f32fraction = TIMER0_MAX_VAL_REG * ((Copy_f32TimerCtr));
        TIMER0_u32Counter = 1;
        OCR0 = (u32)(local_f32fraction);
    }
}

