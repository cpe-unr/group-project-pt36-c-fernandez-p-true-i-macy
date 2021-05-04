/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef WAV_MANAGER
#define WAV_MANAGER

#include <dirent.h>
#include <sys/types.h>
#include "Wav.h"

/**
 * @details - manages input, storage, and output for Wav files
*/
class WavManager{
private:
    std::vector<std::string> fileNames;
    std::vector<Wav*> wavs;
public:
    WavManager(char*);
    virtual ~WavManager();
    Wav* getWav(int) const;
    int getSize() const;
    Wav* selectWav();
    std::vector<Wav*> getWavs() const;
    std::vector<std::string> getFileNames() const;
};

#endif // WAV_MANAGER