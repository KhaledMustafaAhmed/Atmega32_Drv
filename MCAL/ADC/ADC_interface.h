#ifndef  ADC_INTERFACE_H_
#define  ADC_INTERFACE_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/ 
/************************     SWC: ADC                  **************************/ 
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/ 

/*******************************************************************************************************
  Function Name: ADC_voidInit
  Function Description:
       This function initializes the Analog-to-Digital Converter (ADC) peripheral based on pre-defined
       configurations such as voltage reference selection, result adjustment, and ADC prescaler. It sets
       up the ADC to be ready for conversion.
       - Voltage Reference Selection: Configures the voltage reference for the ADC based on the macro
         VOLTAGE_SOURCE. It supports AVCC, AREF, and internal voltage reference options.
       - Result Adjustment: Configures whether the ADC result will be left-adjusted or right-adjusted
         based on the macro ADJUST_RESULT.
       - ADC Prescaler: Sets the prescaler value for the ADC clock frequency division based on the
         macro ADC_PRESCALER. It supports division by 2, 4, 8, 16, 32, 64, and 128.
       - Finally, it enables the ADC peripheral for operation.
 *********************************************************************************************************/
void ADC_voidInit(void);

/*******************************************************************************************
  Function Name: ADC_u8StartConverstionSynch
  Function Parameters:
       1. u8 Copy_u8Channel - The ADC channel to perform conversion on.
       2. u8 *Copy_pu8ADCReading - Pointer to store the ADC conversion result.
  Function Return Type: u8
  Function Description:
       This function initiates a synchronous ADC conversion on the specified channel
       and waits for the conversion to complete. It then stores the result in the
      memory location pointed to by Copy_pu8ADCReading.
       Parameters:
           - Copy_u8Channel: The ADC channel to perform conversion on.
           - Copy_pu8ADCReading: Pointer to store the ADC conversion result.
       Return:
           - Error state:
               - OK (0): Function executed successfully.
               - NOT_OK (1): An error occurred during execution due to a timeout.
 ******************************************************************************************/
u8 ADC_u8StartConverstionSynch(u8 Copy_u8Channel);

/*******************************************************************************************
  Function Name: ADC_u8StartConvertionAsynch
  Function Parameters:
       1. u8 Copy_u8Channel - The ADC channel to perform asynchronous conversion on.
       2. u8 *Copy_pu8ADCReading - Pointer to store the ADC conversion result.
       3. void (*Copy_pvNotificationFunc)(void) - Pointer to a callback function to be
        called upon conversion completion.
  Function Return Type: u8
  Function Description:
       This function initiates an asynchronous ADC conversion on the specified channel and sets up
       a callback function to be executed upon completion of the conversion. It also initializes
       the memory location to store the ADC conversion result. If either the pointer to the
       ADC reading or the callback function pointer is NULL, the function returns an error state.
       Parameters:
           - Copy_u8Channel: The ADC channel to perform asynchronous conversion on.
           - Copy_pu8ADCReading: Pointer to store the ADC conversion result.
           - Copy_pvNotificationFunc: Pointer to a callback function to be called upon conversion completion.
       Return:
           - Error state:
               - OK (0): Function executed successfully.
              - NULL_POINTER (255): Either the pointer to ADC reading or the callback
               function pointer is NULL.
 **************************************************************************************************/
u8 ADC_u8StartConvertionAsynch(u8 Copy_u8Channel, u8 *Copy_pu8ADCReading, void(*Copy_pvNotificationFunc)(void));

#endif
