#ifndef  EXTI_REGISTER_H_
#define  EXTI_REGISTER_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: EXTI                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 
/* MCU Control Register – MCUCR:  */
/* MCU Control Register – MCUCR:  */

/* The MCU Control Register contains control bits for interrupt sense control and general MCU functions.*/
#define MCUCR	*((volatile u8*)0x55)
/* Interrupt Sense Control 1 "INT1" Bit 1 and Bit 0 */
#define MCUCR_ISC11	3
#define MCUCR_ISC10	2
/* Interrupt Sense Control 0 "INT0" Bit 1 and Bit 0 */
#define MCUCR_ISC01	1
#define MCUCR_ISC00	0
/* MCU Control and Status Register – MCUCSR control INT2 for interrupt sense control */
#define MCUCSR	*((volatile u8*)0x54)
/* Interrupt Sense Control 2 */
#define MCUCSR_ISC2	6
/* General Interrupt Control Register – GICR  for enable interrupt request */
#define GICR	*((volatile u8*)0x5B)
/* INT1: External Interrupt Request 1 Enable */
#define GICR_INT1	7
/* INT0: External Interrupt Request 0 Enable */
#define GICR_INT0	6
/* INT2: External Interrupt Request 2 Enable */
#define GICR_INT2	5
/* General Interrupt Flag Register – GIFR */
#define GIFR	*((volatile u8*)0x5A)
/* INTF1: External Interrupt Flag 1 */
#define GIFR_INTF1	7
/* INTF0: External Interrupt Flag 0 */
#define GIFR_INTF0	6
/* INTF2: External Interrupt Flag 2 */
#define GIFR_INTF2	5

#endif
