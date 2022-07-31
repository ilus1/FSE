#ifndef ROAD
#define ROAD

#include "Semaphore.h"

class Road {

private:
    Semaphore semaphore;
    short minGreenTime;
    short maxGreenTime;
    short pedestrianSensor;
    short carSensorA;
    short carSensorA2;
    short carSensorB;
    short carSensorB2;

public:
    Road ();
    Road (short* lights, short minGreenTime, short waitingPedestrian, short carSensorN, short carSensorS);    
    Road (short* lights, short minGreenTime, short waitingPedestrian, short* velocitySensorW, short* velocitySensorE);
    void portSetup (short port, short state);
    void portSetup (short* port, short state);
    Semaphore getSemaphore ();
};

#endif