/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef WAV_H
#define WAV_H

#include "WavHeader.h"
#include "MetadataManager.h"

class Wav{
private:
    std::string fileName;
    WavHeader wh;
    unsigned char* buffer = NULL;
    MetadataManager mm;
public:
    Wav(const std::string&);
    virtual ~Wav();
    void destructData();
    void writeFile(const std::string&);
    void printMetadata();
    int getBufferSize() const;
    std::string getFileName() const;
    unsigned char* getBuffer() const;
};

#endif //WAV_H