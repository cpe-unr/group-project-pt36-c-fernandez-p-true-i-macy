#ifndef METADATA_H
#define METADATA_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class Metadata{
private:
    char tag[4];      
    int size;
    std::vector <char> buffer;
public:
    Metadata() = default;
    Metadata(std::ifstream&);
    std::string getTag() const;
    int getSize() const;
    std::string getBuffer() const;
    void setBuffer(std::string);
};

#endif //METADATA_H