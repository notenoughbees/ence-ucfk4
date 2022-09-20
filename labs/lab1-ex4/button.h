#ifndef BUTTON_H
#define BUTTON_H

//macros
#define BTN_PIO PIO_DEFINE (PORT_D, 7)

/** Return non-zero if button pressed.  */
int button_pressed_p (void);


/** Initialise button1.  */
void button_init (void);
#endif