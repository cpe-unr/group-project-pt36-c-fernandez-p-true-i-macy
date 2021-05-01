#include "Wav.h"

/**
 * @param fileName - the name of the file 
 *  constructs Wav object from input file
*/
Wav::Wav(const std::string& fileName){
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        this->fileName = fileName;                      // reads fileName
        file.read((char*)&wh, sizeof(WavHeader));       // reads WavHeader
        if(wh.numChannels == 1){                        // reads mono
            buffer = new unsigned char[wh.dataSize];
            file.read((char*)buffer, wh.dataSize);     
        } else{                                         // reads stereo
            buffer = new unsigned char[wh.dataSize/2];
            buffer2 = new unsigned char[wh.dataSize/2];
            for(int i = 0; i < wh.dataSize/2; i += wh.blockAlign/2){
                for(int j = 0; j < wh.bitsPerSample/8; ++j){
                    buffer[i+j] = file.get();
                }
                for(int j = 0; j < wh.bitsPerSample/8; ++j){
                    buffer2[i+j] = file.get();
                }
            }
        }
        if(!file.eof()){                                // reads MetadataManager
            mm = MetadataManager(file);                 
        }
        file.close();
    }
    else{
        std::cout << "File " << fileName << " could not be opened.";
    }
}

/**
 * @param outFileName - the out file name
 *  writes contents of Wav object to output .wav file
*/
void Wav::writeFile(const std::string &outFileName){
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wh,sizeof(WavHeader));
    // WRITE DATA
    if(mm.getSize() > 0){
        // WRTIE METADATA HEADER
        // WRITE METADATA
    }
    outFile.close();
}

/**
 *  prints each metadata on newline
*/
void Wav::printMetadata(){
    mm.print();
}

/**
 *  @returns - name of .wav file
*/
std::string Wav::getFileName() const{
    return fileName;
}

/**
 * @returns - size of (each) unsigned char buffer
*/
int Wav::getBufferSize() const{
    return wh.dataSize / wh.numChannels;
}

/**
 * @returns - number of bits per sample
*/
int Wav::getBitsPerSample() const{
    return wh.bitsPerSample;
}

/**
 *  @details - destruct Wav object and delete buffer
*/
Wav::~Wav(){
    delete[] buffer;
    delete[] buffer2;
}