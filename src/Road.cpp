#include "../include/Semaphore.h"
#include "../include/Road.h"

Road::Road () {}

Road::Road (short *lights, short minGreenTime, short pedestrianSensor,
            short carSensorN, short carSensorS) {
    this->semaphore = Semaphore(lights);

    this->minGreenTime = minGreenTime;
    this->maxGreenTime = minGreenTime * 2;

    this->portSetup(pedestrianSensor, INPUT);
    this->pedestrianSensor = pedestrianSensor;

    this->portSetup(carSensorN, INPUT);
    this->carSensorA = carSensorN;

    this->portSetup(carSensorS, INPUT);
    this->carSensorB = carSensorS;
}

Road::Road (short *lights, short minGreenTime, short pedestrianSensor,
            short* carSensorW, short* carSensorE) {
    this->semaphore = Semaphore(lights);

    this->minGreenTime = minGreenTime;
    this->maxGreenTime = minGreenTime * 2;

    this->portSetup(pedestrianSensor, INPUT);
    this->pedestrianSensor = pedestrianSensor;

    this->portSetup(carSensorW[0], INPUT);
    this->carSensorA = carSensorW[0];

    this->portSetup(carSensorW[1], INPUT);
    this->carSensorA2 = carSensorW[1];

    this->portSetup(carSensorE[0], INPUT);
    this->carSensorB = carSensorE[0];

    this->portSetup(carSensorE[1], INPUT);
    this->carSensorB2 = carSensorE[1];
}

void Road::portSetup (short port, short state) {
    pinMode (port, state);
}

void Road::portSetup (short* ports, short state) {
    for (int i = 0; i < 2; i++)
        pinMode (ports[i], state);
}

Semaphore Road::getSemaphore () {
    return this->semaphore;
}