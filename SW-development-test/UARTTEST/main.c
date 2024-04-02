/*
 * main.c
 *
 *  Created on: Jan 20, 2024
 *      Author: yasse
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "UART_interface.h"
#include 	"GIE_interface.h"

void onTransmit();
void onRecieve();
void main(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	UART_configuration USART_Config = {9600, 8, 2, DISABLED_PARITY};
	USART_Init(&USART_Config);
	USART_SetTransmitInterrupt();
	USART_SetReceiveInterrupt();
	GIE_voidEnable();
	USART_SetReceiveCallBack(&onRecieve);
	USART_SetTransmitCallBack(&onTransmit);


	while(1)
	{

	}
}


void onTransmit()
{
	USART_Transmit('D');
}
void onRecieve()
{
	u8 data = USART_Receive();
			if(data == '2')
			{
				DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
			}
			else if(data == '3')
			{
				DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
			}
}
