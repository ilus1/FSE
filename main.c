#include <wiringPi.h>
#include <stdio.h>

#define TOTAL_SINAIS 6
#define TOTAL_ESTADOS 6
#define TOTAL_SENSORES 8

int travessiaAux = 10;
int travessiaPrinc = 11;

int verdeMinPrinc = 10000;
int verdeMinAux = 5000;

int sensorCarroNorte = 15;
int sensorCarroSul = 16;
int sensorCarroLeste = 5;
int sensorCarroOeste = 1;

int sensores[TOTAL_SENSORES] = {1, 4, 5, 6, 10, 11, 15, 16};
int sinais[TOTAL_SINAIS] = {28, 27, 26, 31, 25, 29};
int estados[TOTAL_ESTADOS][TOTAL_SINAIS] = {
  {0, 0, 1, 0, 0, 1},   //Principal-Vermelho  Auxiliar-Vermelho
  {1, 0, 0, 0, 0, 1},   //Principal-Verde     Auxiliar-Vermelho
  {0, 1, 0, 0, 0, 1},   //Principal-Amarelo   Auxiliar-Vermelho
  {0, 0, 1, 1, 0, 0},   //Principal-Vermelho  Auxiliar-Verde
  {0, 0, 1, 0, 1, 0},   //Principal-Vermelho  Auxiliar-Amarelo
  {0, 1, 0, 0, 1, 0}};  //Amarelo Itermitente


void trocaEstados(int *estado) {
  for (int i = 0; i < TOTAL_SINAIS; i++)
    digitalWrite(sinais[i], (estado[i]));
}

void apagaTodos() {
  for (int i = 0; i < TOTAL_SINAIS; i++)
    digitalWrite(sinais[i], LOW);
}

int temPedestre(int travessia) {
  return digitalRead(travessia);
}

void temsensorCarro(int travessia, int *carros) {
  if (travessia == travessiaPrinc) {
    carros[0] = digitalRead(sensorCarroNorte);
    carros[1] = digitalRead(sensorCarroSul);
  } else {
    carros[0] = digitalRead(sensorCarroLeste);
    carros[1] = digitalRead(sensorCarroOeste);
  }
}

void ambosVermelhos() {
  trocaEstados(estados[0]);
  delay(1000);
}

void sinalAmarelo(int *estado) {
  trocaEstados(estado);
  delay(3000);
}

void estadoEmergencia() {
  trocaEstados(estados[5]);
  delay(500);
  apagaTodos();
}

void furouSinal() {
  printf("Furou Sinal");
}

void sinalVerde(int *estado, int travessia, int tempoMin) {
  int timer = 0, pedestre = 0, sensorCarro[2] = {0, 0}, temp[2] = {0, 0};

  trocaEstados(estado);
  while (timer < tempoMin || (!pedestre && !sensorCarro[0] && !sensorCarro[1] && timer < 2 * tempoMin)) {
    if (pedestre == 0) {
      pedestre = temPedestre(travessia);
      temsensorCarro(travessia, temp);
      if (temp[0] != sensorCarro[0]) {
         if(sensorCarro[0] == 1) furouSinal();
         sensorCarro[0] = temp[0];
      }
      if (temp[1] != sensorCarro[1]) {
         if(sensorCarro[1] == 1) furouSinal();
         sensorCarro[1] = temp[1];
      }
      delay(100);
    } else {
      temsensorCarro(travessia, temp);
      if (temp[0] != sensorCarro[0]) {
         if(sensorCarro[0] == 1) furouSinal();
         sensorCarro[0] = temp[0];
      }
      if (temp[1] != sensorCarro[1]) {
         if(sensorCarro[1] == 1) furouSinal();
         sensorCarro[1] = temp[1];
      }
      delay(100);
    }
    timer += 100;
  }
}


int main (void) {
  wiringPiSetup();
  int estado = 0;

  for (int i = 0; i < TOTAL_SINAIS; i++) pinMode(sinais[i], OUTPUT);
  for (int i = 0; i < TOTAL_SENSORES; i++) pinMode(sensores[i], INPUT);

  apagaTodos();
  switch (estado) {
    case 0:
      estado = 1;
      ambosVermelhos();
      break;
    case 1:
      estado = 2;
      sinalVerde(estados[1], travessiaPrinc, verdeMinPrinc);
      break;
    case 2:
      estado = 3;
      sinalAmarelo(estados[2]);
      break;
    case 3:
      estado = 4;
      ambosVermelhos();
      break;
    case 4:
      estado = 5;
      sinalVerde(estados[3], travessiaAux, verdeMinAux);
      break;
    case 5:
      estado = 0;
      sinalAmarelo(estados[4]);
      break;
    default:
      for (;;) estadoEmergencia();
  }
  return 0 ;
}
