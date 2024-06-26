#ifndef  RTOS_INTERFACE_H_
#define  RTOS_INTERFACE_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: RTOS               **************************/ 
/************************     SWC: RTOS                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

void RTOS_voidStart(void);

void RTOS_CreateTask(u8 Priority, u16 periodictiy, void(*ptrFunc)(void));


#endif
