#ifndef WAV_MANAGER
#define WAV_MANAGER

#include <dirent.h>
#include <sys/types.h>
#include "Wav.h"

class WavManager{
private:
    std::vector<Wav*> wavs;
public:
    WavManager(char*);
    virtual ~WavManager();
    Wav* getWav(int) const;
    int getSize() const;
};

#endif // WAV_MANAGER