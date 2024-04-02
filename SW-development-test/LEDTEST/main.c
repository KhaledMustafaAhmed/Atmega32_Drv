/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: yasse
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "LED_interface.h"

void main(void)
{
	LED_t LED_1 = {DIO_u8PORTB, DIO_u8PIN0, SOURCE};
	while(1)
	{
		LED_u8TurnOn(&LED_1);
		_delay_ms(1000);
		LED_u8TurnOff(&LED_1);
		_delay_ms(1000);
	}

}

