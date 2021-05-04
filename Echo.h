/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef ECHO_H
#define ECHO_H

#include "IAlgorithm.h"

/**
 * @details applies echo effect to Wav based on input delay
*/
template<typename T>
class Echo : public IAlgorithm<T>{
private:
	int newDelay, ZERO;
public:
	/**
	 * @details constructs Echo processor
	 * @param delay delay specified by user input
	*/
	explicit Echo(int delay) : newDelay(delay){
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
		float adj_i;
		float adj_delayed_i;
		float echoLevel = 0.5f;
		float val;

		for(int i = 0; i < bufferSize - newDelay; i++){
			adj_i = (float)(buffer[i] - ZERO);
			adj_delayed_i = (float)(buffer[i + newDelay] - ZERO);
			val = adj_i * echoLevel + adj_delayed_i * 0.5f + ZERO;
			buffer[i + newDelay] = (T)(round(val));
		}
	}
};

#endif // ECHO_H

//.5 is the scale factor
// ZERO = 128 for u char
// LOWER = pow(2, sizeof(T) * 8 - 1) * -1;
// UPPER = (LOWER * -1) - 1;
