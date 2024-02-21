#ifndef  TIMER0_REGISTER_H_
#define  TIMER0_REGISTER_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: TIMER0                **************************/
/************************     Version: 1                 **************************/
/*********************************************************************************/
/*********************************************************************************/ 

/*  
    TIMER0 resisters: 
    1- Timer/Counter Control Register – TCCR0 
        Bit 7 – FOC0: Force Output Compare 
             A FOC0 strobe will not generate any interrupt, nor will it clear the timer in CTC mode using OCR0 as TOP.

        Bit 6, 3 – WGM01:0: Waveform Generation Mode
            These bits control the counting sequence of the counter, the source for the maximum 
            (TOP) counter value, and what type of Waveform Generation to be used.

        Bit 5:4 – COM01:0: Compare Match Output Mode   
            These bits control the Output Compare pin (OC0) behavior. If one or both of the
            COM01:0 bits are set, the OC0 output overrides the normal port functionality of the I/O
            pin it is connected to. When OC0 is connected to the pin, the function of the COM01:0 bits depends on the
            WGM01:0 bit setting

        Bit 2:0 – CS02:0: Clock Select
            The three Clock Select bits select the clock source to be used by the Timer/Counter.    

    2- Timer/Counter Register – TCNT0 
        The Timer/Counter Register gives direct access, both for read and write operations, to
        the Timer/Counter unit 8-bit counter. Writing to the TCNT0 Register blocks (removes)
        the compare match on the following timer clock. Modifying the counter (TCNT0) while
        the counter is running, introduces a risk of missing a compare match between TCNT0
        and the OCR0 Register. 

    3- Output Compare Register – OCR0
        The Output Compare Register contains an 8-bit value that is continuously compared
        with the counter value (TCNT0). A match can be used to generate an output compare
        interrupt, or to generate a waveform output on the OC0 pin.       

    4- Timer/Counter Interrupt Mask Register – TIMSK
        Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
            When the OCIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
            Timer/Counter0 Compare Match interrupt is enabled. The corresponding interrupt is
            executed if a compare match in Timer/Counter0 occurs, i.e., when the OCF0 bit is set in
            the Timer/Counter Interrupt Flag Register – TIFR.  
        Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
            When the TOIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
            Timer/Counter0 Overflow interrupt is enabled. The corresponding interrupt is executed if
            an overflow in Timer/Counter0 occurs, i.e., when the TOV0 bit is set in the
            Timer/Counter Interrupt Flag Register – TIFR.

    5- Timer/Counter Interrupt Flag Register – TIFR  
        Bit 1 – OCF0: Output Compare Flag 0
        Bit 0 – TOV0: Timer/Counter0 Overflow Flag            
 */
#define TCCR0          *((volatile u8 *)0x53)    /* Timer/Counter Control Register – TCCR0  */
#define TCCR0_FOC0     7                         /* Bit 7 – FOC0: Force Output Compare */
#define TCCR0_WGM00    6		                 /* WGM01:0: Waveform Generation Mode */
#define TCCR0_WGM01    3                         /* WGM01:0: Waveform Generation Mode */
#define TCCR0_COM00	   4	                     /* Compare Match Output Mode  */
#define TCCR0_COM01	   5                         /* Compare Match Output Mode  */
#define TCCR0_CS02	   2		                 /* Clock Select:  */
#define TCCR0_CS01	   1		                 /* Clock Select: prescaler */
#define TCCR0_CS00     0		                 /* Clock Select: prescaler */
#define TCNT0          *((volatile u8 *)0x52)    /* Timer/Counter Register – TCNT0 */   
#define OCR0		   *((volatile u8 *)0x5C)    /* Output Compare Register – OCR0 */
#define TIMSK		   *((volatile u8 *)0x59)    /* Timer/Counter Interrupt Mask Register – TIMSK */
#define TIMSK_TOIE	   0				         /*  Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable */
#define TIMSK_OCIE0	   1				         /*  Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable */

#endif
