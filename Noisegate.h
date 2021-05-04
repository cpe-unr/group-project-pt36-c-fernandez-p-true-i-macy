/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "IAlgorithm.h"

/**
 * @details applies echo effect to Wav based on input delay
*/
template<typename T>
class Noisegate : public IAlgorithm<T>{
private:
	int newThreshold, ZERO;
public:
	/**
	 * @details constructs Noisegate processor
	 * @param threshold threshold specified by user input
	*/
	explicit Noisegate(int threshold) : newThreshold(threshold){
        if(sizeof(T) == 1){
            ZERO = 128;
        } else{
            ZERO = 0;
        }
	}

	/**
	 * @param buffer pointer to audio buffer of type T
	 * @param bufferSize number of elements in audio buffer
	 * @details applies echo algorithm
	*/
	void processBuffer(T *buffer, int bufferSize) override{
		for(int n = 1; n < bufferSize; ++n){
			if(buffer[n] > (ZERO - newThreshold) && buffer[n] < (ZERO + newThreshold)){
				buffer[n] = ZERO;
			}
		}
	}
};

#endif // NOISEGATE_H
