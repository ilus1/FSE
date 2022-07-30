#ifndef SEMAPHORE
#define SEMAPHORE

#include <wiringPi.h>
class Semaphore {

private:
    unsigned short redLight;
    unsigned short yellowLight;
    unsigned short greenLight;

public:
    Semaphore ();
    Semaphore (unsigned short *lights);
    void setSemaphoreState (unsigned short semaphoreState);

};

#endif