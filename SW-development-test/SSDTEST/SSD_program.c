/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: HAL               **************************/
/************************     SWC: SSD                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static u8 Local_u8SevenSegArr[10] = {
		0b00111111,	/* 0 */
		0b00000110,	/* 1 */
		0b01011011,	/* 2 */
		0b01001111,	/* 3 */
		0b01100110,	/* 4 */
		0b01101101,	/* 5 */
		0b01111101,	/* 6 */
		0b00000111,	/* 7 */
		0b01111111,	/* 8 */
		0b01101111	/* 9 */
} ;



void SSD_u8SetNumber(u8 Copy_u8Number, SSD_t * SSD)
{
	if((SSD ->COM_TYPE) == Anode)
	{

		if((SSD ->EnablePin) == DIO_u8PIN_HIGH)
		{
			DIO_u8SetPortnDirection((SSD ->PORT), DIO_u8PORT_OUTPUT);
			DIO_u8SetPortValue((SSD ->PORT),(~Local_u8SevenSegArr[Copy_u8Number]));
		}

	}
	else
	{

		if((SSD ->EnablePin) == DIO_u8PIN_LOW)
		{
			DIO_u8SetPortnDirection((SSD ->PORT), DIO_u8PORT_OUTPUT);
			DIO_u8SetPortValue((SSD ->PORT),(Local_u8SevenSegArr[Copy_u8Number]));
		}
	}
}
void SSD_u8Enable(SSD_t * SSD)
{
	if((SSD ->COM_TYPE) == Anode)
	{
		DIO_u8SetPinDirection((SSD ->EnablePort), (SSD ->EnablePin), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((SSD ->EnablePort), (SSD ->EnablePin), DIO_u8PIN_HIGH);

	}
	else
	{
		DIO_u8SetPinDirection((SSD ->EnablePort), (SSD ->EnablePin), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((SSD ->EnablePort), (SSD ->EnablePin), DIO_u8PIN_LOW);
	}
}
void SSD_u8Disable(SSD_t * SSD)
{
	if((SSD ->COM_TYPE) == Anode)
	{
		DIO_u8SetPinDirection((SSD ->EnablePort), (SSD ->EnablePin), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((SSD ->EnablePort), (SSD ->EnablePin), DIO_u8PIN_LOW);


	}
	else
	{
		DIO_u8SetPinDirection((SSD ->EnablePort), (SSD ->EnablePin), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((SSD ->EnablePort), (SSD ->EnablePin), DIO_u8PIN_HIGH);
	}
}
