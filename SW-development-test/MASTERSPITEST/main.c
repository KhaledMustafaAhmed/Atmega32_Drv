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

void TOGLED()
{
	u8 LEDSTATE = 0;
	TOGGLE_BIT(LEDSTATE, 0);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8PIN_HIGH);

}
int main(void)
{
	u8 *data;
	/* MOSI */
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN5,DIO_u8PIN_OUTPUT);
	/* MISO */
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN6,DIO_u8PIN_INPUT);
	/* SS */
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN4,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTB, DIO_u8PIN4,DIO_u8PIN_HIGH);
	/* SCK */
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN7,DIO_u8PIN_OUTPUT);
	/* for LED */
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0,DIO_u8PIN_OUTPUT);

	SPI_voidMasterInit();
	while(1)
	{
		SPI_u8TranscieveASynch(1, data, TOGLED);
	}


	return 0;
}
