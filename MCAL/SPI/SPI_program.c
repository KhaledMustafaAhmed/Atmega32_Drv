
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: SPI                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h" 

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_register.h"

void SPI_voidMasterInit(void)
{
	/* Master INIT */
	SET_BIT(SPCR,SPCR_MSTR);
	/* Clock  Prescaler divide by 16 */
	SET_BIT(SPCR,SPCR_SPR0);
	CLEAR_BIT(SPCR,SPCR_SPR1);
	CLEAR_BIT(SPSR,SPSR_SPI2X);
	/* SPI Enable */
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSlaveInit(void)
{
	/* Slave INIT */
	CLEAR_BIT(SPCR,SPCR_MSTR);
	/* SPI Enable */
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Transcieve(u8 Data)
{
	/* Send the Data */
	SPDR = Data;
	/* Busy waiting until transfer is complete */
	while(GET_BIT(SPSR,SPSR_SPIF) != 1);
	/* GET the exchange Data */
	return SPDR;
}
