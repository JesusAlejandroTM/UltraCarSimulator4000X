#include <stdlib.h>
#include <stdio.h>
#include "tools.h"


struct Point {
    int x;
    int y;
};

Point* create_point(int x, int y)
{
    Point *point = malloc(sizeof(Point));
    if (point == NULL) return NULL;
    set_location(point, x, y);
    return point;
}

void set_location(Point *point, int x, int y)
{
    point->x = x;
    point->y = y;
}

void print_location(Point *point)
{
    printf("X: %d, Y: %d", point->x, point->y);
}


int add(int a, int b)
{
    return a + b;
}