#ifndef  SPI_PRIVATE_H_
#define  SPI_PRIVATE_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: SPI                  **************************/
/*********************************************************************************/

/* Options for Clock Rate: */
#define FSYS_Divide_BY_4	1
#define FSYS_Divide_BY_16	2
#define FSYS_Divide_BY_64	3
#define FSYS_Divide_BY_128	4

#define NORMAL	1
#define DOUBLE	2

#define IDLE	1
#define BUSY	2
/* ISR For transfer Complete */
void __vector_12(void) __attribute__((signal));




#endif
