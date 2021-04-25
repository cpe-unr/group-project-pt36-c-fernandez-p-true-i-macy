#ifndef METADATA_H
#define METADATA_H

#include <fstream>
#include <string>
#include <iostream>

class Metadata{
private:
    char metadataID[4];      
    int metadataSize;
    std::string buffer;
public:
    Metadata() = default;
    Metadata(std::ifstream&);
    std::string getID() const;
    int getSize() const;
    std::string getBuffer() const;
    void setBuffer(std::string);
};

#endif //METADATA_H