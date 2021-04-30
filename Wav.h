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
    unsigned char* buffer2 = NULL;
    MetadataManager mm;
public:
    Wav(const std::string&);
    virtual ~Wav();
    void destructData();
    void writeFile(const std::string&);
    void printMetadata();
    std::string getFileName() const;
    int getBufferSize() const;

    /**
     * @returns - pointer to buffer of type T
     */ 
    template<typename T>
    T* getBuffer() const{
        return reinterpret_cast<T*>(buffer);
    }

    /**
     * @returns - pointer to buffer2 of type T
     */ 
    template<typename T>
    T* getBuffer2() const{
        return reinterpret_cast<T*>(buffer2);
    } 
};

#endif //WAV_H