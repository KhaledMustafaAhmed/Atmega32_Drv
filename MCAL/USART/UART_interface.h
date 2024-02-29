#ifndef  UART_INTERFACE_H_
#define  UART_INTERFACE_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/*********************************************************************************/ 

void USART_voidInit(void);

u8 USART_voidSendCharSynch(u8 data);

u8 USART_voidSendCharAsynch(u8 Data, void(*CallbackFunctionNotification)(void));

u8 USART_SendStringASynch(const char *String ,void (*Copy_pvCallBackFunc)(void));

u8 USART_RecieveCharSynch(u8*ReadingData);

u8 USART_RecieveCharASynch(u8*ReadingData, void (*Copy_pvCallBackFunc)(void));

u8 USART_RecieveBufferASynch(u8*ReadingData, u8 BufferSize ,void (*Copy_pvCallBackFunc)(void));


#endif
