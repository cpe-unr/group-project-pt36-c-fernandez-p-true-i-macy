#ifndef WAV_MANAGER
#define WAV_MANAGER

#include <vector>
#include <fstream>
#include <dirent.h>
#include <sys/types.h>
#include "Wav.h"

class WavManager{
private:
    std::vector<Wav*> wavs;
public:
    WavManager(char*);
    void addWav(Wav*);
    int getSize() const;
    Wav* getWav(int) const;
};

#endif // WAV_MANAGER