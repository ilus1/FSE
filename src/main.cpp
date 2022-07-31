
#include "../include/Intersection.h"
#include "../include/Road.h"

<<<<<<< HEAD
short unsigned int semaforoAux[2][3] = {{8, 9, 14}, {31, 25, 29}};
short unsigned int semaforoMain[2][3] = {{30, 21, 22}, {28, 27, 26}};
short unsigned int auxMinGreenTime = 5000;
short unsigned int mainMinGreenTime = 10000;
short unsigned int pedestreAux[2] = {12, 10};
short unsigned int pedestreMain[2] = {13, 11};
short unsigned int sensorCarroNorte[2] = {7, 15};
short unsigned int sensorCarroSul[2] = {0, 16};
short unsigned int velocidadeLeste[2][2] = {{2, 3}, {1, 4}};
short unsigned int velocidadeOeste[2][2] = {{23, 24}, {5, 6}};
=======
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
>>>>>>> 0075888 (Correção de problemas com compilação)


int main(void) {
    Road auxRoad = Road(semaforoAux[0], semaforoMain[0], auxMinGreenTime, pedestreAux[0], sensorCarroNorte[0], sensorCarroSul[0]);
    Road mainRoad = Road(semaforoAux[1], semaforoMain[1], mainMinGreenTime, pedestreMain[0], velocidadeLeste[0], velocidadeOeste[0]);
    Intersection intersection = Intersection(auxRoad, mainRoad);

    return 0;
}