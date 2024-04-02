#ifndef  UART_INTERFACE_H_
#define  UART_INTERFACE_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: UART                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 
#define DISABLED_PARITY 0
#define ODD_PARITY  1
#define EVEN_PARITY 2
/*
Name: UART_configuration
Description: A structure representing the configuration parameters for USART.
Members:
1- baud_rate: The baud rate for communication.
2- data_bits: The number of data bits (e.g., 5 or 6 or 7 or 8 bits).
3- stop_bits: The number of stop bits (e.g., 1 or 2 bits).
4- parity: Parity type (e.g., DISABLED_PARITY, ODD_PARITY, EVEN_PARITY).
*/
typedef struct UART_configuration{
    u16 baud_rate;
    u8 data_bits;
    u8 stop_bits; 
    u8 parity;
}UART_configuration;

/*
Function Name: USART_Init
Description: Initializes the USART (Universal Synchronous Asynchronous Receiver Transmitter) module based on the provided configuration.
Parameters: USART_config: A pointer to a structure (UART_configuration) containing configuration parameters for baud rate, data bits, stop bits, and parity.
Return Type: void
*/
void USART_Init(UART_configuration *USART_config);

/*
Function Name: USART_Transmit
Description: Sends a single byte of data using USART.
Parameters: data "The byte of data to be transmitted".
Return Type: void
*/
void USART_Transmit(u8 data);

/*
Function Name: USART_Receive
Description: Receives a single byte of data using USART.
Parameters: None
Return Type: u8 (the received byte).
*/
u8 USART_Receive(void);

/*
Function: USART_SetReceiveInterrupt
Description: Enables the USART Receive Complete Interrupt.
*/
void USART_SetReceiveInterrupt();

void USART_SetTransmitInterrupt();

/*
Function: USART_SetReceiveCallBack
Description: Sets a callback function to be executed upon USART Receive Complete Interrupt.
Parameters:
- Copy_pvCallBackFunc: Pointer to the callback function.
Returns:
- Local_u8ErrorStatus.
*/
u8 USART_SetReceiveCallBack(void (*Copy_pvCallBackFunc)(void));

u8 USART_SetTransmitCallBack(void (*Copy_pvCallBackFunc)(void));

#endif
