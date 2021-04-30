#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Wav.h"

template<typename T>
class Algorithm{
public:
    void processBuffer(T* buffer, int bufferSize) = 0;
};

#endif // PROCESSOR_H