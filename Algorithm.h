#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <math.h>
#include "Wav.h"

/**
 * @details - base template for processor algorithms
 * @note - must add 128 after processing unsigned char buffer
*/
template<typename T>
class Algorithm{
private:
    int LOWER, UPPER;
public:
    virtual void processBuffer(T* buffer, int bufferSize) = 0;
    
    /**
     * @details - constructs algorithm object and calculates min and max from T
    */
    Algorithm(){
        LOWER = pow(2, sizeof(T)-1) * -1;
        UPPER = (LOWER * -1) - 1;
    }
};

#endif // PROCESSOR_H