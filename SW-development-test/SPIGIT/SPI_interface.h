#ifndef  SPI_INTERFACE_H_
#define  SPI_INTERFACE_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: SPI                  **************************/ 
/*********************************************************************************/ 

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

u8 SPI_u8TranscieveSynch(u8 SendingData, u8 *SamplingData);

u8 SPI_u8TranscieveASynch(u8 SendingData, u8 *SamplingData, void(*CallBackNotificationFunc)(void));



#endif
