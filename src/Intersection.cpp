#include "../include/Road.h"
#include "../include/Intersection.h"


Intersection::Intersection (Road auxRoad, Road mainRoad) {
    this->auxRoad = auxRoad;
    this->mainRoad = mainRoad;
}