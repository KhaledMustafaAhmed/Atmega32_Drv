/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: HAL               **************************/ 
/************************     SWC: LED                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"

void LED_u8TurnOn(LED_t * LED)
{
	if((LED ->CONNECT_TYPE == SOURCE))
	{
		DIO_u8SetPinDirection((LED ->PORT), (LED ->PIN), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((LED ->PORT), (LED ->PIN), DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_u8SetPinDirection((LED ->PORT), (LED ->PIN), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((LED ->PORT), (LED ->PIN), DIO_u8PIN_LOW);
	}
}
void LED_u8TurnOff(LED_t * LED)
{
	if((LED ->CONNECT_TYPE == SOURCE))
	{

		DIO_u8SetPinValue((LED ->PORT), (LED ->PIN), DIO_u8PIN_LOW);
	}
	else
	{

		DIO_u8SetPinValue((LED ->PORT), (LED ->PIN), DIO_u8PIN_HIGH);
	}
}

