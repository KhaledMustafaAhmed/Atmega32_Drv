#ifndef  SPI_REGISTER_H_
#define  SPI_REGISTER_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: SPI                  **************************/ 
/*********************************************************************************/ 

#define SPCR		*((volatile u8*)0x2D)	/* SPI Control Register – SPCR */
#define SPCR_SPIE	7						/* Bit 7 – SPIE: SPI Interrupt Enable */
#define SPCR_SPE	6						/* Bit 6 – SPE: SPI Enable */
#define SPCR_DORD	5						/* Bit 5 – DORD: Data Order */
#define SPCR_MSTR	4						/* Bit 4 – MSTR: Master/Slave Select */
#define SPCR_CPOL	3						/* Bit 3 – CPOL: Clock Polarity */
#define SPCR_CPHA	2						/* Bit 2 – CPHA: Clock Phase */
#define SPCR_SPR1	1						/* Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0 */
#define SPCR_SPR0	0						/* Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0 */

#define SPSR		*((volatile u8*)0x2E)	/* SPI Status Register – SPSR */
#define SPSR_SPIF	7						/* Bit 7 – SPIF: SPI Interrupt Flag */
#define SPSR_WCOL	6						/* Bit 6 – WCOL: Write COLlision Flag */
#define SPSR_SPI2X	0						/* Bit 0 – SPI2X: Double SPI Speed Bit */

#define SPDR		*((volatile u8*)0x2F)	/* SPI Data Register – SPDR */







#endif
