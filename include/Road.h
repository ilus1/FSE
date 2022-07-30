#ifndef ROAD
#define ROAD

#include "Semaphore.h"

class Road {

private:
    Semaphore semaphore;
    unsigned short minGreenTime;
    unsigned short maxGreenTime;
    unsigned short pedestrianSensor;
    unsigned short carSensorA;
    unsigned short carSensorA2;
    unsigned short carSensorB;
    unsigned short carSensorB2;

public:
    Road ();
    Road (unsigned short* lights, unsigned short minGreenTime, unsigned short waitingPedestrian, unsigned short carSensorN, unsigned short carSensorS);    
    Road (unsigned short* lights, unsigned short minGreenTime, unsigned short waitingPedestrian, unsigned short* velocitySensorW, unsigned short* velocitySensorE);
};

#endif