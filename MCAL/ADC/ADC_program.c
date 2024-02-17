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

static u8* ADC_pu8Reading = NULL;
static void(*ADC_pvCallBackNotificationFunc)(void) = NULL;
static u8 ADC_u8State = IDLE;

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
			ADC_u8State = BUSY;
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

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
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
