#include "../include/Semaphore.h"
#include "../include/Road.h"

Road::Road () {}

Road::Road (short *auxLights, short* mainLights,
            short minGreenTime, short pedestrianSensor,
            short carSensorN, short carSensorS) {
    this->auxSemaphore = Semaphore(auxLights);
    this->mainSemaphore = Semaphore(mainLights);
    this->minGreenTime = minGreenTime;
    this->maxGreenTime = minGreenTime * 2;
    this->pedestrianSensor = pedestrianSensor;
    this->carSensorA = carSensorN;
    this->carSensorB = carSensorS;
}

Road::Road (short *auxLights, short* mainLights,
            short minGreenTime, short pedestrianSensor,
            short* carSensorW, short* carSensorE) {
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
