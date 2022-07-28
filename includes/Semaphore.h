#ifndef SEMAPHORE
#define SEMAPHORE

class Semaphore {

public:
    unsigned short redLight;
    unsigned short yellowLight;
    unsigned short greenLight;
    unsigned short minGreenTime;
    unsigned short maxGreenTime;

    Semaphore(unsigned int *lights, unsigned int minGreenTime);
    void setMaxGreenTime();
    void setSemaphoreState(bool *semaphoreState);
};

#endif