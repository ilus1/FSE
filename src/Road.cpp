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
    wiringPiISR(carSensorW[0], INT_EDGE_FALLING, movingCarDetection);

    this->portSetup(carSensorE[0], INPUT);
    this->carSensorB = carSensorE[0];

    this->portSetup(carSensorE[1], INPUT);
    this->carSensorB2 = carSensorE[1];
    wiringPiISR(carSensorE[1], INT_EDGE_FALLING, movingCarDetection);

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

short Road::getPedestrianSensor () {
    return this->pedestrianSensor;
}

short Road::getMinGreenTime () {
    return this->minGreenTime;
}

short Road::getMaxGreenTime () {
    return this->maxGreenTime;
}

short Road::getCarSensorA () {
    return this->carSensorA;
}

short Road::getCarSensorA2 () {
    return this->carSensorA2;
}

short Road::getCarSensorB () {
    return this->carSensorB;
}

short Road::getCarSensorB2 () {
    return this->carSensorB2;
}

void movingCarDetection() {
    this->timer = std::chrono::high_resolution_clock::now();
    wirinPiISR (this->carSensorA2, INT_EDGE_FALLING, calculateVelocity);
}

void calculateSpeed() {
    std::chrono::duration<float> interval = std::chrono::high_resolution_clock::now() - this->timer;

    speed = 3.6 * 1/interval.count();

    std::cout << "velocidade: "  << speed << std::endl;
}

short secondVelocitySensor() {
    this->velocityTimer =
}