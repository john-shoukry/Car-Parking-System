#include "ultra_sonic.h"
#include "icu.h"
#include "gpio.h"
#include "util/delay.h"


static volatile uint16 g_timeHigh = 0;
static volatile uint8 g_edgeCount = 0;



void Ultrasonic_init(void)
{

    ICU_ConfigType ICU_Config = {F_CPU_8, RISING}; // Configure ICU for rising edge detection and F_CPU/8

    /* Initialize the ICU driver */
    ICU_init(&ICU_Config);

    /* Set the ICU callback function */
    ICU_setCallBack(Ultrasonic_edgeProcessing);

    /* Configure the trigger pin as output */
    GPIO_setupPinDirection(TRIGGER_PORT_ID, TRIGGER_PIN_ID, PIN_OUTPUT);

    /* Configure the echo pin as input */
    GPIO_setupPinDirection(ECHO_PORT_ID, ECHO_PIN_ID, PIN_INPUT);  // Ensure this pin is set to input
}

void Ultrasonic_Trigger(void)
{
    /* Send the trigger pulse  */
    GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_HIGH);
    _delay_us(10);
    GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
    uint16 distance;

    /* Trigger the ultrasonic sensor to start measurement */
    Ultrasonic_Trigger();

    /* Wait until both rising and falling edges are captured */
    while (g_edgeCount != 2);

    /* Calculate the distance in centimeters using the pulse width (g_timeHigh) */
    distance = 1+(uint16)((g_timeHigh *0.0085));

    /* Reset the edge counter for the next measurement */
    g_edgeCount = 0;

    return distance;
}

void Ultrasonic_edgeProcessing(void)
{
    if (g_edgeCount == 0)
    {
        /* Rising edge detected */
        /* Clear the timer counter to start count from 0 */
        ICU_clearTimerValue();

        /* Change the edge detection to falling edge */
        ICU_setEdgeDetectionType(FALLING);

        /* Increment edge count */
        g_edgeCount++;
    }
    else if (g_edgeCount == 1)
    {
        /* Falling edge detected */
        /* Get the Timer1 value which indicates the time duration of the high pulse */
        g_timeHigh = ICU_getInputCaptureValue();

        /* Change the edge detection back to rising edge */
        ICU_setEdgeDetectionType(RISING);

        /* Increment edge count to indicate that both edges are captured */
        g_edgeCount++;
    }
}
