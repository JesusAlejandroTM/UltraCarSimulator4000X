#ifndef TOOLS_H
#define TOOLS_H

typedef struct {
    int x;
    int y;
} Point;

Point*  point_create(int x, int y);
void    point_set_location(Point *point, int x, int y);
void    point_move_by(Point *point, int dx, int dy);
void    point_print_location(Point *point);

#endif