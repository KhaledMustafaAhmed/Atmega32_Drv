/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: HAL               **************************/ 
/************************     SWC: CLCD                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

/* Preprocessor file guard */
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);
/* CLCD_voidSendCommand: ready to send command to LCD which means [RS = 0 && RW = 0] each for write  */


void CLCD_voidSendData(u8 Copy_u8Data);
/* CLCD_voidSendData:
  ready to display data [only char 8 bits between ' ' ]on LCD which means [RS = 1 && RW = 0] each for write
 */

void CLCD_voidInit(void);
/* CLCD_voidInit: This function must be invoke to initialize LCD before start any action on it.  */


void CLCD_voidSendString(const char * Copy_pcString);
/* CLCD_voidSendString: This function must be invoke if i want to display a string between " ". */


void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
/* CLCD_voidGoToXY: This function must be invoke if i want to determine on a specific position on LCD.
 * /* End of the function, LCD now on DDRAM and ready to invoke sendData function to display patterns. */

void CLCD_voidWriteSpecialCharacter(u8 * Copy_puPattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);
/* CLCD_voidWriteSpecialCharacter: if i want to display a special characters, this function must invoke. */

#endif
