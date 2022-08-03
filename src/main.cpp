#include <thread>

#include "../include/Intersection.h"
#include "../include/Road.h"

short mainRoadSemaphore[2][3] = {{30, 21, 22}, {28, 27, 26}};
short auxRoadSemaphore[2][3] = {{8, 9, 14}, {31, 25, 29}};
short mainRoadMinGreenTime = 5000;
short auxRoadMinGreenTime = 10000;
short mainRoadPedestrian[2] = {12, 10};
short auxRoadPedestrian[2] = {13, 11};
short northCarSensor[2] = {7, 15};
short southCarSensor[2] = {0, 16};
short eastCarSensors[2][2] = {{2, 3}, {1, 4}};
short westCarSensors[2][2] = {{24, 23}, {5, 6}};


void intersectionControl (int i) {
    short intersectionState = 0;

    Road auxRoad (auxRoadSemaphore[i], auxRoadMinGreenTime, auxRoadPedestrian[i], northCarSensor[i], southCarSensor[i]);
    Road mainRoad (mainRoadSemaphore[i], mainRoadMinGreenTime, mainRoadPedestrian[i], eastCarSensors[i], westCarSensors[i]);
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
                    intersection.closeBothRoads();
                    delay(500);
                }
                break;
            case 7:
                intersection.setIntersectionState(0, 2);
                while (intersectionState == 7) {
                    delay(1000);
                }
                break;
        }
    }
}


int main (void) {
    wiringPiSetup();

    std::thread intersection1(intersectionControl, 0);
    std::thread intersection2(intersectionControl, 1);

    intersection1.join();
    intersection2.join();

    return 0;
}


