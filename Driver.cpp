#include "Driver.h"

/**
 * @details - sets Wav pointer in Driver
*/
void Driver::setWav(Wav* wav){
    this->wav = wav;
    std::cout << std::endl << "SELECTED: " << this->wav->getFileName() << std::endl;
}

/**
 * @details - initiates Wav processing sequence
*/
void Driver::processWav(){
    if(wav->getBitsPerSample() == 8){
        processBuffer<unsigned char>(wav);
    } else if(wav->getBitsPerSample() == 16){
        processBuffer<short>(wav);
    }
}
