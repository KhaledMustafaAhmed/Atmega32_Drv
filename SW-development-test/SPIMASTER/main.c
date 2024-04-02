/*
 * main.c
 *
 *  Created on: Feb 28, 2024
 *      Author: yasse
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include <util/delay.h>

void LEDTOG(void)
{
	u8 x = 0;
	TOGGLE_BIT(x, 0);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, x);
}
int main(void)
{
	/* MOSI */
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN5 ,DIO_u8PIN_OUTPUT);
	/* MISO */
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN_INPUT);
	/* SS: input Pulled up */
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN4, DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN4, DIO_u8PIN_HIGH);
	/* SCK */
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_OUTPUT);
	/* For LED */
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	SPI_voidMasterInit();
	u8 *recive;
	while(1)
	{
		SPI_u8TranscieveASynch(0, recive,LEDTOG);
	}



	return 0;
}
