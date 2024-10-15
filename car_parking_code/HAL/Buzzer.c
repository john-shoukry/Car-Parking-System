/*
 * Buzzer.c
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */

#include"gpio.h"
#include"std_types.h"
#include"common_macros.h"
#include "Buzzer.h"

 /*Initializes the buzzer pin direction and turn off the buzzer.*/
 void Buzzer_init(void)
 {
	 GPIO_setupPinDirection(Buzzer_PORT,Buzzer_PIN,PIN_OUTPUT);
	 GPIO_writePin(Buzzer_PORT,Buzzer_PIN,turn_off);
 }
/* Activates the buzzer.*/
 void Buzzer_on(void)
 {
	 GPIO_writePin(Buzzer_PORT,Buzzer_PIN,turn_on);
 }
 /* Deactivates the buzzer. */
 void Buzzer_off(void)
 {
	 GPIO_writePin(Buzzer_PORT,Buzzer_PIN,turn_off);
 }
