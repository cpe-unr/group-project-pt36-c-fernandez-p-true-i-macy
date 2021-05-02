/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef ECHO_H
#define ECHO_H

#include "Algorithm.h"

/**
 * @details - applies echo effect to Wav based on input delay
 * @note - bounds LOWER and UPPER are available from Algorithm inheritance
*/
template<typename T>
class Echo : public Algorithm<T>{
private:
	int newDelay;
public:
	explicit Echo(int delay) : newDelay(delay){}

	/**
	 * @param - pointer to audio buffer of type T
	 * @param - number of elements in audio buffer
	 * @details - applies echo algorithm
	*/
	void processBuffer(T *buffer, int bufferSize) override{
        std::cout << "Echo processed." << std::endl;
	}
};

#endif // ECHO_H

/*void Echo::processBuffer(unsigned char *buffer, int bufferSize){

	float adj_i;
	float adj_delayed_i;
	float echoLevel = 0.5f;
	float val;

	for(int i = 0; i < bufferSize - newDelay; i++){
		adj_i = (float)(buffer[i] - 128);
		adj_delayed_i = (float)(buffer[i + newDelay] - 128);
		val = adj_i * echoLevel + adj_delayed_i * 0.5f + 128;
		buffer[i + newDelay] = (unsigned char)(round(val));
	}

//.5 is the scale factor
// 128 is the zero*/
