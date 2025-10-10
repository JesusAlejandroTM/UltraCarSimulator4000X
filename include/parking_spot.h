// parking_spot.h

#ifndef PARKING_SPOT_H
#define PARKING_SPOT_H
#include "map_object.h"

typedef struct ParkingSpot {
    MapObject base;      // first field for upcast
    Point drawing_position;
} ParkingSpot;


ParkingSpot map_object_build(const char *name, int posX, int posY);

#endif
