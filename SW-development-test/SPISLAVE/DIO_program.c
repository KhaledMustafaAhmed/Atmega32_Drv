/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: DIO                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

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
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_u8Pin<= DIO_u8PIN7)
	{
		if(Copy_u8Direction  == DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: CLEAR_BIT(DDRA, Copy_u8Pin); break;
			case DIO_u8PORTB: CLEAR_BIT(DDRB, Copy_u8Pin); break;
			case DIO_u8PORTC: CLEAR_BIT(DDRC, Copy_u8Pin); break;
			case DIO_u8PORTD: CLEAR_BIT(DDRD, Copy_u8Pin); break;
			default:Local_u8ErrorState = 1;
			}
		}
		else if(Copy_u8Direction  == DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(DDRA, Copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(DDRB, Copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(DDRC, Copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(DDRD, Copy_u8Pin); break;
			default:Local_u8ErrorState = 1;
			}
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}


	return Local_u8ErrorState;
}

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
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = 0;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: DDRA = Copy_u8Direction; break;
	case DIO_u8PORTB: DDRB = Copy_u8Direction; break;
	case DIO_u8PORTC: DDRC = Copy_u8Direction; break;
	case DIO_u8PORTD: DDRD = Copy_u8Direction; break;
	default: Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}

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
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_u8Pin<= DIO_u8PIN7)
	{
		if(Copy_u8Value  == DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: CLEAR_BIT(PORTA, Copy_u8Pin); break;
			case DIO_u8PORTB: CLEAR_BIT(PORTB, Copy_u8Pin); break;
			case DIO_u8PORTC: CLEAR_BIT(PORTC, Copy_u8Pin); break;
			case DIO_u8PORTD: CLEAR_BIT(PORTD, Copy_u8Pin); break;
			default:Local_u8ErrorState = 1;
			}
		}
		else if(Copy_u8Value  == DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(PORTA, Copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(PORTB, Copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(PORTC, Copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(PORTD, Copy_u8Pin); break;
			default:Local_u8ErrorState = 1;
			}
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}


	return Local_u8ErrorState;
}

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
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: PORTA = Copy_u8Value; break;
	case DIO_u8PORTB: PORTB = Copy_u8Value; break;
	case DIO_u8PORTC: PORTC = Copy_u8Value; break;
	case DIO_u8PORTD: PORTD = Copy_u8Value; break;
	default: Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}

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
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_pu8Value != (NULL) && Copy_u8Pin<= DIO_u8PIN7)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin);  break;
		case DIO_u8PORTB: *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin); break;
		case DIO_u8PORTC: *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin); break;
		case DIO_u8PORTD: *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin); break;
		default:Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}
