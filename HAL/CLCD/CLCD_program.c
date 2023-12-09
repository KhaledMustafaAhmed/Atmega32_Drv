/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: HAL               **************************/ 
/************************     SWC: CLCD                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"


/*
 * Function Name: CLCD_voidSendCommand
 * Function Parameter: u8 Copy_u8Command
 * Function Return Type: void
 * Function Description: ready to send command to LCD which means [RS = 0 && RW = 0] each for write.
 */
void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/* Set RS PIN to low for Command */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
	/* Set R/W PIN to low for Write "Active Low" */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	/* Set Command to Data Pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	/* Send Enable Pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);

}


/*
 * Function Name: CLCD_voidSendData
 * Function Parameter: u8 Copy_u8Data
 * Function Return Type: void
 * Function Description: ready to display data [only char 8 bits between ' ' ]
 * 						 on LCD which means [RS = 1 && RW = 0] each for write.
 */
void CLCD_voidSendData(u8 Copy_u8Data)
{
	/* Set RS PIN to High for Data */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);
	/* Set R/W PIN to low for Write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	/* Set Data to Data Pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);
	/* Send Enable Pulls */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);

}


/*
 * Function Name: CLCD_voidInit
 * Function Parameter: void
 * Function Return Type: void
 * Function Description: Initializes the LCD for operation.
 * NOTE: This function must be invoke to initialize LCD before start any action on it.
 */
void CLCD_voidInit(void)
{
	/* Wait for more that 30ms */
	_delay_ms(40);

	/* Function set command: 2 lines, 5*8 Font Size */
	CLCD_voidSendCommand(0b00111000);

	/* Display Control command: Display ON/OFF:[ Display ON ] / [ Cursor & Blink OFF ] */
	CLCD_voidSendCommand(0b00001100);

	/* Display clear command: Display */
	CLCD_voidSendCommand(0b00000001);
}


/*
 * Function Name: CLCD_voidSendString
 * Function Parameter: const char * Copy_pcString
 * Function Return Type: void
 * Function Description: This function must be invoke if i want to display a string between " "
 * 						 Ready to display string on LCD Display.
 */
void CLCD_voidSendString(const char * Copy_pcString)
{
	u8 Local_u8counter = 0;
	while(Copy_pcString[Local_u8counter] != '\0')
	{
		/* Set Data to Data Pins */
		CLCD_voidSendData(Copy_pcString[Local_u8counter]);
		Local_u8counter++;
	}
}


/*
 * Function Name: CLCD_voidGoToXY
 * Function Parameter: 1- u8 Copy_u8XPos
 * 					   2- u8 Copy_u8YPos
 * Function Return Type: void
 * Function Description: This function must be invoke if i want to determine on a specific position on LCD.
 * NOTE: End of the function, LCD now on DDRAM and ready to invoke sendData function to display patterns.
 */
void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos == 0)
	{
		/* Location is at first line */
		Local_u8Address = Copy_u8YPos;
	}
	else if(Copy_u8XPos == 1)
	{
		/* Location is at second line */
		Local_u8Address = Copy_u8YPos + 0x40;
	}
	CLCD_voidSendCommand(Local_u8Address + 128);
}

/*
 * Function Name: CLCD_voidWriteSpecialCharacter
 * Function Parameter: 1- u8 * Copy_puPattern
 * 					   2- u8 Copy_u8PatternNumber
 * 					   3- u8 Copy_u8XPos
 * 					   4- u8 Copy_u8YPos
 * Function Return Type: void
 * Function Description: This function must be invoke if i want to write a special character and display it on LCD.
 */
void CLCD_voidWriteSpecialCharacter(u8 * Copy_puPattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress = 0;
	u8 Local_u8CounterLoop = 0;
	/* CGRAM Address */
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;

	CLCD_voidSendCommand(Local_u8CGRAMAddress + 64);
	/* Write The Pattern into CGRAM */
	for(Local_u8CounterLoop = 0; Local_u8CounterLoop <8; Local_u8CounterLoop++ )
	{
		CLCD_voidSendData(Copy_puPattern[Local_u8CounterLoop]);
	}
	/* Go back to DDRAM to display the pattern */
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos );
	/* Display the pattern number written in CG RAM on LCD */
	CLCD_voidSendData(Copy_u8PatternNumber);
}
