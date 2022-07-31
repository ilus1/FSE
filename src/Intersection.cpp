#include "../include/Road.h"
#include "../include/Intersection.h"

short bothRoadsClosed_main = 0;
short mainRoadOpen = 1;
short slowDownMainRoad = 2;
short bothRoadsClosed_aux = 3;
short auxRoadOpen = 4;
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

    while (timer < this->auxRoad.getMinGreenTime()
        || (!waitingPedestrian && timer < this->auxRoad.getMaxGreenTime())) {
        if (!waitingPedestrian) waitingPedestrian = digitalRead(this->auxRoad.getPedestrianSensor()) == HIGH;
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
    *state = mainRoadOpen;
    checkAuxRoad();
}

void Intersection::openAuxRoad (short* state) {
    this->auxRoad.getSemaphore().setSemaphoreState(greenLight);
    *state = auxRoadOpen;
    checkMainRoad();
}

void Intersection::bothRoadsClosed (short* state) {
    if (*state == slowDownMainRoad) {
        *state = bothRoadsClosed_aux;
        this->mainRoad.getSemaphore().setSemaphoreState(redLight);
    } else if (*state == slowDownAuxRoad) {
        *state = bothRoadsClosed_main;
        this->auxRoad.getSemaphore().setSemaphoreState(redLight);
    }
    delay(1000);
}

void Intersection::slowDownMainRoad (short* state) {
    this->mainRoad.getSemaphore().setSemaphoreState(yellowLight);
    *state = slowDownMainRoad;
    delay(3000);
}

void Intersection::slowDownAuxRoad (short* state) {
    this->auxRoad.getSemaphore().setSemaphoreState(yellowLight);
    *state = slowDownAuxRoad;
    delay(3000);
}