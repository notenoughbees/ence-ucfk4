#ifndef TIMER_H
#define TIMER_H

#define CPU_FREQ 8000000
#define TIMER1_PRESCALE 1024

#include "system.h"

/* Initialise timer.  */
void timer_init (void);


/* Wait for the specified length of time.  */
void timer_delay_ms (uint16_t milliseconds);

#endif
