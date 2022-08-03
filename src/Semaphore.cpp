#include "../include/Semaphore.h"

Semaphore::Semaphore () {}

Semaphore::Semaphore (short *lights) {
    this->portSetup(lights, OUTPUT);
    this->greenLight = lights[0];
    this->yellowLight = lights[1];
    this->redLight = lights[2];
}

void Semaphore::setSemaphoreState (short state) {
    switch (state) {
        case 0:
            digitalWrite (this->greenLight, LOW);
            digitalWrite (this->yellowLight, LOW);
            digitalWrite (this->redLight, HIGH);
            break;
        case 1:
            digitalWrite (this->greenLight, LOW);
            digitalWrite (this->yellowLight, HIGH);
            digitalWrite (this->redLight, LOW);
            break;
        case 2:
            digitalWrite (this->greenLight, HIGH);
            digitalWrite (this->yellowLight, LOW);
            digitalWrite (this->redLight, LOW);
            break;
    }
}

void Semaphore::portSetup (short* ports, short state) {
    for (int i = 0; i < 3; i++)
        pinMode (ports[i], state);
}
