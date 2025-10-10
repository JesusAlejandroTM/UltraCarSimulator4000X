// assets_manager.h

#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

#include "map_object.h"

char *format_file_path(const char *asset_file_path);
char *format_map_objects_file_path(const char *asset_file_path);
char* get_object_asset_name(MapObject spot);

#endif