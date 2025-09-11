
#include <stdio.h>
#include <stdlib.h>
#include "map_objects.h"

void object_set_location(ParkingSpot *spot, int x, int y)
{
    spot->position.x = x;
    spot->position.y = y;
}

void object_print_location(ParkingSpot spot)
{

    int x = spot.position.x;
    int y = spot.position.y;

    printf("Name : %s\n, X : %d\n, Y : %d\n", spot.name, x, y);
}

Point calculate_drawing_point(Point position)
{
    return position;
} 

ParkingSpot object_build(char *name, int posX, int posY)
{
    Point pos = {
        .x = posX,
        .y = posY,
    };

    Point drawing_pos = calculate_drawing_point(pos);

    ParkingSpot spot = {
        .name = name,
        .position = pos,
        .drawing_position = drawing_pos,
    };

    return spot;
}
