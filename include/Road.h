#ifndef ROAD
#define ROAD

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
    vector<vector<short>> carRecord;

public:
    static std::chrono::time_point<std::chrono::high_resolution_clock> velocityTimer;

    Road ();
    Road (short* lights, short minGreenTime, short waitingPedestrian, short carSensorN, short carSensorS);    
    Road (short* lights, short minGreenTime, short waitingPedestrian, short* velocitySensorW, short* velocitySensorE);
    void portSetup (short port, short state);
    void portSetup (short* port, short state);
    void movingCarDetection();
    void calculateSpeed();
    short getPedestrianSensor ();
    short getMinGreenTime ();
    short getMaxGreenTime ();
    short getCarSensorA ();
    short getCarSensorA2 ();
    short getCarSensorB ();
    short getCarSensorB2 ();
    Semaphore getSemaphore ();
};

#endif