/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: DIO                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef  DIO_INTERFACE_H_
#define  DIO_INTERFACE_H_	

/* Define the pin directions  */
#define DIO_u8PIN_OUTPUT	1
#define DIO_u8PIN_INPUT		0

/* Define the pin values  */
#define DIO_u8PIN_HIGH		1
#define DIO_u8PIN_LOW		0

/* Define the port directions  */
#define DIO_u8PORT_OUTPUT		0xff
#define DIO_u8PORT_INPUT		0

/* Define the port values  */
#define DIO_u8PORT_HIGH			0xff
#define DIO_u8PORT_LOW			0

/* Define the port names */
#define DIO_u8PORTA			0
#define DIO_u8PORTB			1
#define DIO_u8PORTC			2
#define DIO_u8PORTD			3

/* Define the pins numbers */
#define DIO_u8PIN0			0
#define DIO_u8PIN1			1
#define DIO_u8PIN2			2
#define DIO_u8PIN3			3
#define DIO_u8PIN4			4
#define DIO_u8PIN5			5
#define DIO_u8PIN6			6
#define DIO_u8PIN7			7


/*
 * Function Name: DIO_u8SetPinDirection
 * Function Parameters:
 *      1. u8 Copy_u8Port - The desired port to configure (A, B, C, or D).
 *      2. u8 Copy_u8Pin - The specific pin within the chosen port.
 *      3. u8 Copy_u8Direction - The desired direction for the pin (Input or Output).
 * Function Return Type: u8
 * Function Description:
 *      This function configures the direction of a specific pin on a chosen port.
 *      Parameters:
 *          - Copy_u8Port: The port to configure (A, B, C, or D).
 *          - Copy_u8Pin: The specific pin within the chosen port.
 *          - Copy_u8Direction: The desired direction for the pin (Input or Output).
 *      Return:
 *          - Error state:
 *              - 0: Function executed successfully.
 *              - 1: An error occurred during execution.
 */
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/*
 * Function Name: DIO_u8SetPortDirection
 * Function Parameters:
 *      1. u8 Copy_u8Port - The desired port to configure (A, B, C, or D).
 *      2. u8 Copy_u8Direction - The desired direction for the port (Input or Output).
 * Function Return Type: u8
 * Function Description:
 *      This function configures the direction of a specific pin on a chosen port.
 *      Parameters:
 *          - Copy_u8Port: The port to configure (A, B, C, or D).
 *          - Copy_u8Direction: The desired direction for the port (Input or Output).
 *      Return:
 *          - Error state:
 *              - 0: Function executed successfully.
 *              - 1: An error occurred during execution.
 */
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

/*
 * Function Name: DIO_u8SetPinValue
 * Function Parameters:
 *      1. u8 Copy_u8Port - The desired port to configure (A, B, C, or D).
 *      2. u8 Copy_u8Pin - The specific pin within the chosen port.
 *      3. u8 Copy_u8Value - The desired value for the pin (High or Low).
 *
 * Function Return Type: u8
 * Function Description:
 *      This function configures the Value of a specific pin on a chosen port.
 *      Parameters:
 *          - Copy_u8Port: The port to configure (A, B, C, or D).
 *          - Copy_u8Pin: The specific pin within the chosen port.
 *          - Copy_u8Value: The desired value for the pin (High or Low).
 *      Return:
 *          - Error state:
 *              - 0: Function executed successfully.
 *              - 1: An error occurred during execution.
 */
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/*
 * Function Name: DIO_u8SetPortValue
 * Function Parameters:
 *      1. u8 Copy_u8Port - The desired port to configure (A, B, C, or D).
 *      2. u8 Copy_u8Direction - The desired value for the port (High or Low).
 * Function Return Type: u8
 * Function Description:
 *      This function configures the value of a specific pin on a chosen port.
 *      Parameters:
 *          - Copy_u8Port: The port to configure (A, B, C, or D).
 *          - Copy_u8Direction: The desired value for the port (High or Low).
 *      Return:
 *          - Error state:
 *              - 0: Function executed successfully.
 *              - 1: An error occurred during execution.
 */
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/*
 * Function Name: DIO_u8GetPinValue
 * Function Parameters:
 *      1. u8 Copy_u8Port - The desired port to read the value (A, B, C, or D).
 *      2. u8 Copy_u8Pin - The specific pin within the chosen port.
 *      3. u8 *Copy_pu8Value - Pointer to a u8 variable to store the read value of the pin.
 * Function Return Type: u8
 * Function Description:
 *      This function reads the value of a specific pin on a chosen port.
 *      Parameters:
 *          - Copy_u8Port: The port from which to read the value (A, B, C, or D).
 *          - Copy_u8Pin: The specific pin within the chosen port.
 *          - u8 *Copy_pu8Value: Pointer to a u8 variable to store the read value of the pin.
 *      Return:
 *          - Error state:
 *              - 0: Function executed successfully.
 *              - 1: An error occurred during execution.
 */
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value);



#endif
