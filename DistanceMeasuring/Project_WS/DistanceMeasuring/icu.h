 /********************************************************************
 * File Name:icu.h
 *
 * Model:-Header File of ICU Driver
 *
 * Created on:6/10/2022
 *
 * Description:-INPUT Capture Unit
 *
 * Author:Mohammed Sayed Shaaban
 ********************************************************************/

#ifndef ICU_H_
#define ICU_H_
#include "std_types.h"
/********************************************************************
 *                           Definitions
 ********************************************************************/
#define ICU_ICP1_PORT_ID     PORTD_ID
#define ICU_ICP1_PIN_ID      PIN6_ID
typedef enum{
	falling,rising
}ICU_edge;

typedef enum{
	F_CPU_NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_Clock;

typedef struct{
	ICU_edge edg;
	ICU_Clock clock;
}ICU_Config;

/********************************************************************
 *                           Prototypes
 *********************************************************************/
/*
 * Function_Name: ICU_init
 * Description:-
 * Initialize the Input capture unit
 */
void ICU_init(const ICU_Config * Config_Ptr);

/*
 * Function_Name: ICU_setCallBack
 * Description:-
 * to keep the address of call back function in a global pointer to function
 */
void ICU_setCallBack(void(*icu_ptr)(void));

/*
 * Function_Name: ICU_setEdge
 * Description:-
 * to set the required edge
 */
void ICU_setEdge(const ICU_edge edgeType);

/*
 * Function_Name: ICU_getInputCapture
 * Description:-
 * to get the value of input capture
 */
uint16 ICU_getInputCapture(void);

/*
 * Function_Name: clearTimer
 * Description:-
 * to clear the value of register counter(TCNT1)
 */
void ICU_clearTimer(void);

/*
 * Function_Name: ICU_DeInit
 * Description:-
 * to stop the timer1
 */
void ICU_DeInit(void);

#endif
