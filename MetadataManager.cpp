#include "MetadataManager.h"

/**
 *  @details constructs MetadataManager object from input file stream
 * @param file the file info
*/
MetadataManager::MetadataManager(std::ifstream& file){
    file.read((char*)&mh, sizeof(MetadataHeader));
    int i = 0, counter = 0;
    while(i < mh.listSize - 4){
        metadatas.emplace_back(file);
        i += metadatas[counter++].getSize() + 8;
    }
}

/**
 *  @details prints each metadata chunk on a new line, attributes separated by tabs
*/
void MetadataManager::print(){
    for(Metadata& md : metadatas){
        std::cout << md.getID() << '\t' << md.getSize() << '\t' << md.getBuffer() << std::endl;
    }
}

/** 
 * @returns number of metadata chunks held in metadatas vector
*/
int MetadataManager::getSize() const{
    return metadatas.size();
}

/**
 * @param outFile output file stream
 * @details writes metadata and metadata header to output .wav file
*/
void MetadataManager::writeFile(std::ofstream& outFile){
    outFile.write((char*)&mh, sizeof(MetadataHeader));
    for(Metadata m : metadatas){
        m.writeFile(outFile);
    }
}

/**
 * @details calculates list size before writing file
*/
void MetadataManager::setListSize(){
    oldListSize = mh.listSize;
    mh.listSize = 4;
    for(Metadata m : metadatas){
        mh.listSize += 8 + m.calcSize();
    }
}

/**
 * @details get list size
*/
int MetadataManager::getListSize(){
    return mh.listSize;
}

/**
 * @details get old list size
*/
int MetadataManager::getOldListSize(){
    return oldListSize;
}