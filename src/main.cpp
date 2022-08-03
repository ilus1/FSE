#include "../include/Intersection.h"
#include "../include/Road.h"

short mainRoadSemaphore[2][3] = {{30, 21, 22}, {28, 27, 26}};
short auxRoadSemaphore[2][3] = {{8, 9, 14}, {31, 25, 29}};
short mainRoadMinGreenTime = 5000;
short auxRoadMinGreenTime = 10000;
short mainRoadPedestrian[2] = {13, 11};
short auxRoadPedestrian[2] = {12, 10};
short northCarSensor[2] = {7, 15};
short southCarSensor[2] = {0, 16};
short eastCarSensors[2][2] = {{2, 3}, {1, 4}};
short westCarSensors[2][2] = {{24, 23}, {5, 6}};


int main(void) {
    short intersectionState = 0;
    wiringPiSetup();

    Road auxRoad (auxRoadSemaphore[0], auxRoadMinGreenTime, auxRoadPedestrian[0], northCarSensor[0], southCarSensor[0]);
    Road mainRoad (mainRoadSemaphore[0], mainRoadMinGreenTime, mainRoadPedestrian[0], eastCarSensors[0], westCarSensors[0]);
    Intersection intersection = Intersection(auxRoad, mainRoad);

    intersection.closeBothRoads();
    while (intersectionState >= 0) {
        switch (intersectionState) {
            case 0: intersection.closeAuxRoad(&intersectionState);      break;
            case 1: intersection.openMainRoad(&intersectionState);      break;
            case 2: intersection.slowDownMainRoad(&intersectionState);  break;
            case 3: intersection.closeMainRoad(&intersectionState);     break;
            case 4: intersection.openAuxRoad(&intersectionState);       break;
            case 5: intersection.slowDownAuxRoad(&intersectionState);   break;
            case 6:
                while (intersectionState == 6) {
                    intersection.setIntersectionState(1, 1);
                    delay(1000);
                }
                break;
            case 7:
                intersection.setIntersectionState(1, 1);
                while (intersectionState == 7) {
                    delay(1000);
                }
                break;
        }
    }

    return 0;
}