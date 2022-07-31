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

short auxRoadRed = 0, mainRoadRed = 0;
short auxRoadYellow = 1, mainRpadYellow = 1;
short auxRoadGreen = 2, mainRoadGreen = 2;


int main(void) {
    short intersectionState = 0;
    wiringPiSetup();

    Road auxRoad (auxRoadSemaphore[1], auxRoadMinGreenTime, auxRoadPedestrian[1], sensorCarroNorte[1], sensorCarroSul[1]);
    Road mainRoad (mainRoadSemaphore[1], mainRoadMinGreenTime, mainRoadPedestrian[1], velocidadeLeste[1], velocidadeOeste[1]);
    Intersection intersection = Intersection(auxRoad, mainRoad);

    while (intersectionState >= 0) {
        switch (intersectionState) {
            case 0:
                intersectionState = 1;
                intersection.setIntersectionState(auxRoadRed, mainRoadRed);
                delay(1000);
                break;
            case 1:
                intersectionState = 2;
                intersection.setIntersectionState(auxRoadRed, mainRoadGreen);
                intersection.checkAuxRoad();
                break;
            case 2:
                intersectionState = 3;
                intersection.setIntersectionState(auxRoadRed, mainRpadYellow);
                delay(3000);
                break;
            case 3:
                intersectionState = 4;
                intersection.setIntersectionState(auxRoadRed, mainRoadRed);
                delay(1000);
                break;
            case 4:
                intersectionState = 5;
                intersection.setIntersectionState(auxRoadGreen, mainRoadRed);
                intersection.checkMainRoad();
                break;
            case 5:
                intersectionState = 0;
                intersection.setIntersectionState(auxRoadYellow, mainRoadRed);
                delay(3000);
                break;
            case 6:
                while (intersectionState == 6) {
                    intersection.setIntersectionState(auxRoadYellow, mainRpadYellow);
                    delay(1000);
                }
                break;
            case 7:
                intersection.setIntersectionState(auxRoadYellow, mainRpadYellow);
                while (intersectionState == 7) {
                    delay(1000);
                }
                break;
        }
    }

    return 0;
}