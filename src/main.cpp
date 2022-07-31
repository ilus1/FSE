#include "../include/Intersection.h"
#include "../include/Road.h"

short semaforoAux[2][3] = {{8, 9, 14}, {31, 25, 29}};
short semaforoMain[2][3] = {{30, 21, 22}, {28, 27, 26}};
short auxMinGreenTime = 5000;
short mainMinGreenTime = 10000;
short pedestreAux[2] = {12, 10};
short pedestreMain[2] = {13, 11};
short sensorCarroNorte[2] = {7, 15};
short sensorCarroSul[2] = {0, 16};
short velocidadeLeste[2][2] = {{2, 3}, {1, 4}};
short velocidadeOeste[2][2] = {{23, 24}, {5, 6}};

short auxRed = 0, mainRed = 0;
short auxYellow = 1, mainYellow = 1;
short auxGreen = 2, mainGreen = 2;


int main(void) {
    short intersectionState = 0;
    wiringPiSetup();

    Road auxRoad (semaforoAux[1], auxMinGreenTime, pedestreAux[1], sensorCarroNorte[1], sensorCarroSul[1]);
    Road mainRoad (semaforoMain[1], mainMinGreenTime, pedestreMain[1], velocidadeLeste[1], velocidadeOeste[1]);
    Intersection intersection = Intersection(auxRoad, mainRoad);

    while (intersectionState >= -1) {
        case 0:
            intersection.setIntersectionState(auxRed, mainRed);
            delay(1000);
            break;
        case 1:
            intersection.setIntersectionState(auxRed, mainGreen);
            delay(10000);
            break;
        case 2:
            intersection.setIntersectionState(auxRed, mainYellow);
            delay(3000);
            break;
        case 3:
            intersection.setIntersectionState(auxRed, mainRed);
            delay(1000);
            break;
        case 4:
            intersection.setIntersectionState(auxGreen, mainRed);
            delay(5000);
            break;
        case 5:
            intersection.setIntersectionState(auxYellow, mainRed);
            delay(3000);
            break;
        case 6:
            while (intersectionState == 6) {
                intersection.setIntersectionState(auxYellow, mainYellow);
                delay(1000);
            }
            break;
        case 7:
            intersection.setIntersectionState(auxYellow, mainYellow);
            while (intersectionState == 7) {
                delay(1000);
            }
            break;
    }

    return 0;
}