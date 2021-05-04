#include "Metadata.h"

/**
 * @param file input file stream
 * @details constructs one input stream from file
*/
Metadata::Metadata(std::ifstream& file){
    file.read(metadataID, sizeof(metadataID));
    file.read((char*)&metadataSize, sizeof(metadataSize));
    buffer.resize(metadataSize);
    file.read(&buffer[0], metadataSize);
}

/////////////////////////////////////////////
/**
 * @param id 
 * @details constructs one input stream from file
*/
Metadata::Metadata(char id[4], std::string md){
    for(int i = 0; i < 4; ++i){
        metadataID[i] = id[i];
    }
    buffer = md;
    metadataSize = buffer.size() + 1;
}
/////////////////////////////////////////////

/**
 *  @returns metadata ID as string
*/
std::string Metadata::getID() const{
    std::string str;
    for(char c : metadataID){
        str.push_back(c);
    }
    str.push_back('\0');
    return str;
}

/**
 *  @returns - number of bytes in metadata size variable
*/ 
int Metadata::getSize() const{
    return metadataSize;
}

/**
 *  @returns - number of bytes in metadata buffer
*/ 
int Metadata::calcSize(){
    metadataSize = buffer.size();
    return metadataSize;
}

/**
 *  @returns - metadata buffer
*/
std::string Metadata::getBuffer() const{
    return buffer;
}

/**
 * @details - sets metadata buffer when given a string
 * @param buffer - the buffer
*/
void Metadata::setBuffer(std::string buffer){
    this->buffer = buffer;
    this->buffer.resize(sizeof(buffer));
    metadataSize = this->buffer.size() + 1;
}

/**
 * @param outFile output file stream
 * @details writes one busy piece
*/
void Metadata::writeFile(std::ofstream& outFile){
    outFile.write(metadataID, sizeof(metadataID));
    outFile.write(reinterpret_cast<char*>(&metadataSize), sizeof(metadataSize));
    outFile.write(&buffer[0], metadataSize);
}

/**
 * @return size of buffer
*/
int Metadata::getBufferSize() const{
    return buffer.size();
}

/**
 * @param size metadata size
*/
void Metadata::setSize(int size){
    metadataSize = size;
}