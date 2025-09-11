#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "printer.h"
#include "user_controller.h"
#include "tools.h"
#include "map_objects.h"


int main(void)
{
    ParkingSpot spot = object_build("SMALL_PARKING", 10, 10);

    object_print_location(spot);

    getchar();

    clear_screen();
    char small_parking[] = "maps/small_parking";
    char car[] = "vehicles/small_red_car";
    char test[] = "vehicles/test";

    // Ideally we have to display a menu here first
    // where the User can select a mode

    print_map(small_parking);
    while (1)
    {
        char key = key_pressed();
        // Quit the program
        if (key == 'q' | key == 'Q')
        {
            return 0;
        }
        if (key == 'c' | key == 'C')
        {
            print_object(car, 30, 4);
        }
    }

}