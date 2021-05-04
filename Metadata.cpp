#include "Metadata.h"

/**
 *  constructs one metadata chunk from input file
*/
Metadata::Metadata(std::ifstream& file){
    file.read(metadataID, sizeof(metadataID));
    file.read((char*)&metadataSize, sizeof(metadataSize));
    buffer.resize(metadataSize);
    file.read(&buffer[0], metadataSize);
}

/**
 *  @returns - metadata ID as string
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
    metadataSize = buffer.size() + 1;
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
 * @note - when setting buffer we must update listSize in MetadataHeader and fileSize in WavHeader
*/
void Metadata::setBuffer(std::string buffer){
    this->buffer = buffer;
}

/**
 * @param outFile output file stream
 * @details writes one busy piece
*/
void Metadata::writeFile(std::ofstream& outFile){
    outFile.write(metadataID, sizeof(metadataID));
    outFile.write(reinterpret_cast<char*>(&metadataSize), sizeof(metadataSize));
    outFile.write(&buffer[0], buffer.size());
    outFile.put('\0');
}