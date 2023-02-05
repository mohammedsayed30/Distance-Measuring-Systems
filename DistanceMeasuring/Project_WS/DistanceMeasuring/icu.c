 /********************************************************************
 * File Name:icu.c
 *
 * Model:-Source File of ICU Driver
 *
 * Created on:6/10/2022
 *
 * Description:-INPUT Capture Unit
 *
 * Author:Mohammed Sayed Shaaban
 ********************************************************************/
#include "icu.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "common_macros.h"
#include "gpio.h"
static volatile void (*g_Timer1_Call_Back_Ptr)(void)=NULL_PTR;
/*handl the Interrupt*/
ISR(TIMER1_CAPT_vect){
	if(g_Timer1_Call_Back_Ptr !=NULL_PTR){
		(*g_Timer1_Call_Back_Ptr)();
	}
}
/*
 * Function_Name: ICU_init
 * Description:-
 * Initialize the Input capture unit
 */
void ICU_init(const ICU_Config* config){
	/*to set the icp1 as input*/
	GPIO_setupPinDirection(ICU_ICP1_PORT_ID ,ICU_ICP1_PIN_ID, PIN_INPUT);
	TCNT1=0;              /*counter register*/
	ICR1=0;               /*initialize the InputCapture PIN*/
	TCCR1A =(1<<FOC1A)|(1<<FOC1B);  /*to use normal mode*/
	/*set the required clock and edge*/
	TCCR1B=(TCCR1B & 0)|((config->edg)<<ICES1)|(config->clock);
	/*Enable the Interrupt*/
	TIMSK|=(1<<TICIE1);
}
/*
 * Function_Name: ICU_setCallBack
 * Description:-
 * to keep the address of call back function in a global pointer to function
 */
void Timer1_setCallBack(void(*icu_ptr)(void)){
	g_Timer1_Call_Back_Ptr=icu_ptr;
}
/*
 * Function_Name: ICU_setEdge
 * Description:-
 * to set the required edge
 */
void ICU_setEdge(const ICU_edge edge){
	TCCR1B = (TCCR1B&0xBF) |(edge<<ICES1);
}

/*
 * Function_Name: ICU_getInputCapture
 * Description:-
 * to get the value of input capture
 */
uint16 ICU_getInputCapture(void){
	return ICR1;
}
/*
 * Function_Name: clearTimer
 * Description:-
 * to clear the value of register counter(TCNT1)
 */
void ICU_clearTimer(void){
	TCNT1=0;
}

/*
 * Function_Name: ICU_DeInit
 * Description:-
 * to stop the timer1
 */
void ICU_DeInit(void){
	ICR1=0;
	TCNT1=0;
	TCCR1A=0;
	TCCR1B=0;
	TIMSK &= ~(1<<TICIE1);
}
