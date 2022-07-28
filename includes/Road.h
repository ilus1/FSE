#ifndef ROAD
#define ROAD

#include "Semaphore.h"

class Road {

public:
    Semaphore auxRoadSemaphore;
    Semaphore mainRoadSemaphore;
    unsigned short waitingCard;

    Road(unsigned short *lights, unsigned short minGreenTime, bool isMainRoad);
    short setMinGreenTime(unsigned short minGreenTime);
};

#endif