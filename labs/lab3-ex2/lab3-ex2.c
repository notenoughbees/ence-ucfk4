#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include <stdint.h>

#define PACER_RATE 500
#define MESSAGE_RATE 10


void display_character (char character)
{
    char buffer[2];

    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


int main (void)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int8_t character_index = 0;
    char character = alphabet[character_index];

    system_init ();

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);

    /* TODO: Initialise navigation switch driver.  */
    navswitch_init();

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait ();
        tinygl_update ();
        
        /* TODO: Call the navswitch update function.  */
        navswitch_update();

        
        /* TODO: Increment character if NORTH is pressed.  */
        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            character_index++;
            if (character_index > 25) {
                character_index = 0; 
            }
            character = alphabet[character_index];  
        }
        
        /* TODO: Decrement character if SOUTH is pressed.  */
        if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            character_index--;
            if (character_index < 0) {
                character_index = 25;       
            }
            character = alphabet[character_index];  
        }
        
        display_character (character);
    }
    return 0;
}
