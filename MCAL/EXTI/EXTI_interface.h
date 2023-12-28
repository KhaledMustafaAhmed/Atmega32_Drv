/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: EXTI                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef  EXTI_INTERFACE_H_
#define  EXTI_INTERFACE_H_	

/* 1- LOW LEVEL
 * 2- ON CHANGE
 * 3- FALLING EDGE
 * 4- RISING EDGE
 */
#define LOW_LEVEL		1
#define	ON_CHANGE		2
#define	FALLING_EDGE	3
#define	RISING_EDGE		4


void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);

u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt0Func)(void));
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt0Func)(void));


#endif
