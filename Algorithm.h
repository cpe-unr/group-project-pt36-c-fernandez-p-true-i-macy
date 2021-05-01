#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <math.h>
#include "Wav.h"

// NOTE: must add 128 after processing unsigned char buffer

template<typename T>
class Algorithm{
private:
    int min, max;
public:
    Algorithm(){
        min = pow(2, sizeof(T)-1) * -1;
        max = (min * -1) -1;
    }
    virtual void processBuffer(T* buffer, int bufferSize){}
};

#endif // PROCESSOR_H