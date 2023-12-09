/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: HAL               	**************************/
/************************     SWC: CLCD                	**************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

/* Preprocessor file guard */
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


/*
 * Function Name: CLCD_voidSendCommand
 * Function Parameter: u8 Copy_u8Command
 * Function Return Type: void
 * Function Description: ready to send command to LCD which means [RS = 0 && RW = 0] each for write.
 */
void CLCD_voidSendCommand(u8 Copy_u8Command);


/*
 * Function Name: CLCD_voidSendData
 * Function Parameter: u8 Copy_u8Data
 * Function Return Type: void
 * Function Description: ready to display data [only char 8 bits between ' ' ]
 * 						 on LCD which means [RS = 1 && RW = 0] each for write.
 */
void CLCD_voidSendData(u8 Copy_u8Data);


/*
 * Function Name: CLCD_voidInit
 * Function Parameter: void
 * Function Return Type: void
 * Function Description: Initializes the LCD for operation.
 * NOTE: This function must be invoke to initialize LCD before start any action on it.
 */
void CLCD_voidInit(void);


/*
 * Function Name: CLCD_voidSendString
 * Function Parameter: const char * Copy_pcString
 * Function Return Type: void
 * Function Description: This function must be invoke if i want to display a string between " "
 * 						 Ready to display string on LCD Display.
 */
void CLCD_voidSendString(const char * Copy_pcString);


/*
 * Function Name: CLCD_voidGoToXY
 * Function Parameter: 1- u8 Copy_u8XPos
 * 					   2- u8 Copy_u8YPos
 * Function Return Type: void
 * Function Description: This function must be invoke if i want to determine on a specific position on LCD.
 * NOTE: End of the function, LCD now on DDRAM and ready to invoke sendData function to display patterns.
 */
void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);


/*
 * Function Name: CLCD_voidWriteSpecialCharacter
 * Function Parameter: 1- u8 * Copy_puPattern
 * 					   2- u8 Copy_u8PatternNumber
 * 					   3- u8 Copy_u8XPos
 * 					   4- u8 Copy_u8YPos
 * Function Return Type: void
 * Function Description: This function must be invoke if i want to write a special character and display it on LCD.
 */
void CLCD_voidWriteSpecialCharacter(u8 * Copy_puPattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);

#endif
