#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <math.h>
#include "Wav.h"

/**
 * @details - base template for processor algorithms
 * @note - ZERO is located at 128 for unsigned chars, 0 for everything else
 * @note LOWER and UPPER are in relation to adjusted value (after substracting ZERO) for unsigned chars
*/
template<typename T>
class Algorithm{
public:
    virtual void processBuffer(T* buffer, int bufferSize) = 0;
};

#endif // PROCESSOR_H