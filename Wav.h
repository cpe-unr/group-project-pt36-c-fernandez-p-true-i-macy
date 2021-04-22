#ifndef WAV_H
#define WAV_H

#include <iostream>
#include "WaveHeader.h"
#include "MetadataHeader.h"
#include "MetadataManager.h"

class Wav{
private:
    unsigned char* buffer = NULL;
    wav_header wh;
    MetadataManager mm;
public:
    virtual ~Wav();
    void readFile(const std::string&);
    void writeFile(const std::string&);
    void printMetadata();
    unsigned char* getBuffer();
    int getBufferSize() const;
    int getNumChannels() const;
    
};

#endif //WAV_H