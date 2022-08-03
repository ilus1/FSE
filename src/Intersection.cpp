#include "../include/Road.h"
#include "../include/Intersection.h"

#include <iostream>

// const static short closeAuxRoad = 0;
// const static short openMainRoad = 1;
// const static short slowDownMainRoad = 2;
// const static short closeMainRoad = 3;
// const static short openAuxRoad = 4;
// const static short slowDownAuxRoad = 5;

const static short GREEN_LIGHT = 2;
const static short YELLOW_LIGHT = 1;
const static short REG_LIGHT = 0;

Intersection::Intersection (Road auxRoad, Road mainRoad) {
    this->auxRoad = auxRoad;
    this->mainRoad = mainRoad;
}

void Intersection::setIntersectionState (short auxRoadState, short mainRoadState) {
    this->auxRoad.getSemaphore().setSemaphoreState(auxRoadState);
    this->mainRoad.getSemaphore().setSemaphoreState(mainRoadState);
}

void Intersection::checkAuxRoad () {
    short timer = 0;
    bool waitingPedestrian = false;
    bool waitingCar = false;

    while (timer < this->auxRoad.getMinGreenTime()
        || (!waitingPedestrian && !waitingCar
            && timer < this->auxRoad.getMaxGreenTime())) {
        if (!waitingPedestrian) 
            waitingPedestrian = digitalRead(this->auxRoad.getPedestrianSensor()) == HIGH;
        if (!waitingCar)
            waitingCar = checkForWaitingCar();
        else if (checkForWaitingCar() != waitingCar) {
            this->auxRoad.redLightInfraction();
            waitingCar = false;
        }
        delay(200);
        timer += 200;
    }
}

void Intersection::checkMainRoad () {
    short timer = 0;
    bool waitingPedestrian = false;

    while (timer < this->mainRoad.getMinGreenTime()
        || (!waitingPedestrian && timer < this->mainRoad.getMaxGreenTime())) {
        if (!waitingPedestrian) waitingPedestrian = digitalRead(this->mainRoad.getPedestrianSensor()) == HIGH;
        delay(200);
        timer += 200;
    }
}

void Intersection::openMainRoad (short* state) {
    this->mainRoad.getSemaphore().setSemaphoreState(GREEN_LIGHT);
    *state = 2;
    checkAuxRoad();
}

void Intersection::openAuxRoad (short* state) {
    this->auxRoad.getSemaphore().setSemaphoreState(GREEN_LIGHT);
    *state = 5;
    checkMainRoad();
}

void Intersection::closeMainRoad (short* state) {
    *state = 4;
    this->mainRoad.getSemaphore().setSemaphoreState(REG_LIGHT);
    delay(1000);
}

void Intersection::closeAuxRoad (short* state) {
    *state = 1;
    this->auxRoad.getSemaphore().setSemaphoreState(REG_LIGHT);
    delay(1000);
}

void Intersection::slowDownMainRoad (short* state) {
    this->mainRoad.getSemaphore().setSemaphoreState(YELLOW_LIGHT);
    *state = 3;
    delay(3000);
}

void Intersection::slowDownAuxRoad (short* state) {
    this->auxRoad.getSemaphore().setSemaphoreState(YELLOW_LIGHT);
    *state = 0;
    delay(3000);
}

void Intersection::closeBothRoads () {
    this->auxRoad.getSemaphore().setSemaphoreState(REG_LIGHT);
    this->mainRoad.getSemaphore().setSemaphoreState(REG_LIGHT);
}

bool Intersection::checkForWaitingCar () {
    return digitalRead(this->auxRoad.getCarSensorA())
        || digitalRead(this->auxRoad.getCarSensorB());
}