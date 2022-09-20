#include "pio.h"
#include "led.h"


/** Turn LED1 on.  */
void led_on (void)
{
    pio_output_high(LED_PIO);  // high for on
}


/** Turn LED1 off.  */
void led_off (void)
{
    pio_output_low(LED_PIO);  // low for off
}


/** Initialise LED1.  */
void led_init (void)
{
    pio_config_set(LED_PIO, PIO_OUTPUT_LOW);
}