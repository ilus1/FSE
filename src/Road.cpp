#include "../include/Semaphore.h"
#include "../include/Road.h"

Road::Road () {}

Road::Road (unsigned short *lights, unsigned short minGreenTime, unsigned short pedestrianSensor, unsigned short carSensorN, unsigned short carSensorS) {
    this->semaphore = Semaphore(lights);
    this->minGreenTime = minGreenTime;
    this->maxGreenTime = minGreenTime * 2;
    this->pedestrianSensor = pedestrianSensor;
    this->carSensorA = carSensorN;
    this->carSensorB = carSensorS;
}

Road::Road (unsigned short *lights, unsigned short minGreenTime, unsigned short pedestrianSensor, unsigned short* carSensorW, unsigned short* carSensorE) {
    this->semaphore = Semaphore(lights);
    this->minGreenTime = minGreenTime;
    this->maxGreenTime = minGreenTime * 2;
    this->pedestrianSensor = pedestrianSensor;
    this->carSensorA = carSensorW[0];
    this->carSensorA2 = carSensorW[1];
    this->carSensorB = carSensorE[0];
    this->carSensorB2 = carSensorE[1];
}
