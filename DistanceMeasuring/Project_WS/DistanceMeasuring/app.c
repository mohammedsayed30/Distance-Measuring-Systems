 /********************************************************************
 * File Name:app.c
 *
 * Model:-Source File of Ulteronic_Sensor
 *
 * Created on:10/10/2022
 *
 * Description:-Application for Ulteronic_Sensor
 *
 * Author:Mohammed Sayed Shaaban
 ********************************************************************/
#include "ultrasonic.h"   /*to measurement the distance*/
#include "LCD.h"     /*to use the LCD to display the required distance*/
#include <avr/io.h> /*to use SREG register to active the interrupt*/
#include <util/delay.h>  /*to use the delay function*/
/*global variable to count the number of edges*/
uint8 g_edgcount=0;
int main(void){
	uint16 required_distance;  /*the required distance*/
	SREG|=(1<<7);               /*to active the global Interrupt*/
	LCD_init();                /*to active the LCD*/
	LCD_displayString("Distance=    cm"); /*to display this string*/
	ULTRASONIC_init();                             /*to active the Ultersonic sensor*/
	required_distance=ULTRASONIC_readDistance();   /*to get the the required distance*/
	while(1){
		if(g_edgcount==2){    /*to measure the time between rising and falling*/
			g_edgcount=0;
			LCD_moveCursor(0,10);    /*to display the distance in this location*/
			LCD_intgerToString((uint32)required_distance);
			required_distance=ULTRASONIC_readDistance();
	      }
		if(required_distance<10){
			LCD_moveCursor(0,11);
			LCD_displayCharacter(' ');   /*to remove this number in this location*/
		}
		if(required_distance<100){
			LCD_moveCursor(0,12);
			LCD_displayCharacter(' ');          /*to remove this number in this location*/
		}

    }
}





