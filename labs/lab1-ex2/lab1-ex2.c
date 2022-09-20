#include <avr/io.h>
#include "system.h"

static void led_init (void)
{
    /* Initialise port to drive LED 1.  */
    PORTC |= (1 << 2);  // set bit for pin 2 to 1 (for output)
}


static void led_on (void)
{
    /* Set port to turn LED 1 on.  */
    DDRC |= (1 << 2);   // set bit for pin 2 to 1 (for ON)
}


static void led_off (void)
{
    /* Set port to turn LED 1 off.  */
    DDRC &= !(1 << 2);  // set bit for pin 2 to 0 (for OFF)
}



static void button_init (void)
{
    /* Initialise port to read button 1.  */
    PORTD &= !(1 << 7); // set bit for pin 7 to 0 (for input)
}


static int button_pressed_p (void)
{
    /* Return non-zero if button pressed_p.  */
    return (PIND & (1 << 7)) != 0;  // return 1 if button is ON, else 0
                                    //   button is an input, so use PINX.
}


int main (void)
{
    system_init ();

    led_init ();
    button_init ();

    while (1)
    {
        if (button_pressed_p ())
        {
            led_on ();
        }
        else
        {
            led_off ();
        }
    }
}
