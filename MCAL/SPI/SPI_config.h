#ifndef  SPI_CONFIG_H_
#define  SPI_CONFIG_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: SPI                  **************************/
/*********************************************************************************/

/* Select Clock Freq for Master:
 * 1- FSYS_Divide_BY_4
 * 2- FSYS_Divide_BY_16
 * 3- FSYS_Divide_BY_64
 * 4- FSYS_Divide_BY_128
 */
#define SCK_FREQ	FSYS_Divide_BY_16

/* Clock Speed:
 * 1- NORMAL
 * 2- DOUBLE
 */
#define CLOCK_SPEED		NORMAL



#endif
