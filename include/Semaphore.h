#ifndef SEMAPHORE
#define SEMAPHORE

#include <wiringPi.h>
class Semaphore {

public:
    unsigned short redLight;
    unsigned short yellowLight;
    unsigned short greenLight;

    Semaphore(unsigned int *lights);
    void setSemaphoreState(unsigned int semaphoreState);
};

#endif