#include "button.h"
#include "led.h"
#include "system.h"
#include "pio.h"        // version 2


void led_toggle (int8_t prevLedState)
{
    if(prevLedState == 0) {
        led_on();
    } else {
        led_off();    
    }
}

int main (void)
{
    system_init ();

    led_init ();
    button_init ();

    int8_t prevLedState = 0;
    //int8_t ledState = 0;
    int8_t prevBtnState = 0;
    //int8_t currBtnState = 0;

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

        // VERSION 2: ATTEMPT 1
        /*
        if(button_pressed_p() != 0 && ledState == 0) {
            led_on();
            ledState = 1;
       }
       
        if(button_pressed_p() != 0 && ledState == 1) {
            led_off();
            ledState = 0;
        }
        */

        if(button_pressed_p()) {
            prevBtnState ^= 1;
            prevLedState ^= 1;
            // checks if current state of button == prev state of button
            if(button_pressed_p() != prevBtnState) {
                led_toggle(prevLedState);
            }
        }
    }




}
