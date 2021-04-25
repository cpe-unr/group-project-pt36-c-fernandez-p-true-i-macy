#include "Data.h"

/**
 * @param file - file information
 * @param size - the size of file I think...
 * constructs Data from file
*/
Data::Data(std::ifstream& file, int size){
    buffer = new unsigned char[size];
    file.read((char*)buffer, size);
}

/**
 *  destructs Data object and delete buffer
*/
Data::~Data(){
    if(buffer != NULL){
        delete[] buffer;
    }
}

/**
 * @returns - data buffer
*/
unsigned char* Data::getBuffer() const{
    return buffer;
}