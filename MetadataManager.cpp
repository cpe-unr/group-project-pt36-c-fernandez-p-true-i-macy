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

////////////////////////////////////////////////////////////
/**
 *  @details prints each metadata chunk on a new line, attributes separated by tabs
*/
void MetadataManager::print(){
    for(int i = 0; i < metadatas.size(); ++i){
        std::cout << i+1 << ") " << metadatas[i].getID() << ": " << metadatas[i].getBuffer() << std::endl;
    }
}

/**
 * @details process to view, write new, and overwrite metadata
*/
void MetadataManager::editMetadata(){
    char mdid[4];
    std::string md;

    do{
        std::cout << std::endl;
        for(int i = 0; i < metadatas.size(); ++i){
            std::cout << i+1 << ") " << metadatas[i].getID() << ": " << metadatas[i].getBuffer() << std::endl;
        }
        std::cout << "ENTER METADATA ID (0 TO EXIT): ";
        std::cin >> mdid;

        if(mdid[0] != '0'){
            std::cout << "ENTER METADATA: ";
            std::cin >> md;

            std::string str;
            bool overwrite = 0;
            for(char c : mdid){
                str.push_back(c);
            }
            str.push_back('\0');

            for(int i = 0; i < metadatas.size(); ++i){   
                if(metadatas[i].getID() == str){
                    metadatas[i].setBuffer(md);

                overwrite = 1;
                }
            }

            if(overwrite == 0){
                metadatas.emplace_back(mdid, md);
            }
        }      
    } while(mdid[0] != '0'); 
}
////////////////////////////////////////////////////////////

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
        m.setSize(m.getBufferSize() + 1);
        mh.listSize += 8 + m.getSize();
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

/**
 * @details Writing the CSV information for the MetadataHeader
 * @param Metadata - Vector
*/

void MetadataManager::writeCSVMetaM(std::ofstream& outFile){

    for(Metadata& md : metadatas){
        if((md.getID().empty()) || (md.getBuffer().empty())){
            outFile << "No metadata present" << std::endl;

        }
        else{
            outFile << md.getID() << ", " << md.getBuffer() << std::endl; //NEED TO FIGURE OUT WHICH INFO SPECIFICALLY
        }
    }
}