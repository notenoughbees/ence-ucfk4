#include <avr/io.h>
#include "system.h"

/*
 * NOTES:
 - Once the LED is initialised, it is faintly on. Pressing the button then makes it brigher.
 - Blue LED is only on while button is pressed: the button does NOT toggle the state of the LED.
*/

int main (void)
{
    system_init ();

    /* Initialise port to drive LED 1.  */
    // set C2 to be an output pin
    // pin #2 corresponds to 3rd digit (we count the pin numbers from 0), so shift 1 over by 2 places
    PORTC |= (1 << 2);   

    while (1)
    {
        /* Turn LED 1 on.  */
        // set the state of the pin to 1: turn on the LED
        //DDRC |= (1 << 2);


        // VERSION 2
        // turn LED on if button is pressed, or off if button is not pressed.
        if((PIND & (1 << 7)) != 0) {
            DDRC |= (1 << 2);
        } else {
            DDRC &= !(1 << 2);
        }
    }
}
