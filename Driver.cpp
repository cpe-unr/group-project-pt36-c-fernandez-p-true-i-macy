#include "Driver.h"

/**
 * @details - sets Wav pointer in Driver
*/
void Driver::setWav(Wav* wav){
    this->wav = wav;
    std::cout << std::endl << "SELECTED: " << this->wav->getFileName() << std::endl;
}

/**
 * @details handles Wav processing sequence
*/
void Driver::processWav(){
    if(wav->getBitsPerSample() == 8){
        processBuffer<unsigned char>(wav);
    } else if(wav->getBitsPerSample() == 16){
        processBuffer<short>(wav);
    }
}

/**
 * @details writes Wav file to output .wav file
 * @param files vector of filenames in directory
*/
void Driver::outputWavFile(std::vector<std::string> fileNames){
    wav->writeFile(fileNames);
}

/**
 * @details writes Wav file to output .csv file
 * @param wavs vector of pointer to Wav files in directory
*/
void Driver::outputCSVFile(std::vector<Wav*> wavs){
    wav->writeCSV(wavs);
}

//////////////////////////////////////////
/**
 * @details edit metadata
*/
void Driver::editMetadata(){
    wav->editMetadata();
}
///////////////////////////////////////////