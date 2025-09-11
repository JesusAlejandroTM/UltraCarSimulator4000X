#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "printer.h"
#include "user_controller.h"
#include "tools.h"
#include "map_objects.h"


int main(void)
{
    clear_screen();

    ParkingSpot spot = object_build("CAR_PARKING_SPOT", 30, 4);

    char small_parking[] = "maps/small_parking";

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
            print_object(spot);
        }
    }

}