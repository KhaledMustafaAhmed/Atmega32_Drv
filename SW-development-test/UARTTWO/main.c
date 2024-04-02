/*
 * main.c
 *
 *  Created on: Jan 25, 2024
 *      Author: yasse
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include <util/delay.h>
/* act as transmitter */

void main(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	UART_configuration UARTConfig = {9600, 8, 2, 0};
	USART_Init(&UARTConfig);
	while(1)
	{
		USART_Transmit(1);
		_delay_ms(50);
	}
}

