#ifndef LED_H
#define LED_H

// macros
#define LED_PIO PIO_DEFINE (PORT_C, 2)

/** Turn LED1 on.  */
void led_on (void);


/** Turn LED1 off.  */
void led_off (void);


/** Initialise LED1.  */
void led_init (void);
#endif