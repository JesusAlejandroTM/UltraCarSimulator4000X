#include <stdlib.h>
#include <stdio.h>
#include "tools.h"


Point* point_create(int x, int y)
{
    Point *point = malloc(sizeof(Point));
    if (point == NULL) return NULL;
    point_set_location(point, x, y);
    return point;
}

void point_set_location(Point *point, int x, int y)
{
    point->x = x;
    point->y = y;
}

void point_move_by(Point *point, int dx, int dy)
{
    point->x = point->x + dx;
    point->y = point->y + dy;
}

void point_print_location(Point *point)
{
    printf("X: %d, Y: %d", point->x, point->y);
}