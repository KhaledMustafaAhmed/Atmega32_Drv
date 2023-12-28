/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     SWC: EXTI                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/
#ifndef  EXTI_CONFIG_H_
#define  EXTI_CONFIG_H_

/* 1- LOW LEVEL
 * 2- ON CHANGE
 * 3- FALLING EDGE
 * 4- RISING EDGE
 */
#define INT0_SENSE	FALLING_EDGE
#define INT1_SENSE	FALLING_EDGE

/* 1- FALLING EDGE
 * 2- RISING EDGE
 */
#define INT2_SENSE	FALLING_EDGE

/* 1- ENABLED
 * 2- DISABLED
 */
#define INT0_INITIAl_STATE	ENABLED
#define INT1_INITIAl_STATE	ENABLED
#define INT2_INITIAl_STATE	ENABLED





#endif
