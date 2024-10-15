/*
 * LED.h
 *
 *  Created on: Oct 6, 2024
 *      Author: user
 */

#ifndef LED_H_
#define LED_H_
#include "std_types.h"
typedef enum{
	RED_LED=0,GREEN_LED,BLUE_LED
}LED_ID;

#define led_on 1
#define led_off 0
#define LED_PORT PORTC_ID

/* Initializes all Leds (red, green, blue) pins direction.
 *  Turn off all the Leds*/
void LEDS_init(void);
/*Turns on the specified LED.*/
 void LED_on(LED_ID id);
/* Turns off the specified LED*/
 void LED_off(LED_ID id);


#endif /* LED_H_ */
