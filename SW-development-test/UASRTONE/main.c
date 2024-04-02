/*
 * main.c
 *
 *  Created on: Jan 25, 2024
 *      Author: yasse
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "UART_interface.h"
#include <util/delay.h>
/* act as receiver */
void action();
void main(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	UART_configuration UARTConfig = {9600, 8, 2, 0};
	USART_Init(&UARTConfig);
	USART_SetReceiveInterrupt();
	GIE_voidEnable();
	USART_SetReceiveCallBack(&action);
	while(1)
	{

	}
}

void action()
{
	int val = USART_Receive();
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,val);
	_delay_ms(50);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
}
