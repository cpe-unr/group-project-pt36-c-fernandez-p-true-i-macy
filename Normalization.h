/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "IAlgorithm.h"

/**
 * @details applies normalization effect to Wav based on input delay
*/
template<typename T>
class Normalization : public IAlgorithm<T>{
private:
    int newMax, LOWER, ZERO;
public:
	/**
	 * @details constructs Normalization processor
	 * @param newMax new maximum specified by user input
	*/
	explicit Normalization(int max) : newMax(max){
        LOWER = pow(2, sizeof(T) * 8 - 1) * -1;
		if(sizeof(T) == 1){
            ZERO = 128;
        } else{
            ZERO = 0;
        }
	}

    /**
	 * @param buffer pointer to audio buffer of type T
	 * @param bufferSize number of elements in audio buffer
	 * @return max in the buffer
	 * @details finds maximum value in buffer
	*/
    int findMax(T* buffer, int bufferSize){
        int max = LOWER;
        for(int n = 0; n < bufferSize; n++){
            if(buffer[n] > max){
                max = buffer[n];
            }
        }
        return max;
    }

	/**
	 * @param buffer pointer to audio buffer of type T
	 * @param bufferSize number of elements in audio buffer
	 * @details applies echo algorithm
	*/
	void processBuffer(T *buffer, int bufferSize) override{
		float oldMax = (float)(findMax(buffer, bufferSize) - ZERO);
		float adj_newMax = (float)(newMax - ZERO);
		float scale = adj_newMax / oldMax;

		for(int i = 0; i < bufferSize; ++i){
			int val = (float)(buffer[i] - ZERO) * scale; 
			buffer[i] = (T)(round(val + ZERO));
		}
	}
};

#endif // NORMALIZATION_H
