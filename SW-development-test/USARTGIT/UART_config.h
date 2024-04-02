#ifndef  UART_CONFIG_H_
#define  UART_CONFIG_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: UART                  **************************/
/*********************************************************************************/ 

/*
 * 1- ASYNCHRONOUS
 * 2- SYNCHRONOUS
 */
#define USART_MODE      ASYNCHRONOUS

/* USART Speed:
 * 1- ASYNCH_NORMAL
 * 2- ASYNCH_DOUBLE
 */
#define USART_SPEED	 ASYNCH_NORMAL
/*
 * 1- EVEN_PARITYY
 * 2- ODD_PARITY
 * 3- DISABLE_PARITY
 */
#define USART_PARITY	DISABLE_PARITY

/*
 * 1- ONE
 * 2- TWO
 */
#define STOP_BITS	ONE


/* USART Transmit and Receive options:
 * 1- ENABLE
 * 2- DISABLE
 */
#define USART_TRANSMITER	ENABLE
#define USART_RECEIVER	    ENABLE

/* Set the Baud Rate:  */
#define BAUD_RATE	9600
#endif
