#ifndef  TIMER_REGISTER_H_
#define  TIMER_REGISTER_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: TIMER                **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 


/****************************************************************************************
  TIMER0 Registers:
  1- TCCR0 >>  Timer/Counter Control Register
  2- TCNT0 >> Timer/Counter Register
  3- OCR0  >> Output Compare Register
  4- TIMSK >> Timer/Counter Interrupt Mask Register
 *****************************************************************************************/
/* Timer/Counter Control Register – TCCR0  */
#define TCCR0		*((volatile u8 *)0x53)
/* Bit 6, 3 – WGM01:0: Waveform Generation Mode */
#define TCCR0_WGM00		6
#define TCCR0_WGM01		3
/* Bit 5:4 – COM01:0: Compare Match Output Mode */
#define TCCR0_COM01		5
#define TCCR0_COM00		4
/* Bit 2:0 – CS02:0: Clock Select */
#define TCCR0_CS02		2
#define TCCR0_CS01		1
#define TCCR0_CS00		0
/* Timer/Counter Register – TCNT0 */
#define TCNT0		*((volatile u8*)0x52)
/* Output Compare Register – OCR0 */
#define OCR0		*((volatile u8 *)0x5C)
/* Timer/Counter Interrupt Mask Register – TIMSK */
#define TIMSK		*((volatile u8 *)0x59)
/* Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable */
#define TIMSK_OCIE0		1
/* Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable */
#define TIMSK_TOIE0		0

/****************************************************************************************
  TIMER1 Registers:
  1- TCCR0 >>  Timer/Counter Control Register
  2- TCNT0 >> Timer/Counter Register
  3- OCR0  >> Output Compare Register
  4- TIMSK >> Timer/Counter Interrupt Mask Register
 *****************************************************************************************/
#define TCCR1A		*((volatile u8 *)0x4F)
#define TCCR1A_WGM10	0
#define TCCR1A_WGM11	1
#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6

#define TCCR1B		*((volatile u8 *)0x4E) /*  Timer1B Control register  */
#define TCCR1B_WGM13	4
#define TCCR1B_WGM12	3
#define TCCR1B_CS10		0
#define TCCR1B_CS11		1
#define TCCR1B_CS12		2

#define TCCR1B_PRESCALER_MASK		0b11111000



#define ICR1A		*((volatile u16 *)0x46) /*  Timer1 Control register  */

#define OCR1A		*((volatile u8 *)0x4A) /*  Timer1 Control register  */


#endif
