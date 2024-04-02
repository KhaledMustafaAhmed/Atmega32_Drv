/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: ADC                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h" 
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"
/*
    typedef struct{
	u8 *Channel;
	u16 *Result;
	u8 *ChainSize;
	void(*NotificationFunc)(void);

}Chain_T;
 */
static u8* ADC_pu8Reading = NULL;
static void(*ADC_pvCallBackNotificationFunc)(void) = NULL;
static u8 ADC_u8State = IDLE;

static u8 *ADC_pu8ChannelArr = NULL; /* Global Variable to carry Channel Array */
static u8 ADC_pu8ChainSize; /* Global variable to carry ChainSize */
static u16 *ADC_pu16Result = NULL; /* Global variable to carry ADC_pu8Result */
static u8 ADC_u8ChainIndex = 0;  /* To carry the current conversion index */
static u8 ADC_u8ISRSoruce;


void ADC_voidInit(void)
{
	/* Voltage Reference Selection */
#if VOLTAGE_SOURCE == AVCC
	CLEAR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#elif VOLTAGE_SOURCE == AREF
	CLEAR_BIT(ADMUX,ADMUX_REFS1);
	CLEAR_BIT(ADMUX,ADMUX_REFS0);
#elif VOLTAGE_SOURCE == INTERNAL
	SET_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#else
#error "Wrong Voltage Reference Selection Configurations "
#endif

	/* Check Left Adjust Result */
#if ADJUST_RESULT == LEFT_ADJUST
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADJUST_RESULT == RIGHT_ADJUST
	CLEAR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "Wrong Adjust Result Configuration "
#endif

	/* ADC Prescaler */
#if ADC_PRESCALER == DIV_BY_2
	ADCSRA &= 0b11111000;
	ADCSRA |= DIV_BY_2;
#elif ADC_PRESCALER == DIV_BY_4
	ADCSRA &= 0b11111000;
	ADCSRA |= DIV_BY_4;
#elif ADC_PRESCALER == DIV_BY_8
	ADCSRA &= 0b11111000;
	ADCSRA |= DIV_BY_8;
#elif ADC_PRESCALER == DIV_BY_16
	ADCSRA &= 0b11111000;
	ADCSRA |= DIV_BY_16;
#elif ADC_PRESCALER == DIV_BY_32
	ADCSRA &= 0b11111000;
	ADCSRA |= DIV_BY_32;
#elif ADC_PRESCALER == DIV_BY_64
	ADCSRA &= 0b11111000;
	ADCSRA |= DIV_BY_64;
#elif ADC_PRESCALER == DIV_BY_128
	ADCSRA &= 0b11111000;
	ADCSRA |= DIV_BY_128;
#else
#error "Wrong ADC Prescaler Configuration"
#endif

	/* Enable ADC peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}


u8 ADC_u8StartConverstionSynch(u8 Copy_u8Channel, u8 *Copy_pu8ADCReading)
{
	u8 Local_u8Counter = 0;
	u8 Local_u8ErrorState = OK;

	if(ADC_u8State == IDLE)
	{
		/* Make ADC State  Busy */
		ADC_u8State = BUSY;
		/* Clear the MUX bit in ADMUX REQ */
		ADMUX &= MUX_MASK;

		/* Set the channel needed into MUX BITS */
		ADMUX |= Copy_u8Channel;

		/* Start Conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);


		/* Polling until conversion complete flag is set */
		while((GET_BIT(ADCSRA, ADCSRA_ADIF) == 0 ) && (Local_u8Counter++ != TIMEOUT));

		if(Local_u8Counter == TIMEOUT)
		{
			/* Loop is broken because the counter is reach TIMEOUT */
			Local_u8ErrorState = NOT_OK;
		}
		else
		{
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			*Copy_pu8ADCReading = ADCH;
			/* ADC is Finished make it IDLE */
			ADC_u8State = IDLE;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}


	return Local_u8ErrorState;
}


u8 ADC_u8StartConvertionAsynch(u8 Copy_u8Channel, u8 *Copy_pu8ADCReading, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(ADC_u8State == IDLE)
	{
		if(Copy_pu8ADCReading == NULL || Copy_pvNotificationFunc == NULL)
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/* Make ADC_u8State BUSY  */
			ADC_u8State = BUSY;
			/* Make ISR Source Single_ASYNCH*/
			ADC_u8ISRSoruce = Single_ASYNCH;
			/* Initialize the Reading Globally */
			ADC_pu8Reading = Copy_pu8ADCReading;
			/* Initialize the NotificationFunc Globally */
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;
			/* Clear the MUX bit in ADMUX REQ */
			ADMUX &= MUX_MASK;
			/* Set the channel needed into MUX BITS */
			ADMUX |= Copy_u8Channel;

			/* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/* Enable ADC interrupt */
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;
}


u8 ADC_u8StartChainAsynch(Chain_T *Copy_Chain)
{
	u8 Local_u8ErrorState = OK;
	/* Check Pointer Not Equal NULL */
	if(Copy_Chain == NULL)
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	else
	{
		if(ADC_u8State == IDLE)
		{
			/* Make ADC_u8State Busy */
			ADC_u8State = BUSY;
			/* Make ISR Source Chain_ASYNCH */
			ADC_u8ISRSoruce = Chain_ASYNCH;
			/* initialize Chain channel Array */
			ADC_pu8ChannelArr  = Copy_Chain->Channel;
			/* initialize Chain Size */
			ADC_pu8ChainSize = Copy_Chain->ChainSize;
			/* initialize Chain result Array */
			ADC_pu16Result = Copy_Chain->Result;
			/* initialize chain Notification Function*/
			ADC_pvCallBackNotificationFunc = Copy_Chain->NotificationFunc;
			/* initialize current conversion index equal 0 */
			ADC_u8ChainIndex = 0;

			/* Set required Channel */
			/* Clear the MUX bit in ADMUX REQ */
			ADMUX &= MUX_MASK;
			/* Set the channel needed into MUX BITS */
			ADMUX |= ADC_pu8ChannelArr[ADC_u8ChainIndex];
			/* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/* Enable ADC interrupt */
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState = BUSY_FUNC;
		}
	}
	return Local_u8ErrorState;
}


void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	if(ADC_u8ISRSoruce == Chain_ASYNCH)
	{
		/* Read the current conversion */
		ADC_pu16Result[ADC_u8ChainIndex] = ADCH;
		/* increment Index */
		ADC_u8ChainIndex++;
		/* check Chain  if finished or not */
		if(ADC_pu8ChainSize == ADC_u8ChainIndex)
		{
			/* finished */
			/* Make ADC State IDLE */
			ADC_u8State = IDLE;
			/* Invoke the callback	notification function  */
			ADC_pvCallBackNotificationFunc();
			/* Disable ADC conversion complete interrupt */
			CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
		}
		else
		{
			/* chain is not finished */
			/* Set new required Channel */
			/* Clear the MUX bit in ADMUX REQ */
			ADMUX &= MUX_MASK;
			/* Set the channel needed into MUX BITS */
			ADMUX |= ADC_pu8ChannelArr[ADC_u8ChainIndex];
			/* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
	}
	else if(ADC_u8ISRSoruce == Single_ASYNCH)
	{
		/* Read ADC Result */
		*ADC_pu8Reading = ADCH;
		/* Make ADC State IDLE */
		ADC_u8State = IDLE;
		/* Invoke the callback	notification function  */
		ADC_pvCallBackNotificationFunc();
		/* Disable ADC conversion complete interrupt */
		CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
	}
}
