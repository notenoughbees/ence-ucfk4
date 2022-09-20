#include "pio.h"
#include "button.h"


/** Return non-zero if button pressed.  */
int button_pressed_p (void)
{
    return pio_input_get(BTN_PIO);
}


/** Initialise button1.  */
void button_init (void)
{   
    // INPUT because a button is an input. Do NOT use output_low or output_high, these say if it is an output, & what its initial state is (low or high)
    // see pio.h: line 91: options for pio_config_set
    pio_config_set(BTN_PIO, PIO_INPUT);    
}