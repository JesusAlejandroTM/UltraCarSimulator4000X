// map_object.c

#include "map_object.h"

const MapVTable MAP_OBJECT_VTABLE = {
    .super = NULL
};

const char *map_object_get_name(const MapObject *obj)
{ 
    return obj->name; 
}

void map_object_set_name(MapObject *obj, const char *name) 
{ 
    obj->name = name; 
}

Point map_object_get_position(const MapObject *obj)
{ 
    return obj->position; 
}

void map_object_set_position(MapObject *obj, Point p)
{
    obj->position = p;
}
