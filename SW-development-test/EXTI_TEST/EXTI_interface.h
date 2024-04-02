#ifndef  EXTI_INTERFACE_H_
#define  EXTI_INTERFACE_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: EXTI                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

void EXTI_INT0Init(void);

void EXTI_INT1Init(void);

void EXTI_INT2Init(void);

u8 EXTI_INT0SetCallBackFunc(void(*pvINT0func)(void));

u8 EXTI_INT1SetCallBackFunc(void(*pvINT1func)(void));

u8 EXTI_INT2SetCallBackFunc(void(*pvINT2func)(void));


#endif
