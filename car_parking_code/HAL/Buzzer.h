/*
 * Buzzer.h
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define turn_on 1
#define turn_off 0
#define Buzzer_PORT PORTC_ID
#define Buzzer_PIN	PIN5_ID

 /*Initializes the buzzer pin direction and turn off the buzzer.*/
 void Buzzer_init(void);
/* Activates the buzzer.*/
 void Buzzer_on(void);
 /* Deactivates the buzzer. */
 void Buzzer_off(void);


#endif /* BUZZER_H_ */
