/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: EXTI                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

static void(*EXTI_pvINT0)(void) = NULL;
static void(*EXTI_pvINT1)(void) = NULL;
static void(*EXTI_pvINT2)(void) = NULL;

void EXTI_INT0Init(void)
{
	/* Check Sense Control: */
#if INT0Sense == LowLevel
	CLEAR_BIT(MCUCR,MCUCR_ISC01);
	CLEAR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0Sense == OnChange
	CLEAR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#elif INT0Sense == FallingEdge
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLEAR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0Sense == RisingEdge
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#else
#error "Wrong INT0Sense configuration options"
#endif

	/* Check interrupt state  */
#if INT0INITIALSTATE == ENABLE
	SET_BIT(GICR, GICR_INT0);
#elif INT0INITIALSTATE == DISABLE
	CLEAR_BIT(GICR, GICR_INT0);
#else
#error "Wrong INT0INITIALSTATE configuration options"
#endif
}

void EXTI_INT1Init(void)
{
	/* Check Sense Control */
#if INT1Sense == LowLevel
	CLEAR_BIT(MCUCR,MCUCR_ISC10);
	CLEAR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1Sense == OnChange
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLEAR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1Sense == FallingEdge
	CLEAR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1Sense == RisingEdge
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Wrong INT0Sense configuration options"
#endif
	/* Check interrupt for INT1INITIALSTATE  */
#if INT1INITIALSTATE == ENABLE
	SET_BIT(GICR,GICR_INT1);
#elif INT1INITIALSTATE == DISABLE
	CLEAR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1INITIALSTATE configuration options"
#endif
}

void EXTI_INT2Init(void)
{
	/* Check Sense Control */
#if INT2Sense == FallingEdge
	CLEAR_BIT(MCUCSR,MCUCSR_ISC2);
#elif INT2Sense == RisingEdge
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "Wrong INT2Sense configuration options"
#endif
	/* Check interrupt for INT2INITIALSTATE  */
#if INT2INITIALSTATE == ENABLE
	SET_BIT(GICR,GICR_INT2);
#elif INT2INITIALSTATE == DISABLE
	CLEAR_BIT(GICR,GICR_INT2);
#else
#error "Wrong INT2INITIALSTATE configuration options"
#endif
}

u8 EXTI_INT0SetCallBackFunc(void(*pvINT0func)(void))
{
	u8 Local_u8ErrorStatus = OK;
	if(pvINT0func != NULL)
	{
		EXTI_pvINT0 = pvINT0func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

u8 EXTI_INT1SetCallBackFunc(void(*pvINT1func)(void))
{
	u8 Local_u8ErrorStatus = OK;
	if(pvINT1func != NULL)
	{
		EXTI_pvINT1 = pvINT1func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

u8 EXTI_INT2SetCallBackFunc(void(*pvINT2func)(void))
{
	u8 Local_u8ErrorStatus = OK;
	if(pvINT2func != NULL)
	{
		EXTI_pvINT2 = pvINT2func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvINT0 != NULL)
	{
		EXTI_pvINT0();
	}
	else
	{
		/* Do nothing */
	}
}

void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvINT1 != NULL)
	{
		EXTI_pvINT1();
	}
	else
	{
		/* Do nothing */
	}
}

void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvINT2 != NULL)
	{
		EXTI_pvINT2();
	}
	else
	{
		/* Do nothing */
	}
}

