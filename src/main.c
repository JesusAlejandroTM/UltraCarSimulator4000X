#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "displayer.h"
#include "user_controller.h"
#include "tools.h"



int main(void)
{
    clear_screen();
    char small_parking[] = "maps/small_parking";
    char car[] = "vehicles/small_red_car";

    // Ideally we have to display a menu here first
    // where the User can select a mode

    display_map(small_parking);
    while (1)
    {
        char key = key_pressed();
        // Quit the program
        if (key == 'q')
        {
            return 0;
        }
        if (key == 'c')
        {
            display_object(car, 30, 7);
        }
    }

}