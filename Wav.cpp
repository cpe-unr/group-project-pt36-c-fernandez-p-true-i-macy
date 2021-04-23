#include "Wav.h"

// Constructs Wav object from input file
Wav::Wav(const std::string& fileName){
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        this->fileName = fileName;
        file.read((char*)&wh, sizeof(wav_header));  // Reads and stores wave header
        buffer = new unsigned char[wh.data_bytes];  // Declares new buffer to hold data
        file.read((char*)buffer, wh.data_bytes);    // Reads data into buffer
        if(!file.eof()){
            mm = MetadataManager(file);             // Reads metadata and stores in metadata manager
        }
        file.close();
    }
    else{
        std::runtime_error("File " + fileName + " could not be opened.");
    }
}

// Custom destructor
Wav::~Wav() {
    if(buffer != NULL){
        delete[] buffer;
    }
}

// Writes contents of Wav object to output .wav file
void Wav::writeFile(const std::string &outFileName){
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wh,sizeof(wav_header));
    outFile.write((char*)buffer, wh.data_bytes);
    if(mm.getSize() > 0){
        // WRTIE METADATA HEADER
        // WRITE METADATA
    }
    outFile.close();
}

// Prints metadata
void Wav::printMetadata(){
    mm.print();
}

// Returns data buffer
unsigned char* Wav::getBuffer(){
    return buffer;
}

// Returns number of bytes in data buffer
int Wav::getBufferSize() const{
    return wh.data_bytes;
}

// Returns number of audio channels
int Wav::getNumChannels() const{
    return wh.num_channels; 
}

// Returns name of .wav file
std::string Wav::getFileName() const{
    return fileName;
}
