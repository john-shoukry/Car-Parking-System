/*
 * LED.c
 *
 *  Created on: Oct 6, 2024
 *      Author: user
 */

#include"gpio.h"
#include"std_types.h"
#include"common_macros.h"
#include "LED.h"

/*
  * Description :
 * Setup the direction of the LED pins as output.
 * Turn off all the Leds
 */
void LEDS_init(void)
{
	 GPIO_setupPinDirection(LED_PORT,RED_LED,PIN_OUTPUT);
	 GPIO_setupPinDirection(LED_PORT,GREEN_LED,PIN_OUTPUT);
	 GPIO_setupPinDirection(LED_PORT,BLUE_LED,PIN_OUTPUT);
	 GPIO_writePin(LED_PORT,RED_LED,led_off);
	 GPIO_writePin(LED_PORT,GREEN_LED,led_off);
	 GPIO_writePin(LED_PORT,BLUE_LED,led_off);


}
/* Description
 * turn on specified led using id
 */
void LED_on(LED_ID id)
{
	 GPIO_writePin(LED_PORT,id,led_on);
}

/* Description
 * turn off specified led using id
 */
void LED_off(LED_ID id)
{
	 GPIO_writePin(LED_PORT,id,led_off);
}
