/*
 * main.c
 *
 *  Created on: Oct 10, 2023
 *      Author: yasse
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

void main(void)
{
	u8 Local_u8InputVAlue = 0;
	/* set pin A1 as input for switch  */
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_INPUT);

	/* Activate Pullup */
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_HIGH);

	/* set pin A0 as output for LED */
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);

	while(1)
	{
		DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN7,&Local_u8InputVAlue);

		if(Local_u8InputVAlue == 0){
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}

		else{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}

	}

}


