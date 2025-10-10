// parking_spot.c

#include "parking_spot.h"

static const MapVTable PARKING_SPOT_VTABLE = {
    .super = &MAP_OBJECT_VTABLE
};

static Point calculate_drawing_point(Point position)
{
    return position;
} 

ParkingSpot map_object_build(const char *name, int posX, int posY)
{
    Point pos = { .x = posX, .y = posY };
    Point drawing_pos = calculate_drawing_point(pos);

    ParkingSpot spot;

    spot.base.vptr = &PARKING_SPOT_VTABLE;
    spot.base.name = name;
    spot.base.position = pos;
    
    spot.drawing_position = drawing_pos;    

    return spot;
}
