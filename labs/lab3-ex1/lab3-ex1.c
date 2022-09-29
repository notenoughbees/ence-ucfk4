#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"


#define PACER_RATE 500
#define MESSAGE_RATE 10

int main (void)
{
    system_init();

    /* TODO: Initialise tinygl. */
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL); // Q3.6: needed to scroll text rather than display character frame-by-frame

    /* TODO: Set the message using tinygl_text().  */
    //char matrix_text[] = "A";
    //char matrix_text[] = "ABC";
    //char matrix_text[] = "Hello World!";
    char matrix_text[] = "HIT!";    // EXTRA
    tinygl_text(matrix_text);
    

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();
        
        /* TODO: Call the tinygl update function. */
        tinygl_update();
        
    }
    return 0;
}
