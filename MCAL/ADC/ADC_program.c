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
