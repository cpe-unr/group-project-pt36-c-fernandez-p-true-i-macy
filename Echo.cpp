#include "Echo.h"
#include <iostream>
#include <cmath>

/**
*
*/
Echo::Echo(int delay) : newDelay(delay){

}

/**
*
*/

void Echo::processBuffer(unsigned char *buffer, int bufferSize){

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
// 128 is the zero

}
