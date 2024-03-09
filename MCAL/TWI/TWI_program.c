
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: TWI                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h" 

#include "TWI_register.h"
#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"

/* Pass 0 in the slave address argument if master will not be addressed */
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/* Set clock Freq to 400kbps */
	/* Set TWBR to 2 */
	TWBR = 2;
	/* Clear two Bits of TWPS */
	CLEAR_BIT(TWSR, TWSR_TWPS0);
	CLEAR_BIT(TWSR, TWSR_TWPS1);
	/* Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
	/* Intialize Node Address */
	if(Copy_u8SlaveAddress != 0)
	{
		TWAR = ( Copy_u8SlaveAddress << 1 );
	}
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/* Intialize Node Address */
	TWAR = Copy_u8SlaveAddress<<1;

	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
}

TWI_ERROR_STATUS TWI_SendStartCondition(void)
{
	TWI_ERROR_STATUS Local_ErrorStatus = NoError;

	/* Send start Condition on the Bus */
	SET_BIT(TWCR, TWCR_TWSTA);

	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if((TWSR & 0xF8) != START_ACK)
		Local_ErrorStatus = StartConditionError;

	return Local_ErrorStatus;
}

TWI_ERROR_STATUS TWI_SendRepeatedStart(void)
{
	TWI_ERROR_STATUS Local_ErrorStatus = NoError;

	/* Send start Condition on the Bus */
	SET_BIT(TWCR, TWCR_TWSTA);

	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if((TWSR & 0xF8) != REP_START_ACK)
		Local_ErrorStatus = RepeatedStartError;

	return Local_ErrorStatus;
}

TWI_ERROR_STATUS TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ERROR_STATUS Local_ErrorStatus = NoError;

	/* Clear Start Condition Bit */
	CLEAR_BIT(TWCR, TWCR_TWSTA);

	/* Set the slave address in the 7 MSB in the data register */
	TWDR = (Copy_u8SlaveAddress<<1);
	CLEAR_BIT(TWDR, 0); /* For Write request */

	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if((TWSR & 0xF8) != SLAVE_ADD_AND_W_ACK)
		Local_ErrorStatus = SlaveAddressWithWriteError;
	return Local_ErrorStatus;
}

TWI_ERROR_STATUS TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ERROR_STATUS Local_ErrorStatus = NoError;

	/* Clear Start Condition Bit */
	CLEAR_BIT(TWCR, TWCR_TWSTA);

	/* Set the slave address in the 7 MSB in the data register */
	TWDR = (Copy_u8SlaveAddress<<1);
	SET_BIT(TWDR, 0); /* For Read request */

	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if((TWSR & 0xF8) != SLAVE_ADD_AND_R_ACK)
		Local_ErrorStatus = SlaveAddressWithReadError;

	return Local_ErrorStatus;
}

TWI_ERROR_STATUS TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ERROR_STATUS Local_ErrorStatus = NoError;

	/* Write data into data register */
	TWDR = Copy_u8DataByte;
	/* Clear interrupt flag   */
	SET_BIT(TWCR, TWCR_TWIE);

	while(GET_BIT(TWCR, TWCR_TWIE) == 0);

	if((TWSR & 0xF8) != MSTR_W_BYTE_ACK)
		Local_ErrorStatus = MasterWriteByteError;

	return Local_ErrorStatus;
}

TWI_ERROR_STATUS TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ERROR_STATUS Local_ErrorStatus = NoError;

	/* Enable master generate ACK bit */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Clear interrupt flag   */
	SET_BIT(TWCR, TWCR_TWIE);

	while(GET_BIT(TWCR, TWCR_TWIE) == 0);

	if((TWSR & 0xF8) != MSTR_R_BYTE_WITH_ACK)
		Local_ErrorStatus = MasterReadByteError;
	else
		*Copy_pu8DataByte = TWDR ;

	return Local_ErrorStatus;
}

void TWI_SendStopCondition(void)
{
	/* Send start Condition on the Bus */
	SET_BIT(TWCR, TWCR_TWSTO);

	/* Clear the interrupt flag */
	SET_BIT(TWCR, TWCR_TWINT);
}
