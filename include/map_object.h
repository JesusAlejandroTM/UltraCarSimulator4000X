// map_object.h

#ifndef MAP_OBJECT_H
#define MAP_OBJECT_H

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

struct MapObject;

typedef struct MapVTable {
    const struct MapVTable *super;
} MapVTable;

typedef struct MapObject {
    const MapVTable *vptr;
    const char *name;
    Point position;
} MapObject;

extern const MapVTable MAP_OBJECT_VTABLE;

/* Base getters/setters */
const char *map_object_get_name(const MapObject *obj);
void map_object_set_name(MapObject *obj, const char *name);
Point map_object_get_position(const MapObject *obj);
void map_object_set_position(MapObject *obj, Point p);

#endif
