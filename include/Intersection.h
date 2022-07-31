#ifndef INTERSECTION
#define INTERSECTION

#include "Road.h"

class Intersection {

private:
    Road auxRoad;
    Road mainRoad;


public:
    Intersection (Road auxRoad, Road mainRoad);

};

#endif