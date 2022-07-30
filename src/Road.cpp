#include "../includes/Road.h"

Road::Road(unsigned short *lights, unsigned short minGreenTime, bool waitingPedestrian) {
    this->semaphore = Semaphore(lights, minGreenTime);
    this->minGreenTime = minGreenTime;
    this->maxGreenTime = this.setMaxGreenTime();
    this->havePedestrian = waitingPedestrian;
}

Road:Road(unsigned short *lights, unsigned short minGreenTime, bool waitingPedestrian) {
    this->auxRoadSemaphore = Semaphore(lights);
    this->mainRoadSemaphore = Semaphore(lights, minGreenTime, true);
    this->waitingPedestrian = waitingPedestrian;
}

void Road::setMaxGreenTime() {
    this->maxGreenTime = this->minGreenTime * 2;
}



Road::Road