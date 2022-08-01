#include "../include/Road.h"
#include "../include/Intersection.h"

short closeAuxRoad = 0;
short openMainRoad = 1;
short slowDownMainRoad = 2;
short closeMainRoad = 3;
short openAuxRoad = 4;
short slowDownAuxRoad = 5;

short greenLight = 2;
short yellowLight = 1;
short redLight = 0;

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
        if (!waitingPedestrian) waitingPedestrian = digitalRead(this->auxRoad.getPedestrianSensor()) == HIGH;
        if (!waitingCar) waitingCar = checkForWaitingCar();
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
    this->mainRoad.getSemaphore().setSemaphoreState(greenLight);
    *state = 2;
    checkAuxRoad();
}

void Intersection::openAuxRoad (short* state) {
    this->auxRoad.getSemaphore().setSemaphoreState(greenLight);
    *state = 5;
    checkMainRoad();
}

void Intersection::closeMainRoad (short* state) {
    *state = 4;
    this->mainRoad.getSemaphore().setSemaphoreState(redLight);
    delay(1000);
}

void Intersection::closeAuxRoad (short* state) {
    *state = 1;
    this->auxRoad.getSemaphore().setSemaphoreState(redLight);
    delay(1000);
}

void Intersection::slowDownMainRoad (short* state) {
    this->mainRoad.getSemaphore().setSemaphoreState(yellowLight);
    *state = 3;
    delay(3000);
}

void Intersection::slowDownAuxRoad (short* state) {
    this->auxRoad.getSemaphore().setSemaphoreState(yellowLight);
    *state = 0;
    delay(3000);
}

void Intersection::closeBothRoads () {
    this->auxRoad.getSemaphore().setSemaphoreState(redLight);
    this->mainRoad.getSemaphore().setSemaphoreState(redLight);
}

bool Intersection::checkForWaitingCar () {
    return digitalRead(this->auxRoad.getCarSensorA())
        || digitalRead(this->auxRoad.getCarSensorB());
}