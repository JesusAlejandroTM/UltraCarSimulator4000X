// main.c

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "object_printer.h"
#include "window_manager.h"
#include "user_controller.h"
#include "tools.h"
#include "map_object.h"
#include "parking_spot.h"
#include "map_objects_interpreter.h"

int main(void)
{
    char small_parking[] = "maps/small_parking";
    // read_map_objects(small_parking);

    initscr();
    noecho();
    curs_set(0);
    clear();


    ParkingSpot spot = map_object_build("CAR_PARKING_SPOT", 30, 4);
        
    // Ideally we have to display a menu here first
    // where the User can select a mode

    if (check_terminal_size() == 0)
    {
        init_warning();
        char key =  getch();
        while (1) {
            if (key) {
                endwin();
                return 0;
            }
        }
    }

    init_introduction();
    while (1) {}
    
    init_simulator_gui();
    print_map(mid_sim_w, small_parking);

    while (1)
    {
        char key = getch();
        // Quit the program
        if (key == 'q' || key == 'Q') {
            endwin();
            return 0;
        }
        if (key == 'c' || key == 'C') {
            print_map_object(mid_sim_w, &spot.base);
        }
    }

}
