#ifndef INTERSECTION
#define INTERSECTION

#include <wiringPi.h>

#include "Road.h"

class Intersection {

private:
    Road auxRoad;
    Road mainRoad;


public:
    Intersection (Road auxRoad, Road mainRoad);
    void setIntersectionState (short auxRoadState, short mainRoadState);
    void checkAuxRoad();
    void checkMainRoad();
};

#endif