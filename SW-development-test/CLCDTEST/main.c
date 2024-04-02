/*
 * main.c
 *
 *  Created on: Oct 31, 2023
 *      Author: yasse
 */

#include "STD_TYPES.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"

void main(void)
{
	/* Set Directions */
	DIO_u8SetPortnDirection(DIO_u8PORTA, DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_OUTPUT);

	CLCD_voidInit();

	CLCD_voidSendData('K');
	CLCD_voidSendData('h');
	CLCD_voidSendData('a');
	CLCD_voidSendData('l');
	CLCD_voidSendData('e');
	CLCD_voidSendData('d');
	while(1);

}
