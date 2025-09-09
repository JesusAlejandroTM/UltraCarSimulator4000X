#include <tools.h>

typedef struct {
    char *name;
    Point *position;
} MapObject;

typedef struct {
    MapObject object;
    Point *drawingPoint;
} ParkingSpot;

