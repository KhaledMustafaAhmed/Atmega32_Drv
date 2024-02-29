/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: UART                **************************/
/*********************************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h" 

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
#include "UART_register.h"

#define TIMEOUT	50000
static u8 USART_State = IDlE;
static u8 GlobalCounter = 0;
static u8 USART_ISRTransmit_Source ;

static void(*CallbackFunc)(void) = NULL;
static char *USART_String = NULL;
static u8*USART_Buffer = NULL;
static u8 USART_Buffer_Size ;

static u8 GlobalDataSend;
static u8 *GlobalDataRecieve;



void USART_voidInit(void)
{
	u8 Local_u8UCSRCTest = 0;
	u8 Local_u8UBRRHTest = 0;
	u16 Local_u16UBRR;
	/* To access UCSRC Make Bit 7 Equal 1 */
	SET_BIT(Local_u8UCSRCTest, UCSRC_URSEL);
#if USART_MODE == ASYNCHRONOUS
	CLEAR_BIT(Local_u8UCSRCTest, UCSRC_UMSEL);
#else
#error "Wrong USART_MODE Configurations"
#endif


#if USART_PARITY == EVEN_PARITYY
	SET_BIT(Local_u8UCSRCTest, UCSRC_UPM1);
	CLEAR_BIT(Local_u8UCSRCTest, UCSRC_UPM0);
#elif USART_PARITY == ODD_PARITYY
	SET_BIT(Local_u8UCSRCTest, UCSRC_UPM1);
	SET_BIT(Local_u8UCSRCTest, UCSRC_UPM0);
#elif USART_PARITY == DISABLE_PARITY
	CLEAR_BIT(Local_u8UCSRCTest, UCSRC_UPM1);
	CLEAR_BIT(Local_u8UCSRCTest, UCSRC_UPM0);
#else
#error "Wrong USART_PARITY Configurations"
#endif

#if STOP_BITS == ONE
	CLEAR_BIT(Local_u8UCSRCTest, UCSRC_USBS);
#elif STOP_BITS == TWO
	SET_BIT(Local_u8UCSRCTest, UCSRC_USBS);
#else
#error "Wrong STOP_BITS Configurations "
#endif

	/* Char Size is 8 BIT */
	SET_BIT(Local_u8UCSRCTest, UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCTest, UCSRC_UCSZ0);
	CLEAR_BIT(UCSRB, UCSRB_UCSZ2);

	UCSRC = Local_u8UCSRCTest;

#if USART_SPEED == ASYNCH_NORMAL
	CLEAR_BIT(UCSRA, UCSRA_U2X);
	Local_u16UBRR = (FSYS / (16 * BAUD_RATE)) - 1 ;
	UBRRL = (u8)Local_u16UBRR;
	UBRRH = (UBRRH_MASK & (Local_u16UBRR >> 8));

#elif USART_SPEED  == ASYNCH_NORMAL
	SET_BIT(UCSRA, UCSRA_U2X);
	Local_u16UBRR = (FSYS / (8 * BAUD_RATE)) - 1 ;
	UBRRL = (u8)Local_u16UBRR;
	UBRRH = (UBRRH_MASK & (Local_u16UBRR >> 8));

#else
#error "Wrong USART_SPEED Configuration "
#endif

#if USART_TRANSMITER == ENABLE
	SET_BIT(UCSRB, UCSRB_TXEN);
#elif USART_TRANSMITER == DISABLE
	CLEAR_BIT(UCSRB, UCSRB_TXEN);
#else
#error "Wrong USART_TRANSMITER Configurations"
#endif

#if USART_RECEIVER == ENABLE
	SET_BIT(UCSRB, UCSRB_RXEN);
#elif USART_RECEIVER== DISABLE
	CLEAR_BIT(UCSRB, UCSRB_RXEN);
#else
#error "Wrong USART_RECEIVER Configurations"
#endif

}

u8 USART_voidSendCharSynch(u8 data)
{
	u16 Local_u16Counter = 0;
	u8 Local_u8ErrorState = OK;
	if(USART_State == IDlE)
	{
		/* First make USART Busy */
		USART_State = USART_BUSY;
		/* Polling For a UDRE Flag */
		while((GET_BIT(UCSRA, UCSRA_UDRE) != 1) && (Local_u16Counter !=  TIMEOUT))
			Local_u16Counter++;

		if(Local_u16Counter != TIMEOUT)
		{
			UDR = data;
			USART_State = IDlE;
		}
		else
		{
			Local_u8ErrorState = NOT_OK;
		}
	}
	else
	{
		Local_u8ErrorState = USART_BUSY;
	}

	return Local_u8ErrorState;
}

u8 USART_voidSendCharAsynch(u8 Data, void(*CallbackFunctionNotification)(void))
{
	u8 Local_u8ErroState = OK;
	if(USART_State == IDlE)
	{
		if(CallbackFunctionNotification != NULL)
		{
			USART_State = USART_BUSY;
			USART_ISRTransmit_Source = CHARACTER;
			CallbackFunc = CallbackFunctionNotification;
			GlobalDataSend = Data;
			SET_BIT(UCSRB, UCSRB_UDRIE);
		}
		else
		{
			Local_u8ErroState = NULL_POINTER;
		}
	}
	else
	{
		Local_u8ErroState = USART_BUSY;
	}

	return Local_u8ErroState;
}

u8 USART_SendStringASynch(const char *String ,void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(USART_State == IDlE)
	{
		if(String != NULL && Copy_pvCallBackFunc != NULL)
		{
			USART_State = USART_BUSY;
			USART_ISRTransmit_Source = STRING;
			CallbackFunc = Copy_pvCallBackFunc;
			USART_String = String;
			SET_BIT(UCSRB, UCSRB_UDRIE);
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}
	}
	else
	{
		Local_u8ErrorState = USART_BUSY;
	}
	return Local_u8ErrorState;
}

u8 USART_RecieveCharSynch(u8*ReadingData)
{
	u8 Local_u8Counter = 0;
	u8 Local_u8ErrorState = OK;
	if(USART_State == IDlE)
	{
		while((GET_BIT(UCSRA, UCSRA_RXC) != 1) && (Local_u8Counter != TIMEOUT))
			Local_u8Counter++;

		if(Local_u8Counter != TIMEOUT)
		{
			*ReadingData = UDR;
		}
		else
		{
			Local_u8ErrorState = NOT_OK;
		}
	}
	else
	{
		Local_u8ErrorState = USART_BUSY;
	}

	return Local_u8ErrorState;
}

u8 USART_RecieveCharASynch(u8*ReadingData, void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(USART_State == IDlE)
	{
		if(Copy_pvCallBackFunc != NULL)
		{
			USART_State = USART_BUSY;
			USART_ISRTransmit_Source = CHARACTER;
			GlobalDataRecieve = ReadingData;
			CallbackFunc = Copy_pvCallBackFunc;
			SET_BIT(UCSRB, UCSRB_RXCIE);
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}
	}
	else
	{
		Local_u8ErrorState = USART_BUSY;
	}


	return Local_u8ErrorState;
}

u8 USART_RecieveBufferASynch(u8*ReadingData, u8 BufferSize ,void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(USART_State == IDlE)
	{
		if(Copy_pvCallBackFunc != NULL)
		{
			USART_State = USART_BUSY;
			USART_ISRTransmit_Source = STRING;
			USART_Buffer = ReadingData;
			USART_Buffer_Size = BufferSize;
			CallbackFunc = Copy_pvCallBackFunc;
			SET_BIT(UCSRB, UCSRB_RXCIE);
		}
		else
		{
			Copy_pvCallBackFunc = NULL_POINTER;
		}
	}
	else
	{
		Local_u8ErrorState = USART_BUSY;
	}
	return Local_u8ErrorState;

}


/* ISR For USART Data Register Empty */
void __vector_14 (void)
{
	if(USART_ISRTransmit_Source == CHARACTER)
	{
		if(CallbackFunc != NULL)
		{
			UDR = GlobalDataSend;
			USART_State = IDlE;
			CallbackFunc();
			CLEAR_BIT(UCSRB, UCSRB_UDRIE);
		}
		else
		{
			/* Do nothing */
		}
	}
	else if(USART_ISRTransmit_Source == STRING)
	{
		if(CallbackFunc != NULL)
		{

			UDR = USART_String[GlobalCounter];
			GlobalCounter++;
			if(USART_String[GlobalCounter] == '/0')
			{
				USART_State = IDlE;
				GlobalCounter = 0;
				CallbackFunc();
				CLEAR_BIT(UCSRB, UCSRB_UDRIE);
			}
			else
			{
				/* Do nothing */
			}
		}
		else
		{
			/* Do nothing */
		}
	}

}

/* ISR For USART, Rx Complete */
void __vector_13(void)
{
	if(USART_ISRTransmit_Source == CHARACTER)
	{
		if(CallbackFunc != NULL)
		{
			*GlobalDataRecieve = UDR;
			USART_State = IDlE;
			CallbackFunc();
			CLEAR_BIT(UCSRB, UCSRB_RXCIE);
		}
		else
		{
			/* Do nothing */
		}
	}
	else if(USART_ISRTransmit_Source == STRING)
	{
		if(CallbackFunc != NULL)
		{
			USART_Buffer[GlobalCounter] = UDR;
			GlobalCounter++;
			if(GlobalCounter == USART_Buffer_Size)
			{
				USART_State = IDlE;
				GlobalCounter = 0;
				CallbackFunc();
				CLEAR_BIT(UCSRB, UCSRB_RXCIE);
			}
			else
			{
				/* Do nothing */
			}
		}
		else
		{
			/* Do nothing */
		}
	}

}
