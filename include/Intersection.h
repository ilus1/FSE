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
    bool checkForWaitingCar();
    void setIntersectionState (short auxRoadState, short mainRoadState);
    void checkAuxRoad(short minTime, short maxTime);
    void checkMainRoad(short minTime, short maxTime);
    void openMainRoad(short* state);
    void openAuxRoad(short* state);
    void slowDownMainRoad(short* state);
    void slowDownAuxRoad(short* state);
    void closeAuxRoad(short* state);
    void closeMainRoad(short* state);
    void closeBothRoads();
};

#endif