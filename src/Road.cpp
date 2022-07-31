#include "../include/Semaphore.h"
#include "../include/Road.h"

Road::Road () {}

Road::Road (unsigned short *auxlights, unsigned short* mainLights,
            unsigned short minGreenTime, unsigned short pedestrianSensor,
            unsigned short carSensorN, unsigned short carSensorS) {
    this->auxSemaphore = Semaphore(auxLights);
    this->mainSemaphore = Semaphore(mainLights);
    this->minGreenTime = minGreenTime;
    this->maxGreenTime = minGreenTime * 2;
    this->pedestrianSensor = pedestrianSensor;
    this->carSensorA = carSensorN;
    this->carSensorB = carSensorS;
}

Road::Road (unsigned short *auxLights, unsigned short* mainLights,
            unsigned short minGreenTime, unsigned short pedestrianSensor,
            unsigned short* carSensorW, unsigned short* carSensorE) {
    this->auxSemaphore = Semaphore(auxLights);
    this->mainSemaphore = Semaphore(mainLights);
    this->minGreenTime = minGreenTime;
    this->maxGreenTime = minGreenTime * 2;
    this->pedestrianSensor = pedestrianSensor;
    this->carSensorA = carSensorW[0];
    this->carSensorA2 = carSensorW[1];
    this->carSensorB = carSensorE[0];
    this->carSensorB2 = carSensorE[1];
}
