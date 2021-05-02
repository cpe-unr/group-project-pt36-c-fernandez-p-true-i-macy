#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "Algorithm.h"

template<typename T>
class Normalization : public Algorithm{

    private:
        int newDelay;

    public:
	    Normalization() = default;
	    Normalization::Normalization(int delay) : newDelay(delay){
        }
        void processBuffer(unsigned char* buffer, int bufferSize) override;
};

#endif