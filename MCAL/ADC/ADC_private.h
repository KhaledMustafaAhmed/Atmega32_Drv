#ifndef  ADC_PRIVATE_H_
#define  ADC_PRIVATE_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     SWC: ADC                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

#define AVCC		1
#define AREF		2
#define INTERNAL	3

#define DIV_BY_2	0
#define DIV_BY_4	2
#define DIV_BY_8	3
#define DIV_BY_16	4
#define DIV_BY_32	5
#define DIV_BY_64	6
#define DIV_BY_128	7

#define LEFT_ADJUST		1
#define	RIGHT_ADJUST	2

#define MUX_MASK	0b11100000

#define IDLE	1
#define BUSY	2

#define Chain_ASYNCH	1
#define Single_ASYNCH	2


#endif
