#include "pio.h"
#include "system.h"

// supposed to be a spiral
void test1(void) {
    // leg 1
    pio_output_low(LEDMAT_ROW1_PIO);
    pio_output_low(LEDMAT_ROW2_PIO);
    pio_output_low(LEDMAT_ROW3_PIO);
    pio_output_low(LEDMAT_ROW4_PIO);
    pio_output_low(LEDMAT_ROW5_PIO);
    pio_output_low(LEDMAT_ROW6_PIO);
    pio_output_low(LEDMAT_ROW7_PIO);
    pio_output_low(LEDMAT_COL1_PIO);
    // leg 2
    pio_output_low(LEDMAT_ROW7_PIO);
    pio_output_low(LEDMAT_COL1_PIO);
    pio_output_low(LEDMAT_COL2_PIO);
    pio_output_low(LEDMAT_COL3_PIO);
    pio_output_low(LEDMAT_COL4_PIO);
    pio_output_low(LEDMAT_COL5_PIO);
    /*
    // leg 3
    pio_output_low(LEDMAT_ROW6_PIO);
    pio_output_low(LEDMAT_COL5_PIO);
    pio_output_low(LEDMAT_ROW5_PIO);
    pio_output_low(LEDMAT_COL5_PIO);
    pio_output_low(LEDMAT_ROW4_PIO);
    pio_output_low(LEDMAT_COL5_PIO);
    pio_output_low(LEDMAT_ROW3_PIO);
    pio_output_low(LEDMAT_COL5_PIO);
    pio_output_low(LEDMAT_ROW2_PIO);
    pio_output_low(LEDMAT_COL5_PIO);
    // leg 4
    pio_output_low(LEDMAT_ROW2_PIO);
    pio_output_low(LEDMAT_COL4_PIO);
    pio_output_low(LEDMAT_ROW2_PIO);
    pio_output_low(LEDMAT_COL3_PIO);
    // leg 5
    pio_output_low(LEDMAT_ROW3_PIO);
    pio_output_low(LEDMAT_COL3_PIO);
    pio_output_low(LEDMAT_ROW4_PIO);
    pio_output_low(LEDMAT_COL3_PIO);
    pio_output_low(LEDMAT_ROW5_PIO);
    pio_output_low(LEDMAT_COL3_PIO);
    */
}

// supposed to be a 2-square diagonal
void test2(void) {
    pio_output_low(LEDMAT_ROW1_PIO);
    pio_output_low(LEDMAT_COL1_PIO);

    pio_output_low(LEDMAT_ROW2_PIO);
    pio_output_low(LEDMAT_COL2_PIO);
}

void test3(void) {
    pio_output_low(LEDMAT_ROW2_PIO);
    pio_output_low(LEDMAT_COL1_PIO);

    pio_output_low(LEDMAT_ROW6_PIO);
    pio_output_low(LEDMAT_COL5_PIO);
}




void matrix_init(void) {
    // set all LEDs to high initially: all cols (5) and all rows (7) = 12 lines total
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
}

/** Turn LED in row1, col1 of matrix on.  */
void ledmat11_on(void) {
    pio_output_low(LEDMAT_ROW1_PIO);
    pio_output_low(LEDMAT_COL1_PIO);
}

/** Turn all LEDS in the left column - col 1 - on. */
void ledmat_col1_on(void) {
    // we need 7 LEDs to be on, so we need 7 places where a row and col cross: we need 7 lines for the rows
    pio_output_low(LEDMAT_ROW1_PIO);
    pio_output_low(LEDMAT_ROW2_PIO);
    pio_output_low(LEDMAT_ROW3_PIO);
    pio_output_low(LEDMAT_ROW4_PIO);
    pio_output_low(LEDMAT_ROW5_PIO);
    pio_output_low(LEDMAT_ROW6_PIO);
    pio_output_low(LEDMAT_ROW7_PIO);
    pio_output_low(LEDMAT_COL1_PIO);
}




int main(void)
{
    system_init();
    matrix_init();
    
    while (1)
    {
        /* TODO.  Use PIO module to turn on LEDs in
           LED matrix.  */

        //ledmat11_on();            // ex10.2
        //ledmat_col1_on();         // ex10.3

        test3();
        
    }
}
