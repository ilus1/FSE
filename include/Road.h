#ifndef ROAD
#define ROAD

#include "Semaphore.h"

class Road {

private:
    Semaphore auxSemaphore;
    Semaphore mainSemaphore;
    short minGreenTime;
    short maxGreenTime;
    short pedestrianSensor;
    short carSensorA;
    short carSensorA2;
    short carSensorB;
    short carSensorB2;

public:
    Road ();
    Road (short* auxLights, short* mainLights, short minGreenTime, short waitingPedestrian, short carSensorN, short carSensorS);    
    Road (short* auxLights, short* mainLights, short minGreenTime, short waitingPedestrian, short* velocitySensorW, short* velocitySensorE);
};

#endif