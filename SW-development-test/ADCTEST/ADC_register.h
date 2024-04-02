#ifndef  ADC_REGISTER_H_
#define  ADC_REGISTER_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: ADC                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

/*  ADC Multiplexer Selection Register – ADMUX */
#define ADMUX		*((volatile u8*)0x27)
/* Bit 7,6: – REFS1,REFS0: Reference Selection Bits */
#define ADMUX_REFS1		7
#define ADMUX_REFS0		6
/* Bit 5 – ADLAR: ADC Left Adjust Result */
#define ADMUX_ADLAR		5
/* Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits */
#define ADMUX_MUX4		4
#define ADMUX_MUX3		3
#define ADMUX_MUX2		2
#define ADMUX_MUX1		1
#define ADMUX_MUX0		0
/* ADC Control and Status Register A – ADCSRA */
#define ADCSRA		*((volatile u8*)0x26)
/* Bit 7 – ADEN: ADC Enable */
#define ADCSRA_ADEN		7
/* Bit 6 – ADSC: ADC Start Conversion */
#define ADCSRA_ADSC		6
/* Bit 5 – ADATE: ADC Auto Trigger Enable */
#define ADCSRA_ADATE	5
/* Bit 4 – ADIF: ADC Interrupt Flag */
#define ADCSRA_ADIF		4
/* Bit 3 – ADIE: ADC Interrupt Enable */
#define ADCSRA_ADIE		3
/* Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits */
#define ADCSRA_ADPS2	2
#define ADCSRA_ADPS1	1
#define ADCSRA_ADPS0	0
/* The ADC Data Register – ADCL "Low Byte" and ADCH "High Byte" */
#define ADCH	*((volatile u8*)0x25)
#define ADCL	*((volatile u8*)0x24)

#endif
