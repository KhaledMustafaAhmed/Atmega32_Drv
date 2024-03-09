#ifndef  TIMER_INTERFACE_H_
#define  TIMER_INTERFACE_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: TIMER                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

/*
TIMER0_voidInit(void):
Description: Initializes the Timer0 module.
Parameters: None.
Return Type: void.
Usage: Call this function to initialize the Timer0 module with predefined settings.
*/
void TIMER0_voidInit(void);

/*
u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void)):
Description: Sets the callback function to be executed when the timer overflows.
Parameters:
Copy_pvCallBackFunc: Pointer to the function that will be called when the timer overflows.
Return Type: u8 (unsigned 8-bit integer).
Usage: Call this function to set the callback function that will be executed when Timer0 overflows. Returns an error status.
*/
u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

/*
void TIMER0_voidSetCompareMatchValue(u8 Copy_u8CompareValue):
Description: set compare match value into OCR register.
Parameters: u8 Copy_u8CompareValue.
Return Type: void.
Usage: Call this function to set compare match value into OCR register.
*/
void TIMER0_voidSetCompareMatchValue(u8 Copy_u8CompareValue);

#endif
