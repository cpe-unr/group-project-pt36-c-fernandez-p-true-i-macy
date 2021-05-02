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
    std::vector<Wav*> wavs;
public:
    WavManager(char*);
    virtual ~WavManager();
    Wav* getWav(int) const;
    int getSize() const;
    Wav* selectWav();
};

#endif // WAV_MANAGER