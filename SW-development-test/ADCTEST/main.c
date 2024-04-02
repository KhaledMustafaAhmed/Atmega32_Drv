/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: yasse
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "DIO_interface.h"


int main(void)
{
	u8 Local_u8ADCReading;
	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PORT_INPUT);
	DIO_u8SetPortDirection(DIO_u8PORTC, DIO_u8PORT_OUTPUT);

	ADC_voidInit();



	while(1)
	{
		Local_u8ADCReading = ADC_u8GetChannelReading(0);

		DIO_u8SetPortValue(DIO_u8PORTC, Local_u8ADCReading);
	}
	return 0;
}
