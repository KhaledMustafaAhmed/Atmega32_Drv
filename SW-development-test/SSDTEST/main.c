/*
 * main.c

 *
 *  Created on: Oct 30, 2023
 *      Author: yasse
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "DIO_interface.h"
#include "SSD_interface.h"



void main (void)
{

	SSD_t SSD_1 = {Anode, DIO_u8PORTA, DIO_u8PORTC, DIO_u8PIN1};

	SSD_u8Enable(&SSD_1);
	SSD_u8SetNumber(8 , &SSD_1);



}

