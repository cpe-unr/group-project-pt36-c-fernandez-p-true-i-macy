#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Wav.h"

template<typename T>
class Algorithm{
public:
    int calcMax(){
        switch(sizeof(T)){
            case 8: 
            case 16:
        }
    }

    int calcMin(){

    }

    int calcZero(){

    }

    virtual void processBuffer(T* buffer, int bufferSize) = 0 override;
};

#endif // PROCESSOR_H