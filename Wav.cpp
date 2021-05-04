#include "Wav.h"

/**
 * @param fileName - the name of the file 
 *  constructs Wav object from input file
*/
Wav::Wav(const std::string& path, const std::string& fileName){
    std::ifstream file(path + fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        this->path = path;
        this->fileName = fileName;
        file.read((char*)&wh, sizeof(WavHeader));       // reads WavHeader
        if(wh.numChannels == 1){                        // reads mono
            buffer = new unsigned char[wh.dataSize];
            file.read((char*)buffer, wh.dataSize);     
        } else{                                         // reads stereo
            buffer = new unsigned char[wh.dataSize/2];
            buffer2 = new unsigned char[wh.dataSize/2];
            for(int i = 0; i < wh.dataSize/2; i += wh.blockAlign/2){
                for(int j = 0; j < wh.bitsPerSample/8; ++j){
                    buffer[i+j] = file.get();
                }
                for(int j = 0; j < wh.bitsPerSample/8; ++j){
                    buffer2[i+j] = file.get();
                }
            }
        }
        if(!file.eof()){                                // reads MetadataManager
            mm = MetadataManager(file);                 
        }
        file.close();
    }
    else{
        std::cout << "File " << fileName << " could not be opened.";
    }
}

/**
 * @param fileNames - vector containing list of filenames already in directory
 *  writes contents of Wav object to output .wav file
*/
void Wav::writeFile(std::vector<std::string>& fileNames){
    std::string outFileName;
    bool validName;
    do{ 
        validName = 1;
        std::cout << std::endl << "NAME OUTPUT FILE: ";
        std::cin >> outFileName;
        for(std::string s : fileNames){
            if(s == outFileName){
                validName = 0;
            }
        }
        std::string extension(outFileName.end() - 4, outFileName.end());
        if(validName == 0){
            std::cout << "This file already exists." << std::endl;
        } else if(extension != ".wav"){
            validName = 0;
            std::cout << "Filename must end in \'.wav\'." << std::endl;
        } else{
            mm.setListSize();
            wh.fileSize += mm.getListSize() - mm.getOldListSize();
            std::ofstream outFile(path + outFileName, std::ios::out | std::ios::binary);
            outFile.write((char*)&wh,sizeof(WavHeader));
            if(wh.numChannels == 1){                        // writes mono
                outFile.write((char*)buffer, wh.dataSize); 
            } else{                                         // writes stereo
                for(int i = 0; i < wh.dataSize/2; i += wh.blockAlign/2){
                    for(int j = 0; j < wh.bitsPerSample/8; ++j){
                        outFile.put(buffer[i+j]);
                    }
                    for(int j = 0; j < wh.bitsPerSample/8; ++j){
                        outFile.put(buffer2[i+j]);
                    }
                }
            }
            if(mm.getSize() > 0){
                mm.writeFile(outFile);
            }
            outFile.close();
            std::cout << "File has been created." << std::endl;
        }
    } while(validName == 0);
}

/**
 * @details writes to output csv file
 * @param wavs - vector of the wavs
*/
void Wav::writeCSV(std::vector<Wav*> wavs){
    std::string outFileName;
    bool validName;
    std::ofstream outFile;
    do{ 
        validName = 1;
        std::cout << std::endl << "NAME OUTPUT FILE: ";
        std::string extension(outFileName.end() - 4, outFileName.end());
        if(extension != ".csv"){
            validName = 0;
            std::cout << "Filename must end in '.csv'." << std::endl;
        } else{
            mm.setListSize();
            wh.fileSize += mm.getListSize() - mm.getOldListSize();

            outFile.open(outFileName);
            if(outFile.is_open()){
                for(Wav* wav : wavs){
                    outFile << wh.fileSize << ", " << wh.fmtSize << ", " << wh.audioFmt << ", " << wh.numChannels << ", " << wh.sampleRate << ", " << wh.byteRate << ", " << wh.blockAlign << ", " << wh.bitsPerSample << ", " << wh.dataSize << ", " << std::endl;
                    mm.writeCSVMetaM(outFile);
                }
            }
            else{
                std::cout << "Could not open " << outFileName << std::endl;
            }
        }
    } while(validName == 0);
}

/**
 *  prints each metadata on newline
*/
void Wav::printMetadata(){
    mm.print();
}

/**
 *  @returns - name of .wav file
*/
std::string Wav::getFileName() const{
    return fileName;
}

/**
 * @returns - size of (each) unsigned char buffer
*/
int Wav::getBufferSize() const{
    return wh.dataSize / wh.numChannels;
}

/**
 * @returns - number of bits per sample
*/
int Wav::getBitsPerSample() const{
    return wh.bitsPerSample;
}

/**
 * @details metadata editing process
*/
void Wav::editMetadata(){
    mm.editMetadata();
}

/**
 *  @details - destruct Wav object and delete buffer
*/
Wav::~Wav(){
    delete[] buffer;
    delete[] buffer2;
}