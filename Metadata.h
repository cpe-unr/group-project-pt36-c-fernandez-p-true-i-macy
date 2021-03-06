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
    std::string getBuffer() const;
    void setSize(int);
    void setBuffer(std::string);
    void writeFile(std::ofstream&);
};

#endif //METADATA_H