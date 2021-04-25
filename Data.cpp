#include "Data.h"

// constructs Data from file
Data::Data(std::ifstream& file, int size){
    buffer = new unsigned char[size];
    file.read((char*)buffer, size);
}

// destruct Data object and delete buffer
Data::~Data(){
    if(buffer != NULL){
        delete[] buffer;
    }
}

// returns data buffer
unsigned char* Data::getBuffer() const{
    return buffer;
}