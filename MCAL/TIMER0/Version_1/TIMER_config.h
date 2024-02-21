#ifndef  TIMER0_CONFIG_H_
#define  TIMER0_CONFIG_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     Layer: MCAL               **************************/
/************************     Version: 1                **************************/
/*********************************************************************************/

/* Set the mode that you want: 
1- NORMAL_MODE
2- CTC_MODE
*/
#define TIMER0_MODE  CTC_MODE



/* Set the clock option that you want "TIME0 is a 8 BIT Timer": 
1- TIMER0_PRESCALER_1       >> Tick = 1/8 Microseconds  >> OverFlow Time = Tick * 2^n = 1/8 * 2^8 = 32 microseconds 
2- TIMER0_PRESCALER_8       >> Tick = 1 Microseconds    >> OverFlow Time = Tick * 2^n = 1 * 2^8 = 256 microseconds 
3- TIMER0_PRESCALER_64      >> Tick = 8 Microseconds    >> OverFlow Time = Tick * 2^n = 8 * 2^8 = 2048 microseconds 
4- TIMER0_PRESCALER_256     >> Tick = 32 Microseconds   >> OverFlow Time = Tick * 2^n = 32 * 2^8 = 8192 microseconds 
5- TIMER0_PRESCALER_1024    >> Tick = 128 Microseconds  >> OverFlow Time = Tick * 2^n = 128 * 2^8 = 32768 microseconds "Max Delay Time"   

*/
#define TIMER0_CK  TIMER0_PRESCALER_8 

/* define Overflow time based on given clock  */
#if TIMER0_CK == TIMER0_PRESCALER_1
#define TIMER0_OVT  32
#elif TIMER0_CK == TIMER0_PRESCALER_8
#define TIMER0_OVT  256
#elif TIMER0_CK == TIMER0_PRESCALER_64
#define TIMER0_OVT  2048
#elif TIMER0_CK == TIMER0_PRESCALER_256
#define TIMER0_OVT  8192
#elif TIMER0_CK == TIMER0_PRESCALER_1024
#define TIMER0_OVT  32768
#endif

/* Timer0 Interrupt options:
1- TIMER0_OverFlow_INT_ENABLE
2- TIMER0_CompareMatch_INT_ENABLE
 */
#define TIMER0_INT  TIMER0_CompareMatch_INT_EN

/* Timer0 CTC mode >> OC0 PIN PB3 options:
1- TIMER0_OC0_DISABLE
2- TIMER0_OC0_SET
3- TIMER0_OC0_CLEAR
4- TIMER0_OC0_TOGGLE
*/
#define TIMER0_OC0_STATE 	TIMER0_OC0_TOGGLE

#endif
