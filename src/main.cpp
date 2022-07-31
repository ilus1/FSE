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

short red = 0;
short yellow = 1;
short green = 2;


int main(void) {
    wiringPiSetup();

    Road auxRoad (semaforoAux[1], auxMinGreenTime, pedestreAux[1], sensorCarroNorte[1], sensorCarroSul[1]);
    Road mainRoad (semaforoMain[1], mainMinGreenTime, pedestreMain[1], velocidadeLeste[1], velocidadeOeste[1]);
    Intersection intersection = Intersection(auxRoad, mainRoad);

    for(int i = 0; i < 50; i++) {
        intersection.setIntersectionState(green, yellow);
        delay(800);
        intersection.setIntersectionState(yellow, green);
        delay(800);
        intersection.setIntersectionState(red, red);
        delay(800);
    }

    return 0;
}