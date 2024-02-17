#ifndef  EXTI_CONFIG_H_
#define  EXTI_CONFIG_H_
/*********************************************************************************/
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     SWC: EXTI                  **************************/
/************************     Version: 1.00             **************************/
/*********************************************************************************/
/*********************************************************************************/
/*  */

/* Sense Control Options:
 * 1- LowLevel
 * 2- OnChange
 * 3- FallingEdge
 * 4- RisingEdge
 */

/* For INT0 Choose One from the four sense control options: Falling Edge as a default state */
#define INT0Sense	FallingEdge
/* For INT1 Choose One from the four sense control options: Falling Edge as a default state */
#define INT1Sense	FallingEdge
/* For INT2 Choose One from these options: Falling Edge as a default state.
 * 1- FallingEdge
 * 2- RisingEdge
 */
#define INT2Sense	FallingEdge
/* Enable or Disable interrupt
 * 1- ENABLE
 * 2- DISABLE
 * DISABLE as a default state
 */
#define INT0INITIALSTATE	DISABLE
#define INT1INITIALSTATE	DISABLE
#define INT2INITIALSTATE	DISABLE

#endif
