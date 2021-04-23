#include "WavManager.h"

// Construct WavManager object given path to directory of .wav files
WavManager::WavManager(char* path){
    // Check if directory opens
    struct dirent *entry;
    DIR *dir = opendir(path);
    if(dir == NULL){
        throw std::runtime_error(std::string("Directory could not be found."));
    }
    // Creates and populates fileNames vector
    std::vector<std::string> fileNames;
    while((entry = readdir(dir)) != NULL){
        std::string temp = entry->d_name;
        std::string extension(temp.end() - 4, temp.end());
        if(extension == ".wav"){
            fileNames.push_back(entry->d_name);
        }
    }
    closedir(dir);
    // Construct Wav object for each .wav file in directory and store in wavs vector
    for(std::string fileName : fileNames){
        std::string strPath(path);
        strPath.push_back('/');
        wavs.push_back(new Wav(strPath + fileName));
    }
}   

// Adds new Wav object to back of wavs vector
void WavManager::addWav(Wav* wav){
    wavs.push_back(wav);
}

// Returns pointer to Wav object at index i in wavs vector
Wav* WavManager::getWav(int i) const{
    return wavs[i];
}

// Returns size of wavs vector
int WavManager::getSize() const{
    return wavs.size();
}
