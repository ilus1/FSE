#include "../include/Road.h"
#include "../include/Intersection.h"


Intersection::Intersection (Road auxRoad, Road mainRoad) {
    this->auxRoad = auxRoad;
    this->mainRoad = mainRoad;
}

void Intersection::setIntersectionState (short auxRoadState, short mainRoadState) {
    auxRoad.getSemaphore().setSemaphoreState(auxRoadState);
    mainRoad.getSemaphore().setSemaphoreState(mainRoadState);
}

void Intersection::checkAuxRoad () {
    short timer = 0;
    bool waitingPedestrian = false;

    if (timer < this->auxRoad.getMinGreenTime()
        || (!waitingPedestrian && timer < this->auxRoad.getMaxGreenTime())) {
        waitingPedestrian = digitalRead(this->auxRoad.getPedestrianSensor()) == HIGH;
        delay(200);
        timer += 200;
    }
}

void Intersection::checkMainRoad () {
    short timer = 0;
    bool waitingPedestrian = false;

    if (timer < this->mainRoad.getMinGreenTime()
        || (!waitingPedestrian && timer < this->mainRoad.getMaxGreenTime())) {
        waitingPedestrian = digitalRead(this->mainRoad.getPedestrianSensor()) == HIGH;
        delay(200);
        timer += 200;
    }
}