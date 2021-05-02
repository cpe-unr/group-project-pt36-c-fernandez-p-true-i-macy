#include "WavManager.h"

/**
 * @param path - the directory path it should take
 * @details - construct WavManager object given path to directory of .wav files
*/
WavManager::WavManager(char* path){
    // check if directory opens
    struct dirent *entry;
    DIR *dir = opendir(path);
    if(dir == NULL){
        std::cout << "Directory could not be found." << std::endl;
    } else{
        // creates and populates fileNames vector
        std::vector<std::string> fileNames;
        while((entry = readdir(dir)) != NULL){
            std::string temp = entry->d_name;
            std::string extension(temp.end() - 4, temp.end());
            if(extension == ".wav"){
                fileNames.push_back(entry->d_name);
            }
        }
        closedir(dir);
        if(fileNames.size() == 0){
            std::cout << "Directory does not contain any '.wav' files." << std::endl;
        } else{
            // construct Wav object for each .wav file in directory and store in wavs vector
            for(std::string fileName : fileNames){  
                std::string strPath(path);
                strPath.push_back('/');
                wavs.push_back(new Wav(strPath + fileName));
            }
        }
    }
} 

/**
 * @details - destructs WavManager and deletes all Wav files in wavs vector
*/
WavManager::~WavManager(){
    for(Wav* wav: wavs){
        delete wav;
    }
}

/**
 * @param i - index i 
 * @returns - pointer to Wav object at index i in wavs vector
*/
Wav* WavManager::getWav(int i) const{
    return wavs[i];
}

/**
 *  @returns - size of wavs vector
*/
int WavManager::getSize() const{
    return wavs.size();
}

/**
 * @returns - pointer to the Wav object you select
*/ 
Wav* WavManager::selectWav(){
    int index = 0;
    std::cout << std::endl;
    for(int i = 0; i < wavs.size(); ++i){
        std::cout << i + 1 << ") " << wavs[i]->getFileName() << std::endl;
    }
    do{
        std::cout << "SELECT A FILE: ";
        std::cin >> index;
    } while(index < 1 || index > wavs.size());
    return wavs[index - 1];
}