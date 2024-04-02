/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: HAL               **************************/ 
/************************     SWC: SWITCH                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SW_interface.h"

static u8 Local_u8CheckNumber = 0;

u8 SW_u8GetState(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PullType)
{
	u8 SW_State = NOT_PRESSED;
	if(Copy_u8PullType == PullUP)
	{
		DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin, &Local_u8CheckNumber);
		if( Local_u8CheckNumber == 1)
		{
			SW_State =  NOT_PRESSED;
		}
		else
		{
			SW_State =  PRESSED;
		}
	}
	else if(Copy_u8PullType == PullDown)
	{
		DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin, &Local_u8CheckNumber);
		if(Local_u8CheckNumber == 0)
		{
			SW_State =  PRESSED;
		}
		else
		{
			SW_State =  NOT_PRESSED;
		}
	}
	return SW_State;
}

