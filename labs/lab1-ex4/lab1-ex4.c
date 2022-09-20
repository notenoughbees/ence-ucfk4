#include "button.h"
#include "led.h"
#include "system.h"
#include "pio.h"        // version 2


int main (void)
{
    system_init ();

    led_init ();
    button_init ();

    int8_t ledState = 0;

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
        /*
        //if (!pio_output_get(LED_PIO) && button_pressed_p() != 0) {
        if (button_pressed_p() && !pio_output_get(LED_PIO)) {  // if btn pressed when led is currently off...
            led_on();
            if(button_pressed_p() && pio_output_get(LED_PIO)) {
                led_off();
            }
        } else {
            led_off();
        }
        */

        if(button_pressed_p() != 0 && ledState == 0) {
            led_on();
            ledState = 1;
       }
       
        if(button_pressed_p() != 0 && ledState == 1) {
            led_off();
            ledState = 0;
        }


    }
}
