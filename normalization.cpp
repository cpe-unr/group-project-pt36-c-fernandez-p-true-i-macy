#include "normalization.h"
#include <iostream>

/**
 * Need to find the biggest "jump" then use it to make it the "normal" spot
 * need to ask what they want to normalize to (like -1.0 or -5.0)
*/
template<typename T>
void Normalization::processBuffer(unsigned char* buffer, int bufferSize){
    int max = 0;
    int jump = 0;
    int subtracting = 0;

    std::cin >> jump;

    for(int i = 0; i < bufferSize; i++){
        if(buffer[i] < 128){
            if((buffer[i] - jump) >= 0){
                buffer[i] = buffer[i] - jump;
            }
            else{
                buffer[i] = 0;
            }
        }
        else if(buffer[i] > 128){
            if((buffer[i] + jump) <= 255){
                buffer[i] = jump + buffer[i];
            }
            else{
                buffer[i] = 255;
            }
            
        }
    }

}

