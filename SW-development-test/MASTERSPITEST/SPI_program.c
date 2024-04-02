
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: SPI                  **************************/ 
/*********************************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h" 

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_register.h"

#define TIMEOUT	50000
static void(*CallBackFunc)(void) = NULL;
static u8 * Global_Sample_Data;

static u8 SPI_State = IDLE;

void SPI_voidMasterInit(void)
{
	/* Set MCU as Master in Network */
	SET_BIT(SPCR, SPCR_MSTR);

	/* Select Clock Polarity: 0 >> Leading Edge will be a rising edge */
	CLEAR_BIT(SPCR, SPCR_CPOL);

	/* Select Clock Phase: 0 >> Leading Edge will be Sample  */
	CLEAR_BIT(SPCR, SPCR_CPHA);

	/* Select Data order: 1 >> LSB of the data word is transmitted first */
	SET_BIT(SPCR, SPCR_DORD);

	/* Clock speed: */
#if CLOCK_SPEED == NORMAL
	CLEAR_BIT(SPSR, SPSR_SPI2X);
#elif CLOCK_SPEED == DOUBLE
	SET_BIT(SPSR, SPSR_SPI2X);
#else
#error "Wrong Clock Speed Configuration"
#endif

	/* SCK Freq: */
#if SCK_FREQ == FSYS_Divide_BY_4
	CLEAR_BIT(SPCR, SPCR_SPR1);
	CLEAR_BIT(SPCR, SPCR_SPR0);
#elif SCK_FREQ == FSYS_Divide_BY_16
	CLEAR_BIT(SPCR, SPCR_SPR1);
	SET_BIT(SPCR, SPCR_SPR0);
#elif SCK_FREQ == FSYS_Divide_BY_64
	SET_BIT(SPCR, SPCR_SPR1);
	CLEAR_BIT(SPCR, SPCR_SPR0);
#elif SCK_FREQ == FSYS_Divide_BY_128
	SET_BIT(SPCR, SPCR_SPR1);
	SET_BIT(SPCR, SPCR_SPR0);
#else
#error "Wrong SCK Freq Configuration"
#endif

	/* Enable SPI */
	SET_BIT(SPCR, SPCR_SPE);
}

void SPI_voidSlaveInit(void)
{
	/* Set MCU as Master in Network */
	CLEAR_BIT(SPCR, SPCR_MSTR);

	/* Enable SPI */
	SET_BIT(SPCR, SPCR_SPE);
}


u8 SPI_u8TranscieveSynch(u8 SendingData, u8 *SamplingData)
{
	u8 Local_u8ErrorState = OK;
	u8 Local_u8Counter = 0;
	/* Send Data */
	SPDR = SendingData;

	/* Wait for complete Sending Flag */
	while((GET_BIT(SPSR, SPSR_SPIF) != 1) && (Local_u8Counter != TIMEOUT))
		Local_u8Counter++;

	if(Local_u8Counter != TIMEOUT)
	{
		*SamplingData = SPDR;
	}
	else
	{
		Local_u8ErrorState = NOT_OK;
	}

	return Local_u8ErrorState;
}


u8 SPI_u8TranscieveASynch(u8 SendingData, u8 *SamplingData, void(*CallBackNotificationFunc)(void))
{

	u8 Local_u8ErrorState = OK;
	if(SPI_State == IDLE)
	{
		if(CallBackNotificationFunc !=NULL)
		{
			SPI_State = BUSY;
			CallBackFunc = CallBackNotificationFunc;
			Global_Sample_Data = SamplingData;
			SPDR = SendingData;
			SET_BIT(SPCR, SPCR_SPIE);
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}
	}

	return Local_u8ErrorState;
}


void __vector_12(void)
{
	if(CallBackFunc != NULL)
	{
		*Global_Sample_Data = SPDR;
		SPI_State = IDLE;
		CallBackFunc();
		CLEAR_BIT(SPCR, SPCR_SPIE);
	}
	else
	{
		/* Do nothing */
	}
}
