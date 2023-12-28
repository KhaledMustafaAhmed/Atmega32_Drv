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
static u8 *ADC_pu8Reading = NULL;

static void(*ADC_pvCallBackNotificationFunc)(void) = NULL;

u8 ADC_u8BusyState = IDLE;

void ADC_voidInit(void)
{
	/* AVCC as reference voltage  */
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLEAR_BIT(ADMUX, ADMUX_REFS1);

	/* Activate left adjust result 8bit */
	SET_BIT(ADMUX, ADMUX_ADLAR);

	/* set prescaler to divide by128 */
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);

	/* Enable ADC */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8 *Copy_pu8Reading)
{
	u32 Local_u8Counter = 0;
	u8 Local_u8ErrorState = OK;
	if(ADC_u8BusyState == IDLE)
	{
		ADC_u8BusyState = BUSY;
		/* Clear the mask bits in ADMUX register */
		ADMUX &=0b11100000;
		/* Set the required channel into the MUX bits */
		ADMUX |= Copy_u8Channel;

		/* Start ADC conversion */
		SET_BIT(ADCSRA, ADCSRA_ADSC);

		/* Polling busy waiting until the conversion complete flag is set or counter equal timeout */
		while((GET_BIT(ADCSRA, ADCSRA_ADIF) == 0) && (Local_u8Counter != ADC_u32TIMEOUT))
		{
			Local_u8Counter++;
		}
		if(Local_u8Counter == ADC_u32TIMEOUT)
		{
			// Loop in broken because timeout is reached
			Local_u8ErrorState = NOT_OK;
		}
		else
		{
			// Loop in broken because flag is raised
			SET_BIT(ADCSRA, ADCSRA_ADIF);
			*Copy_pu8Reading = ADCH;
			/* ADC is finished return it to IDLE */
			ADC_u8BusyState = IDLE;
		}

	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	/* return the ADC value */
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionASynch(u8 Copy_u8Channel, u8 *Copy_pu8Reading, void(*Copy_pvNotificatioFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(ADC_u8BusyState == IDLE)
	{

		if((Copy_pu8Reading == NULL) || (Copy_pvNotificatioFunc == NULL))
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/* Make ADC Busy in order not to work until being IDLE */
			ADC_u8BusyState = BUSY;
			/* Initialize the reading variable globally */
			ADC_pu8Reading = Copy_pu8Reading;

			/* Initialize the callback notification function globally */
			ADC_pvCallBackNotificationFunc = Copy_pvNotificatioFunc;

			/* Clear the mask bits in ADMUX register */
			ADMUX &=0b11100000;
			/* Set the required channel into the MUX bits */
			ADMUX |= Copy_u8Channel;

			/* Start ADC conversion */
			SET_BIT(ADCSRA, ADCSRA_ADSC);


			/* ADC Interrupt Enable */
			SET_BIT(ADCSRA, ADCSRA_ADIE);
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

void__vector_16 (void) __attribute__((signal));
void__vector_16 (void)
{
	/* read ADC result */
	*ADC_pu8Reading = ADCH;

	/* make ADC State be IDLE */
	ADC_u8BusyState = IDLE;
	/* invoke the call back notification function */
	ADC_pvCallBackNotificationFunc();

	/* disable ADC conversion complete interrupt */
	CLEAR_BIT(ADCSRA,ADCSRA_ADIE);
}
