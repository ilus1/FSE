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