/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: UART                **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h" 

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_config.h"
#include "UART_private.h"

static void (*UART_pvSetReceiveCallBackFunc)(void) = NULL;
static void (*UART_pvSetTransmitCallBackFunc)(void) = NULL;

void USART_Init(UART_configuration *USART_config)
{
    /*calculate UBRR value: sysFreq: 8000000*/
    u16 UBRR_val = 8000000 / (16UL * (USART_config->baud_rate)) - 1;
    u8 UCSRC_val = 0;
    /*Set Baud Rate*/
    UBRRH = (u8)(UBRR_val>>8);
    UBRRL = (u8)(UBRR_val);

    /*Set frame format (data bits, stop bits, parity)*/
    SET_BIT(UCSRC_val,UCSRC_URSEL);
    switch (USART_config->data_bits)
    {
        case 5: CLEAR_BIT(UCSRC_val,UCSRC_UCSZ0); CLEAR_BIT(UCSRC_val,UCSRC_UCSZ1);break;
        case 6: SET_BIT(UCSRC_val,UCSRC_UCSZ0); CLEAR_BIT(UCSRC_val,UCSRC_UCSZ1);break;
        case 7: CLEAR_BIT(UCSRC_val,UCSRC_UCSZ0); SET_BIT(UCSRC_val,UCSRC_UCSZ1);break;
        case 8: SET_BIT(UCSRC_val,UCSRC_UCSZ0); SET_BIT(UCSRC_val,UCSRC_UCSZ1);break;        
    }
    switch (USART_config->stop_bits)
    {
        case 1: CLEAR_BIT(UCSRC_val,UCSRC_USBS); break;
        case 2: SET_BIT(UCSRC_val,UCSRC_USBS); break;
    }
    switch (USART_config->parity)
    {
        case DISABLED_PARITY:  CLEAR_BIT(UCSRC_val,UCSRC_UPM0); CLEAR_BIT(UCSRC_val,UCSRC_UPM1);break;
        case ODD_PARITY: CLEAR_BIT(UCSRC_val,UCSRC_UPM0); SET_BIT(UCSRC_val,UCSRC_UPM1);break;;
        case EVEN_PARITY: SET_BIT(UCSRC_val,UCSRC_UPM0); SET_BIT(UCSRC_val,UCSRC_UPM1);break;
    }

     UCSRC = UCSRC_val;

     /*Enable transmitter and receiver*/
     UCSRB = (1 <<UCSRB_TXEN) | (1 << UCSRB_RXEN);

}

void USART_Transmit(u8 data)
{
    while(GET_BIT(UCSRA,UCSRA_UDRE) != 1);
    /*write data */
    UDR = data;
}

u8 USART_Receive(void)
{
    while (GET_BIT(UCSRA,UCSRA_RXC) != 1);
    /*receive data*/
    return (UDR);
}

void USART_SetReceiveInterrupt()
{
    SET_BIT(UCSRB,UCSRB_RXCIE);
}

void USART_SetTransmitInterrupt()
{
	SET_BIT(UCSRB,UCSRB_TXCIE);
}

u8 USART_SetReceiveCallBack(void (*Copy_pvCallBackFunc)(void))
{
	/*Local Status*/
	u8 Local_u8ErrorStatus = OK;
	/*check if the poiter if point to NULL or not*/
	if(Copy_pvCallBackFunc != NULL)
	{
		UART_pvSetReceiveCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}


	return Local_u8ErrorStatus;
}

u8 USART_SetTransmitCallBack(void (*Copy_pvCallBackFunc)(void))
{
	/*Local Status*/
		u8 Local_u8ErrorStatus = OK;
		/*check if the poiter if point to NULL or not*/
		if(Copy_pvCallBackFunc != NULL)
		{
			UART_pvSetTransmitCallBackFunc = Copy_pvCallBackFunc;
		}
		else
		{
			Local_u8ErrorStatus = NULL_POINTER;
		}


		return Local_u8ErrorStatus;
}
/*ISR For USART Rx Complete*/
void __vector_13(void)  __attribute__((signal));
void __vector_13(void)
{
	if(UART_pvSetReceiveCallBackFunc != NULL)
	{
		UART_pvSetReceiveCallBackFunc();
	}
	else
	{
		/* Nothing */
	}
}


void __vector_15(void)  __attribute__((signal));
void __vector_15(void)
{
	if(UART_pvSetTransmitCallBackFunc != NULL)
	{
		UART_pvSetTransmitCallBackFunc();
	}
	else
	{
		/* Nothing */
	}
}
