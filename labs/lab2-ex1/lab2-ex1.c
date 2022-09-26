#include <avr/io.h>
#include "system.h"
#include "led.h"

void timer_delay(uint16_t ticks) {
    TCNT1 = 0;
    while (TCNT1 < ticks) {
        continue;
    }
}

int main (void)
{
    system_init ();
    led_init ();
    
    /* TODO: Initialise timer/counter1.  */
    TCCR1A = 0x00;
    TCCR1B = 0x05;  // binary: 00000101. Bit #5 to set timer freq to clk/1024.
    TCCR1C = 0x00;
    
    while (1)
    {
        /* Turn LED on.  */
        led_set (LED1, 1);
        
        /* TODO: wait for 500 milliseconds.  */
        //timer_delay(3906);  // 500ms = 3906 ticks
        //timer_delay(70);    // V2
        timer_delay(35);    // V3
        
        /* Turn LED off.  */
        led_set (LED1, 0);
        
        /* TODO: wait for 500 milliseconds.  */
        //timer_delay(3906);
        //timer_delay(70);    // V2
        timer_delay(105);    // V3

    }
    
}
