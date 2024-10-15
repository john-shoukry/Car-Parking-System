Objective

The goal of this project is to design a simple car parking sensor system that helps drivers detect obstacles and avoid collisions while parking. The system measures the distance between the car and an obstacle using an ultrasonic sensor and provides visual and auditory feedback via an LCD display, LEDs, and a buzzer.

Project Overview
This system uses an ATmega32 microcontroller to process distance data from an ultrasonic sensor and display it on an LCD. Three LEDs (Red, Green, and Blue) and a buzzer are used to provide visual and auditory proximity warnings. As the obstacle gets closer, the LEDs light up progressively and the buzzer activates, helping the driver park safely.

Features
1. Ultrasonic Distance Measurement
The ultrasonic sensor measures the distance between the car and nearby objects, allowing the system to detect obstacles in real-time.
2. LCD Display
The LCD shows the distance between the car and the obstacle in centimeters.
If the obstacle is within 5 cm, the LCD displays "Stop" as a warning.
3. LED Indicators
Three LEDs (Red, Green, and Blue) are used to indicate the proximity of the object:
Distance > 20 cm: Green LED turns ON.
Distance between 10–20 cm: Green and Blue LEDs turn ON.
Distance between 5–10 cm: Red LED turns ON with the Green and Blue LEDs.							
Distance <= 5 cm: All LEDs turn ON and the buzzer sounds.
4. Buzzer Alert
The buzzer activates when the distance between the car and the obstacle is less than or equal to 5 cm, indicating that the driver should stop.
