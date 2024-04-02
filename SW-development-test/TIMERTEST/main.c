/*
 * main.c
 *
 *  Created on: Jan 3, 2024
 *      Author: yasse
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include <util/delay.h>
void main(void)
{
	u16 Local_u8Counter;
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_OUTPUT);

	TIMER1_voidInit();
	TIMER1_voidSetICR(20000);


	while(1)
	{
		/* pin 5 PD */
		for(Local_u8Counter = 750; Local_u8Counter<2500; Local_u8Counter++)
		{
			TIMER1_voidSetChannelACompMatchValue(Local_u8Counter);
			_delay_ms(10);
		}
	}

}
