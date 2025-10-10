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

    int start = 0;
    init_introduction();
    while (!start) {
        char key = getch();
        // Quit the program
        if (key == 'P' || key == 'p') {
            start = 1;
        }
    }

    clear();
    
    init_simulator_gui();
    print_map(mid_sim_w, small_parking);

    while (1)
    {
        char key = getch();
        // Quit the program
        if (key == 'x' || key == 'X') {
            endwin();
            return 0;
        }
        if (key == 'c' || key == 'C') {
            print_map_object(mid_sim_w, &spot.base);
        }
        if (key == 'x' || key == 'X') {
            delete_map_object(mid_sim_w, &spot.base);
        }
        if (key == 'z' || key == 'Z')
        {
            delete_map_object(mid_sim_w, &spot.base);
            spot.base.position.y += 1;
            print_map_object(mid_sim_w, &spot.base);
        }
        if (key == 'd' || key == 'D')
        {
            delete_map_object(mid_sim_w, &spot.base);
            spot.base.position.x += 1;
            print_map_object(mid_sim_w, &spot.base);
        }
        if (key == 'q' || key == 'Q')
        {
            delete_map_object(mid_sim_w, &spot.base);
            spot.base.position.x -= 1;
            print_map_object(mid_sim_w, &spot.base);
        }
        if (key == 's' || key == 'S')
        {
            delete_map_object(mid_sim_w, &spot.base);
            spot.base.position.y -= 1;
            print_map_object(mid_sim_w, &spot.base);
        }
    }

}
