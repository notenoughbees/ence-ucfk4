#include <avr/io.h>
#include "led.h"


/** Turn LED1 on.  */
void led_on (void)
{
    DDRC |= (1 << 2);   // 1 for on
}


/** Turn LED1 off.  */
void led_off (void)
{
    DDRC &= ( 1 << 2);  // 0 for off
}


/** Initialise LED1.  */
void led_init (void)
{
    PORTC |= (1 << 2);   // 1 for output
}
