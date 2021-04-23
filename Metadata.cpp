#include "Metadata.h"

// Constructs one metadata chunk from input file
Metadata::Metadata(std::ifstream& file){
    file.read(tag, sizeof(tag));
    file.read((char*)&size, sizeof(size));
    buffer.resize(size);
    file.read(&buffer[0], size);
}

// Returns metadata tag as string
std::string Metadata::getTag() const{
    std::string str;
    for(char c : tag){
        str.push_back(c);
    }
    str.push_back('\0');
    return str;
}

// Returns number of bytes in metadata buffer
int Metadata::getSize() const{
    return size;
}

// Returns metadata buffer
std::string Metadata::getBuffer() const{
    std::string str(buffer.begin(), buffer.end() - 1);
    return str;
}

// Sets metadata buffer when given a string
// NOTE: when setting buffer we must update listSize in MetadataHeader and wav_size in wav_header
void Metadata::setBuffer(std::string str){
    size = str.length() + 2;
    std::vector<char> temp(str.begin(), str.end());
    temp.push_back('\0');
    temp.push_back('\0');
    buffer = temp;
}
