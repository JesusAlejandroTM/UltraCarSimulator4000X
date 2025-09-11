#ifndef MAP_OBJECTS_H
#define MAP_OBJECTS_H

#include "tools.h"

// typedef enum 
// {
//     ParkingSpot,
//     Car,
// } MapObjectTypes;

// typedef struct 
// {
//     MapObjectTypes type;
// } MapObject;

typedef struct 
{
    const char *name;
    Point position;
    Point drawing_position;
} ParkingSpot;

ParkingSpot object_build(char *name, int posX, int posY);
void object_print_location(ParkingSpot spot);

#endif