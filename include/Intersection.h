#ifndef INTERSECTION
#define INTERSECTION

#include "Road.h"

class Intersection {

public:
    Road auxRoad;
    Road mainRoad;

    Intersection(Road auxRoad, Road mainRoad);

};

#endif