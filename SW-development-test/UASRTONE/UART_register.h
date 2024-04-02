#ifndef  UART_REGISTER_H_
#define  UART_REGISTER_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: UART                **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

#define UDR         *((volatile u8*)0x2C)    /*USART I/O Data Register – UDR*/
#define UCSRA       *((volatile u8*)0x2B)    /*USART Control and Status Register A – UCSRA*/ 
#define UCSRA_RXC   7                       /*USART Receive Complete flag*/
#define UCSRA_TXC   6                       /*USART Transmit Complete flag*/
#define UCSRA_UDRE  5                       /*USART Data Register Empty flag*/
#define UCSRA_FE    4                       /*Frame Error*/
#define UCSRA_DOR   3                       /*Data OverRun*/
#define UCSRA_PE    2                       /*Parity Error*/
#define UCSRA_U2X   1                       /*Double the USART Transmission Speed*/
#define UCSRA_MPCM  0                       /*Multi-processor Communication Mode*/

#define UCSRB        *((volatile u8*)0x2A)   /*USART Control and Status Register B – UCSRB*/
#define UCSRB_RXCIE  7                      /*RXCIE RX Complete Interrupt Enable flag*/ 
#define UCSRB_TXCIE  6                      /*TXCIE TX Complete Interrupt Enable flag*/ 
#define UCSRB_UDRIE  5                      /*UDRIE USART Data Register Empty Interrupt Enable flag*/ 
#define UCSRB_RXEN   4                      /*RXEN Receiver Enable*/ 
#define UCSRB_TXEN   3                      /*TXEN Transmitter Enable*/ 
#define UCSRB_UCSZ2  2                      /*UCSZ2 Character Size*/ 
#define UCSRB_RXB8   1                      /*RXB8 Receive Data Bit 8*/ 
#define UCSRB_TXB8   0                      /*TXB8 Transmit Data Bit 8*/ 

#define UCSRC        *((volatile u8*)0x40)  /*USART Control and Status Register C – UCSRC*/
#define UCSRC_URSEL  7                      /*URSEL  Register Select*/ 
#define UCSRC_UMSEL  6                      /*UMSEL USART Mode Select*/ 
#define UCSRC_UPM1   5                      /*UPM1  Parity Mode*/ 
#define UCSRC_UPM0   4                      /*UPM0  Parity Mode*/ 
#define UCSRC_USBS   3                      /*USBS  Stop Bit Select*/ 
#define UCSRC_UCSZ1  2                      /*UCSZ1 Character Size*/ 
#define UCSRC_UCSZ0  1                      /*UCSZ0 Character Size*/ 
#define UCSRC_UCPOL  0                      /*UCPOL Clock Polarity*/ 
 
#define UBRRH        *((volatile u8*)0x40)  /*USART Baud Rate Registers UBRRH*/
#define UBRRH_URSEL  7                      /*URSEL  Register Select*/ 
#define UBRRH_UBRR0  0
#define UBRRH_UBRR1  1
#define UBRRH_UBRR2  2
#define UBRRH_UBRR3  3
#define UBRRL        *((volatile u8*)0x29)  /*USART Baud Rate Registers UBRRL*/

#endif
