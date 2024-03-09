#ifndef  TWI_INTERFACE_H_
#define  TWI_INTERFACE_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: TWI                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

typedef enum{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,


}TWI_ERROR_STATUS;

/* Pass 0 in the slave address argument if master will not be addressed */
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ERROR_STATUS TWI_SendStartCondition(void);

TWI_ERROR_STATUS TWI_SendRepeatedStart(void);

TWI_ERROR_STATUS TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ERROR_STATUS TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ERROR_STATUS TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ERROR_STATUS TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

void TWI_SendStopCondition(void);

#endif
