#ifndef  TWI_REGISTER_H_
#define  TWI_REGISTER_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: TWI                  **************************/
/*********************************************************************************/

#define TWCR		*((volatile u8*)0x56)	/* TWI Control Register – TWCR */
#define TWCR_TWINT	7 						/* Bit 7 – TWINT: TWI Interrupt Flag */
#define TWCR_TWEA	6 						/* Bit 6 – TWEA: TWI Enable Acknowledge Bit */
#define TWCR_TWSTA	5 						/* Bit 5 – TWSTA: TWI START Condition Bit */
#define TWCR_TWSTO	4 						/* Bit 4 – TWSTO: TWI STOP Condition Bit */
#define TWCR_TWWC	3 						/* Bit 3 – TWWC: TWI Write Collision Flag */
#define TWCR_TWEN	2 						/* Bit 2 – TWEN: TWI Enable Bit */
#define TWCR_TWIE	0 						/* Bit 0 – TWIE: TWI Interrupt Enable */

#define TWDR		*((volatile u8*)0x23)	/*  TWI Data Register – TWDR */

#define TWAR		*((volatile u8*)0x22) 	/*  TWI (Slave) Address Register – TWAR */
#define TWAR_TWGCE	0						/* 	Bit 0 – TWGCE: TWI General Call Recognition Enable Bit */

#define TWSR		*((volatile u8*)0x21)	/* TWI Status Register – TWSR */
#define TWSR_TWPS1	1 						/* Bits 1 – TWPS: TWI Prescaler Bits */
#define TWSR_TWPS0	0 						/* Bits 0 – TWPS: TWI Prescaler Bits */

#define TWBR		*((volatile u8*)0x20)	/* TWI Bit Rate Register – TWBR */

#endif
