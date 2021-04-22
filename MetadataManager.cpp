#include "MetadataManager.h"

// Constructs metadata manager from input file
MetadataManager::MetadataManager(std::ifstream& file){
    file.read((char*)&mh, sizeof(MetadataHeader));
    int i = 0, counter = 0;
    while(i < mh.listSize - 4){
        metadatas.emplace_back(file);
        i += metadatas[counter++].getSize() + 8;
    }
}

// Prints each metadata chunk on a new line, attributes separated by spaces
void MetadataManager::print(){
    for(Metadata& md : metadatas){
        std::cout << md.getTag() << ' ' << md.getSize() << ' ' << md.getBuffer() << std::endl;
    }
}

// Returns number of metadata chunks held in metadatas vector
int MetadataManager::getSize() const{
    return metadatas.size();
}
