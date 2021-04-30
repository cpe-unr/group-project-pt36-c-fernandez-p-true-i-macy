#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Algorithm.h"
#include "Wav.h"

template<typename T>
class Processor{
public:
    void process(Algorithm& a, Wav* wav){
        a.processBuffer(wav->getBuffer()<T>, wav->getBufferSize() / sizeof(T));
        if(wav->getBuffer2()<T> != NULL){
            a.processBuffer(wav->getBuffer2()<T>, wav->getBufferSize() / sizeof(T));
        }
    }
};

#endif // PROCESSOR_H