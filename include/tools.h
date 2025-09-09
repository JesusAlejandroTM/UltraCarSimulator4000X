// Just un example de .h
// pour importer une fonction

#ifndef TOOLS_H
#define TOOLS_H

typedef struct Point Point;

void set_location(Point *point, int x, int y);
void print_location(Point *point);
Point* create_point(int x, int y);
int add(int a, int b);

#endif