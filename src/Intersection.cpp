#include "../include/Road.h"
#include "../include/Intersection.h"


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