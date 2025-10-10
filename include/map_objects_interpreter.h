// map_objects_interpreter.h

#ifndef MAP_OBJECTS_INTERPRETER_H
#define MAP_OBJECTS_INTERPRETER_H

#include "tools.h"
#include "assets_manager.h"
#include "object_printer.h"

void read_map_objects(char *map_asset_name);
char *fetch_asset_name(char *map_asset_name, int count);

#endif