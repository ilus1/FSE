#ifndef SEMAPHORE
#define SEMAPHORE

#include <wiringPi.h>
class Semaphore {

private:
    short redLight;
    short yellowLight;
    short greenLight;

public:
    Semaphore ();
    Semaphore (short *lights);
    void setSemaphoreState (short semaphoreState);

};

#endif