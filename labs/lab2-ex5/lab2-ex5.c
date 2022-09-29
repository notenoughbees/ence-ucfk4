#include <stdlib.h>
#include "system.h"
#include "pio.h"
#include "pacer.h"


/** Define PIO pins driving LED matrix rows.  */
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO, 
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};


/** Define PIO pins driving LED matrix columns.  */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};


static const uint8_t bitmap[] =
{
    0x30, 0x46, 0x40, 0x46, 0x30    // smiley
    //0x7F, 0x41, 0x5D, 0x51, 0x5F    // spiral
};


static void display_column (uint8_t row_pattern, uint8_t curr_column)
{
    /* TODO */
    static uint8_t prev_column = 4; // initialise to 4 since curr_column starts at 0
    // given: 0x30, 0

    // set the needed rows low (on)
    pio_output_high(cols[prev_column]);  // V2: from Q8.5: disable all active cols before setting the row pattern, to avoid ghosting!
    for(size_t curr_row = 0; curr_row < 7; curr_row++) {
        if ((row_pattern >> curr_row) & 1) {
            pio_output_low(rows[curr_row]);
        } else {
            pio_output_high(rows[curr_row]);
        }
    }    

    // set the needed column low (on), and the previous column high (off)
    pio_output_low(cols[curr_column]);

    // we must disable the prev col bc otherwise, all cols will end up being on, which will collide with the rows and result in *all rows in our bitmap that have an led being on all the time*
    pio_output_high(cols[prev_column]);
    prev_column++;
    if (prev_column > (LEDMAT_COLS_NUM - 1))
    {
        prev_column = 0; // cycle back to first column
    }  
}


int main (void)
{
    uint8_t current_column = 0;
  
    system_init ();
    pacer_init (500);
    
    /* TODO: Initialise LED matrix pins.  */
    for(size_t i = 0; i < 7; i++) {
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }
    for(size_t i = 0; i < 5; i++) {
        pio_config_set(cols[i], PIO_OUTPUT_HIGH);
    }
    

    while (1)
    {
        pacer_wait ();
        
        display_column (bitmap[current_column], current_column);
    
        current_column++;
    
        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0; // cycle back to first column
        }           
    }
}
