/*
 * test.c
 *
 *  Created on: Oct 15, 2024
 *      Author: user
 */


/*
 * main.c
 *
 *  Created on: Oct 14, 2024
 *      Author: user
 */

#include "icu.h"
#include "gpio.h"
#include "LED.h"
#include "Buzzer.h"
#include "lcd.h"
#include "ultra_sonic.h"
#include <avr/io.h>
#include "common_macros.h"
#include <util/delay.h>

int main(void)
{
	// Initialize components
	Buzzer_init();
	LCD_init();
	LEDS_init();
	Ultrasonic_init();

	// Enable global interrupts
	SET_BIT(SREG, 7);

	uint16 distance = 0; // Variable to hold the measured distance
	uint8 flag_stop=0;
	uint8 flag_dist=0;

	while (1)
	{
		// Read distance from the ultrasonic sensor
		distance = Ultrasonic_readDistance();




		// Control LED and Buzzer based on distance
		if (distance <= 5)
		{
			if(flag_stop==0)
			{
				LCD_clearScreen();
				LCD_displayString("Stop!");
				flag_stop=1;
			}

			Buzzer_on();
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
			_delay_ms(500); // Flash duration
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
			_delay_ms(500); // Flash duration
			flag_dist=0;
		}
		else
		{
			flag_stop=0;
			if(flag_dist==0){
				LCD_clearScreen();
				LCD_displayString("Distance=    cm"); // Display initial message with extra spaces
				flag_dist=1;
			}
			LCD_moveCursor(0, 10);  // Move to where the distance is displayed
			// Display the new distance
			LCD_intgerToString(distance); // Display new distance
			if (distance >= 6 && distance <= 10)
			{


				if(distance<10){
					LCD_moveCursor(0, 11);
					LCD_displayString(" ");
				}
				Buzzer_off();
				LED_on(RED_LED);
				LED_on(GREEN_LED);
				LED_on(BLUE_LED);
			}
			else if (distance >= 11 && distance <= 15)
			{



				Buzzer_off();
				LED_on(RED_LED);
				LED_on(GREEN_LED);
				LED_off(BLUE_LED);
			}
			else if (distance >= 16 && distance <= 20)
			{

				Buzzer_off();
				LED_on(RED_LED);
				LED_off(GREEN_LED);
				LED_off(BLUE_LED);
			}
			else if (distance > 20)
			{

				Buzzer_off();
				LED_off(RED_LED);
				LED_off(GREEN_LED);
				LED_off(BLUE_LED);
			}
		}
	}
}

