// object_printer.h

#ifndef OBJECT_PRINTER_H
#define OBJECT_PRINTER_H

#define TOP_ANCHOR_POSITION 0
#define LEFT_ANCHOR_POSITION 0
#define TOP_SIMULATOR_ANCHOR_POSITION 1
#define LEFT_SIMULATOR_ANCHOR_POSITION 2

#include <ncurses.h>
#include "map_object.h"
#include "assets_manager.h"

void print_gui_element(const char *asset_file_path, int x, int y);
void print_map(WINDOW* win, const char *asset_file_path);
void print_map_object(WINDOW* win, const MapObject* spot);

#endif //PRINTER_H