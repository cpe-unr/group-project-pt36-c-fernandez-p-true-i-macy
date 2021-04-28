#include "Noisegate.h"
#include <iostream>

/**
 * 
*/
Noisegate::Noisegate(int numbers) : newNum(numbers){

}

/**
 * 
*/ 
void Noisegate::processBuffer(unsigned char* buffer, int bufferSize){

	for(int i = 0; i < bufferSize; i++){
	
		if((buffer[i] > 128) && (buffer[i] < (128 + newNum))){
			
			buffer[i] = 128;
		}
		else if((buffer[i] < 128) && (buffer[i] > (128 - newNum))){
			
			buffer[i] = 128;
		}
		else{
			
			buffer[i] = buffer[i];
		}
	}
}
