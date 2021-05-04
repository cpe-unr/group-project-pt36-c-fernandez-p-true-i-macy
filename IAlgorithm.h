#ifndef IALGORITHM_H
#define IALGORITHM_H

#include <math.h>
#include "Wav.h"

/**
 * @details - base template for processor algorithms
 * @note - ZERO is located at 128 for unsigned chars, 0 for everything else
 * @note LOWER and UPPER are in relation to adjusted value (after substracting ZERO) for unsigned chars
*/
template<typename T>
class IAlgorithm{
public:
    virtual void processBuffer(T* buffer, int bufferSize) = 0;
};

#endif // IALGORITHM_H