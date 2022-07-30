#include "../include/Semaphore.h"

Semaphore::Semaphore () {}

Semaphore::Semaphore (unsigned short *lights) {
    this->redLight = lights[0];
    this->yellowLight = lights[1];
    this->greenLight = lights[2];
}

void Semaphore::setSemaphoreState (unsigned short state) {
    switch (state) {
        case 0:
            digitalWrite (this->redLight, HIGH);
            digitalWrite (this->yellowLight, LOW);
            digitalWrite (this->greenLight, LOW);
            break;
        case 1:
            digitalWrite (this->redLight, LOW);
            digitalWrite (this->yellowLight, HIGH);
            digitalWrite (this->greenLight, LOW);
            break;
        case 2:
            digitalWrite (this->redLight, LOW);
            digitalWrite (this->yellowLight, LOW);
            digitalWrite (this->greenLight, HIGH);
            break;
    }
}