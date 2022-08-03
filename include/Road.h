#ifndef ROAD
#define ROAD

#include <chrono>
#include <vector>

#include "Semaphore.h"
#include "iostream"

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
    std::vector<std::vector<short>> carRecord;

public:

    Road ();
    Road (short* lights, short minGreenTime, short waitingPedestrian, short carSensorN, short carSensorS);    
    Road (short* lights, short minGreenTime, short waitingPedestrian, short* velocitySensorW, short* velocitySensorE);
    void portSetup (short port, short state);
    void portSetup (short* port, short state);
    short getPedestrianSensor ();
    short getMinGreenTime ();
    short getMaxGreenTime ();
    short getCarSensorA ();
    short getCarSensorA2 ();
    short getCarSensorB ();
    short getCarSensorB2 ();
    void redLightInfraction();
    Semaphore getSemaphore ();
};

#endif