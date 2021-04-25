#include "MetadataManager.h"

// constructs MetadataManager object from input file stream
MetadataManager::MetadataManager(std::ifstream& file){
    file.read((char*)&mh, sizeof(MetadataHeader));
    int i = 0, counter = 0;
    while(i < mh.listSize - 4){
        metadatas.emplace_back(file);
        i += metadatas[counter++].getSize() + 8;
    }
}

// prints each metadata chunk on a new line, attributes separated by tabs
void MetadataManager::print(){
    for(Metadata& md : metadatas){
        std::cout << md.getID() << '\t' << md.getSize() << '\t' << md.getBuffer() << std::endl;
    }
}

// returns number of metadata chunks held in metadatas vector
int MetadataManager::getSize() const{
    return metadatas.size();
}
