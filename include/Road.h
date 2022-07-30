#ifndef ROAD
#define ROAD

#include "Semaphore.h"

class Road {

public:
    Semaphore semaphore;
    bool havePedestrian;

    Road(unsigned short *lights, unsigned short minGreenTime, bool isMainRoad);

};

#endif