#include <tools.h>

typedef struct {
    char *name;
    int x;
    int y;
} MapObject;

typedef struct {
    char *name;
    int x;
    int y;
    Point *drawingPoint;
} ParkingSpot;

typedef struct {
    MapObject object;
    char *color;
} Vehicle;