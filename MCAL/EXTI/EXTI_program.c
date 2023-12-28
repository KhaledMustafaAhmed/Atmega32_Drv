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
/* Global Pointer to function */
void (*EXTI_pvInt0Func)(void) = NULL;
void (*EXTI_pvInt1Func)(void) = NULL;
void (*EXTI_pvInt2Func)(void) = NULL;


/* PRE build configuration for INT0 */
void EXTI_voidInt0Init(void)

{
#if INT0_SENSE == LOW_LEVEL
	/* Set sense control for INT0 to LOW_LEVEL */
	CLEAR_BIT(MCUCR, MCUCR_ISC00);
	CLEAR_BIT(MCUCR, MCUCR_ISC01);

#elif  INT0_SENSE == ON_CHANGE
	/* Set sense control for INT0 to ON_CHANGE */
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLEAR_BIT(MCUCR, MCUCR_ISC01);

#elif  INT0_SENSE == FALLING_EDGE
	/* Set sense control for INT0 to FALLING_EDGE */
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLEAR_BIT(MCUCR, MCUCR_ISC00);

#elif  INT0_SENSE == RISING_EDGE
	/* Set sense control for INT0 to RISING_EDGE */
	SET_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);
#else
#error	"Wrong INT0_SENSE Configuration option"
#endif

	/* Check PIE initial state */
#if	INT0_INITIAl_STATE == ENABLED
	SET_BIT(GICR, GICR_INT0);
#elif	INT0_INITIAl_STATE == DISABLED
	CLEAR_BIT(GICR, GICR_INT0);
#else
#error "Wrong INT0_INITIAl_STATE Configuration option"
#endif

}

/* PRE build configuration for INT1 */
void EXTI_voidInt1Init(void)
{
#if INT1_SENSE == LOW_LEVEL
	/* Set sense control for INT1 to LOW_LEVEL */
	CLEAR_BIT(MCUCR, MCUCR_ISC11);
	CLEAR_BIT(MCUCR, MCUCR_ISC10);

#elif  INT1_SENSE == ON_CHANGE
	/* Set sense control for INT0 to ON_CHANGE */
	SET_BIT(MCUCR, MCUCR_ISC10);
	CLEAR_BIT(MCUCR, MCUCR_ISC11);

#elif  INT1_SENSE == FALLING_EDGE
	/* Set sense control for INT0 to FALLING_EDGE */
	SET_BIT(MCUCR, MCUCR_ISC11);
	CLEAR_BIT(MCUCR, MCUCR_ISC10);

#elif  INT1_SENSE == RISING_EDGE
	/* Set sense control for INT0 to RISING_EDGE */
	SET_BIT(MCUCR, MCUCR_ISC11);
	SET_BIT(MCUCR, MCUCR_ISC10);
#else
#error	"Wrong INT1_SENSE Configuration option"
#endif

	/* Check PIE initial state */
#if	INT1_INITIAl_STATE == ENABLED
	SET_BIT(GICR, GICR_INT1);
#elif	INT1_INITIAl_STATE == DISABLED
	CLEAR_BIT(GICR, GICR_INT1);
#else
#error "Wrong INT1_INITIAl_STATE Configuration option"
#endif
}

/* PRE build configuration for INT2 */
void EXTI_voidInt2Init(void)
{
#if INT2_SENSE == FALLING_EDGE
	/* Set sense control for INT2 to FALLING_EDGE */
	CLEAR_BIT(MCUCSR, MCUCSR_ISC2);

#elif  INT2_SENSE == RISING_EDGE
	/* Set sense control for INT2 to RISING_EDGE */
	SET_BIT(MCUCSR, MCUCSR_ISC2);

#else
#error	"Wrong INT2_SENSE Configuration option"
#endif

	/* Check PIE initial state */
#if	INT2_INITIAl_STATE == ENABLED
	SET_BIT(GICR, GICR_INT2);
#elif	INT2_INITIAl_STATE == DISABLED
	CLEAR_BIT(GICR, GICR_INT2);
#else
#error "Wrong INT2_INITIAl_STATE Configuration option"
#endif
}

/* Function to set the required sense control for int0 using post build configuration */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	/* Set sense control for INT0 to LOW_LEVEL */
	case LOW_LEVEL: CLEAR_BIT(MCUCR, MCUCR_ISC00); CLEAR_BIT(MCUCR, MCUCR_ISC01); break;
	/* Set sense control for INT0 to ON_CHANGE */
	case ON_CHANGE: SET_BIT(MCUCR, MCUCR_ISC00); CLEAR_BIT(MCUCR, MCUCR_ISC01); break;
	/* Set sense control for INT0 to FALLING_EDGE */
	case FALLING_EDGE: SET_BIT(MCUCR, MCUCR_ISC01); CLEAR_BIT(MCUCR, MCUCR_ISC00); break;
	/* Set sense control for INT0 to RISING_EDGE */
	case RISING_EDGE: SET_BIT(MCUCR, MCUCR_ISC01); SET_BIT(MCUCR, MCUCR_ISC00); break;

	default: Local_u8ErrorState = NOT_OK; break;
	}
	return Local_u8ErrorState;
}


u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = 0;
	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}


	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState = 0;
		if(Copy_pvInt1Func != NULL)
		{
			EXTI_pvInt1Func = Copy_pvInt1Func;
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}


		return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState = 0;
			if(Copy_pvInt2Func != NULL)
			{
				EXTI_pvInt2Func = Copy_pvInt2Func;
			}
			else
			{
				Local_u8ErrorState = NULL_POINTER;
			}


			return Local_u8ErrorState;
}
/* ISR for INT0 */
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/* Do Nothing */
	}

}
/* ISR for INT1 */
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/* Do Nothing */
	}

}
/* ISR for INT2 */
void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/* Do Nothing */
	}

}

