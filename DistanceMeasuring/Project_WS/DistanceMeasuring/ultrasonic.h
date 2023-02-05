 /********************************************************************
 * File Name:ultrasonic.h
 *
 * Model:-Header File of ultrasonic_sensor Driver
 *
 * Created on:10/10/2022
 *
 * Description:-ultrasonic_sensor to calculate the distance
 *
 * Author:Mohammed Sayed Shaaban
 ********************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"
/****************************************************************************
 *                               Definitions
 ****************************************************************************/
/*Pin of echo(alaways connected to PIN6 in PORTD)*/
#define ULTRASONIC_ECHO_PORT_ID             PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID              PIN6_ID
/*Pin of Trigger*/
#define ULTRASONIC_TRIGGER_PORT_ID             PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID              PIN5_ID

/****************************************************************************
 *                               Prototypes
 ****************************************************************************/
/*
 * Function_Name:Ultrasonic_init
 *
 * Description:
 *
 * 1-setup the Ultrasonic sensor
 *
 * 2- Setup the direction for the trigger pin as output pin.
 *
 */
void ULTRASONIC_init(void);


/* Function_Name:Ultrasonic_readDistance
*
* Description:
*
*➢ Send the trigger pulse by using Ultrasonic_Trigger function.
*➢
*➢  Start the measurements by the ICU from this moment
*
*/
uint16 ULTRASONIC_readDistancd(void);





#endif /* ULTRASONIC_H_ */
