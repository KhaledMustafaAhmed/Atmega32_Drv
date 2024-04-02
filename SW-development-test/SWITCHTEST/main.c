/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: yasse
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SW_interface.h"
#include "LED_interface.h"

int main(void)
{
	LED_t LED_1 = {DIO_u8PORTB, DIO_u8PIN7, SOURCE};

	/* Activate PULLUP */
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN7, DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN7, DIO_u8PIN_HIGH);

	while(1)
	{

		if(SW_u8GetState(DIO_u8PORTD,  DIO_u8PIN7, PullUP) == PRESSED)
			{
				LED_u8TurnOn(&LED_1);
			}
			else
			{
				LED_u8TurnOff(&LED_1);
			}

	}
	return 0;
}

