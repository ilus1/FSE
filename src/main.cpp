#include "../include/Intersection.h"
#include "../include/Road.h"

short mainRoadSemaphore[2][3] = {{30, 21, 22}, {28, 27, 26}};
short auxRoadSemaphore[2][3] = {{8, 9, 14}, {31, 25, 29}};
short mainRoadMinGreenTime = 5000;
short auxRoadMinGreenTime = 10000;
short mainRoadPedestrian[2] = {13, 11};
short auxRoadPedestrian[2] = {12, 10};
short sensorCarroNorte[2] = {7, 15};
short sensorCarroSul[2] = {0, 16};
short velocidadeLeste[2][2] = {{2, 3}, {1, 4}};
short velocidadeOeste[2][2] = {{23, 24}, {5, 6}};


int main(void) {
    short intersectionState = 0;
    wiringPiSetup();

    Road auxRoad (auxRoadSemaphore[1], auxRoadMinGreenTime, auxRoadPedestrian[1], sensorCarroNorte[1], sensorCarroSul[1]);
    Road mainRoad (mainRoadSemaphore[1], mainRoadMinGreenTime, mainRoadPedestrian[1], velocidadeLeste[1], velocidadeOeste[1]);
    Intersection intersection = Intersection(auxRoad, mainRoad);

    intersection.closeBothRoads();
    while (intersectionState >= 0) {
        switch (intersectionState) {
            case 0: intersection.closeAuxRoad(&intersectionState); break;
            case 1: intersection.openMainRoad(&intersectionState); break;
            case 2: intersection.slowDownMainRoad(&intersectionState); break;
            case 3: intersection.closeMainRoad(&intersectionState); break;
            case 4: intersection.openAuxRoad(&intersectionState); break;
            case 5: intersection.slowDownAuxRoad(&intersectionState); break;
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