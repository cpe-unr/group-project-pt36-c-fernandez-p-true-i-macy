#include "Wav.h"

// constructs Wav object from input file
Wav::Wav(const std::string& fileName){
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        this->fileName = fileName;                  // reads and stores fileName
        file.read((char*)&wh, sizeof(WavHeader));   // reads and stores WavHeader
        buffer = new unsigned char[wh.dataSize];
        file.read((char*)buffer, wh.dataSize);      // reads and stores Data
        if(!file.eof()){
            mm = MetadataManager(file);             // reads and stores MetadataManager
        }
        file.close();
    }
    else{
        std::cout << "File " << fileName << " could not be opened.";
    }
}

// writes contents of Wav object to output .wav file
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

// prints each metadata on newline
void Wav::printMetadata(){
    mm.print();
}

// returns name of .wav file
std::string Wav::getFileName() const{
    return fileName;
}

// returns number of bytes in data buffer
int Wav::getBufferSize() const{
    return wh.dataSize;
}

// returns data buffer
unsigned char* Wav::getBuffer() const{
    return buffer;
}

// destruct Wav object and delete buffer
Wav::~Wav(){
    delete[] buffer;
}