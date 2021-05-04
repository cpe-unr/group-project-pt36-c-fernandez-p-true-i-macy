/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

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
    Metadata(char*, std::string);
    std::string getID() const;
    int getSize() const;
    int calcSize();
    std::string getBuffer() const;
    void setID(char[4]);
    void setBuffer(std::string);
    void writeFile(std::ofstream&);
    void setSize(int);
    int getBufferSize() const;
};

#endif //METADATA_H