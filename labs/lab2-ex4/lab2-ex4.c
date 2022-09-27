#include "system.h"
#include "pio.h"

/* Include the pacer module from the previous lab.
   You must have completed this before starting this lab2-exercise.  */
#include "pacer.h"

int8_t three_corners(int8_t state) {
    /*
    if (state == 0) {
        // drive row1, row7, col1 high: this turns on the 2 leds in the first col
        pio_output_low(LEDMAT_ROW1_PIO);
        pio_output_low(LEDMAT_ROW7_PIO);
        pio_output_low(LEDMAT_COL1_PIO);
    } else {
        // drive row1, col5 high: this turns on the one led in the last col
        pio_output_low(LEDMAT_ROW1_PIO);
        pio_output_low(LEDMAT_COL5_PIO);
    }
    state = !state;


    pio_output_set (leds_cfg[led].pio,
                leds_cfg[led].active_high ? state : !state);
    */

    /*
    pio_output_set(LEDMAT_ROW1_PIO, state);
    pio_output_set(LEDMAT_ROW7_PIO, state);
    pio_output_set(LEDMAT_COL1_PIO, state);

    pio_output_set(LEDMAT_ROW1_PIO, state);
    pio_output_set(LEDMAT_COL5_PIO, state);
    */

    if (state == 0) {
        // drive row1, row7, col1 high: this turns on the 2 leds in the first col
        pio_output_low(LEDMAT_ROW1_PIO);
        pio_output_low(LEDMAT_ROW7_PIO);
        pio_output_high(LEDMAT_ROW2_PIO);
        pio_output_high(LEDMAT_ROW3_PIO);
        pio_output_high(LEDMAT_ROW4_PIO);
        pio_output_high(LEDMAT_ROW5_PIO);
        pio_output_high(LEDMAT_ROW6_PIO);

        pio_output_low(LEDMAT_COL1_PIO);
        pio_output_high(LEDMAT_COL2_PIO);
        pio_output_high(LEDMAT_COL3_PIO);
        pio_output_high(LEDMAT_COL4_PIO);
        pio_output_high(LEDMAT_COL5_PIO);
    } else {
        // drive row1, col5 high: this turns on the one led in the last col
        pio_output_low(LEDMAT_ROW1_PIO);
        pio_output_high(LEDMAT_ROW2_PIO);
        pio_output_high(LEDMAT_ROW3_PIO);
        pio_output_high(LEDMAT_ROW4_PIO);
        pio_output_high(LEDMAT_ROW5_PIO);
        pio_output_high(LEDMAT_ROW6_PIO);
        pio_output_high(LEDMAT_ROW7_PIO);

        pio_output_low(LEDMAT_COL5_PIO);
        pio_output_high(LEDMAT_COL1_PIO);
        pio_output_high(LEDMAT_COL2_PIO);
        pio_output_high(LEDMAT_COL3_PIO);
        pio_output_high(LEDMAT_COL4_PIO);
    }
    state ^= 1;
    return state;

}

int main (void)
{
    system_init ();
    int8_t state = 0;   // state is always 0. we get the other state by doing !state.
    
    /* TODO: Initialise the pins of the LED matrix.  */
    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_HIGH);

    /* Set up pacer with a frequency of 50 Hz.  */
    pacer_init (80); // 80 default. Set to eg 1 to see the states toggling

    while (1)
    {
        /* Pace the loop.  */
        pacer_wait ();
        
        /* TODO: Drive the LED matrix using the pio functions,
           displaying only three corner LEDs.  */
        state = three_corners(state);
    }
}
