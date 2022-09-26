#include <avr/io.h>
#include "pacer.h"

static uint16_t pacer_period;

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency)
{
    /* TODO: initialise timer/counter peripheral the
       same way as in lab2/lab2-ex2/timer.c but also calculate 
       the timer/counter value from the pacer frequency */
        TCCR1A = 0x00;
        TCCR1B = 0x05;
        TCCR1C = 0x00;

        // frequency measured in Hz but period measured in s, 
        //  so to get period, must convert seconds to ticks
        //uint16_t ticks = milliseconds * (CPU_FREQ / TIMER1_PRESCALE) / 1000;
        uint16_t ticks = 1 * (CPU_FREQ / TIMER1_PRESCALE);  // 1: delay in seconds
        pacer_period = ticks / pacer_frequency;  // period = reciprocal of frequency: http://www.differencebetween.net/science/mathematics-statistics/difference-between-period-and-frequency/

}


/* Pace a while loop.  */
void pacer_wait (void)
{
    /* TODO: Implement the same way as the timer_delay () function 
       lab2-except reset TCNT1 after the while loop. */

        // TCNT1 = counter value
        while (TCNT1 < pacer_period) {  // pacer_period (measured in ticks) instead of ticks
            continue;
        }
        TCNT1 = 0;
}
