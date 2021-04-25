#ifndef WAV_H
#define WAV_H

#include "WavHeader.h"
#include "Data.h"
#include "MetadataHeader.h"
#include "MetadataManager.h"

class Wav{
private:
    std::string fileName;
    WavHeader wh;
    Data data;
    MetadataManager mm;
public:
    Wav(const std::string&);
    void writeFile(const std::string&);
    void printMetadata();
    unsigned char* getBuffer();
    int getBufferSize() const;
    int getNumChannels() const;
    std::string getFileName() const;
};

#endif //WAV_H