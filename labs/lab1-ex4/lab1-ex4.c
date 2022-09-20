#include "button.h"
#include "led.h"
#include "system.h"
#include "pio.h"        // version 2


int main (void)
{
    system_init ();

    led_init ();
    button_init ();

    while (1)
    {
        // VERSION 1
        /*
        if (button_pressed_p ())
        {
            led_on ();
        }
        else
        {
            led_off ();
        }
        */

        // VERSION 2
        //if (!pio_output_get(LED_PIO) && button_pressed_p() != 0) {
        if (!pio_output_get(LED_PIO) && button_pressed_p()) {  // if btn pressed when led is currently off...
            led_on();
        } else {
            led_off();
        }


    }
}
