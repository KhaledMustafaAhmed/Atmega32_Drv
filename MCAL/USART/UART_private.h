#ifndef  UART_PRIVATE_H_
#define  UART_PRIVATE_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: UART                 **************************/
/*********************************************************************************/ 

/* System Clock */
#define FSYS	8000000

/* Options for speed of transmition: U2X */
#define ASYNCH_NORMAL 	1
#define ASYNCH_DOUBLE	2

/* options for enable or disable */
#define ENABLE	1
#define DISABLE	2

/* USART Modes: */
#define ASYNCHRONOUS	1
#define SYNCHRONOUS		2

/* Parity Modes: */
#define EVEN_PARITYY	1
#define ODD_PARITY		2
#define DISABLE_PARITY	3

/* Stop Bits */
#define ONE	1
#define TWO	2


#define CHARACTER	1
#define STRING		2


#define IDlE		1
#define USART_BUSY	2

#define UBRRH_MASK	0b00001111

/* ISR For USART, Rx Complete: */
void __vector_13(void)	__attribute__((signal));

/* ISR For USART Data Register Empty: */
void __vector_14(void)    __attribute__((signal));

/* ISR For USART, Tx Complete: */
void __vector_15(void)	__attribute__((signal));



#endif
