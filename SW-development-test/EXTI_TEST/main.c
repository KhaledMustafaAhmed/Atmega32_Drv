/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Khaled
 */

#include "STD_TYPES.h"

#include	"DIO_interface.h"
#include	"EXTI_interface.h"
#include	"GIE_interface.h"
void INT1ISR(void);

void main(void)
{
	/* Pull up activation for PD2 */
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_HIGH);

	/* PA0 direction output */
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_OUTPUT);

	EXTI_voidInt1Init();
	 EXTI_u8Int1SetCallBack(&INT1ISR);
	 GIE_voidEnable();

	while(1)
	{

	}
}

void INT1ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
}

