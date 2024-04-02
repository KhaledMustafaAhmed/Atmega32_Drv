#ifndef  ADC_CONFIG_H_
#define  ADC_CONFIG_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     SWC: ADC                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/

/*****************************************************************************
   Voltage Reference
  1- AREF, Internal Vref turned off
  2- AVCC with external capacitor at AREF pin
  3- Internal 2.56V Voltage Reference with external capacitor at AREF pin.
  ----------------------------------------------------------------------------
  Choose one to select your voltage source: AVCC as default source
  1- AREF
  2- AVCC
  3- INTERNAL 2.56V Voltage Reference "write INTERNAL"
 ******************************************************************************/
#define VOLTAGE_SOURCE	AVCC

/*****************************************************************************
  ADC Prescaler Select Bits:
  These bits determine the division factor between the XTAL frequency and
  the input clock to the ADC.
  1- Division Factor: 2 	>> Write: DIV_BY_2
  2- Division Factor: 4 	>> Write: DIV_BY_4
  3- Division Factor: 8 	>> Write: DIV_BY_8
  4- Division Factor: 16 	>> Write: DIV_BY_16
  5- Division Factor: 32 	>> Write: DIV_BY_32
  6- Division Factor: 64 	>> Write: DIV_BY_64
  7- Division Factor: 128 	>> Write: DIV_BY_128
  DIV_BY_128 as default prescaler
 ******************************************************************************/
#define ADC_PRESCALER	DIV_BY_128

/*****************************************************************************
	ADC Left Adjust Result: choose from two options :
	1- LEFT_ADJUST
	2- RIGHT_ADJUST
	LEFT_ADJUST as default state.
 ******************************************************************************/
#define ADJUST_RESULT 	LEFT_ADJUST

/*****************************************************************************
	Set the number you want
 ******************************************************************************/
#define TIMEOUT	50000

#endif
