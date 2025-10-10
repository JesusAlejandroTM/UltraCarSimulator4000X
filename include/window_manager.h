// window_manager.h

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <ncurses.h>
#include "map_object.h"
#include "object_printer.h"
#include "assets_manager.h"

extern WINDOW *top_sim_w;
extern WINDOW *mid_sim_w;
extern WINDOW *bot_sim_w;

int check_terminal_size();
void init_simulator_gui();
void init_warning();
void init_introduction();

#endif //WINDOW_MANAGER_H