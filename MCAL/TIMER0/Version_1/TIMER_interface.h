#ifndef  TIMER0_INTERFACE_H_
#define  TIMER0_INTERFACE_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     Version: 1                **************************/
/*********************************************************************************/

/*  
Fuction Name: TIMER0_Init
Fuction Description: initialize timer0 with the configuration given in the config.h file.
Function parameter: None
Function Return Value: None
*/
void TIMER0_Init(void);
/*  
Fuction Name: TIMER0_Start
Fuction Description: Start a timer and execute the notification after req time.
Function parameter: u32 req time in microseconds , callback function
Function Return Value: None
hint: interrupt Must be enable before calling this functions using
void TIMER0_EnOVFNotification(void);
*/
u8 TIMER0_Start(u32 reqTime , void(*CallBackFuncNotification)(void));
/* this function enable the overflow interrupt */
void TIMER0_EnOVFNotification(void);

/* this function disable overflow interrupt */
void TIMER0_DISOVFNotification(void);


#endif
