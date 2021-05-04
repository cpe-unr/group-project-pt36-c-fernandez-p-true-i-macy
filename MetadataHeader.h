/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef METADATA_HEADER_H
#define METADATA_HEADER_H

#include <iostream> 

struct MetadataHeader{
    char listID[4];
    int listSize;
    char infoID[4];
    //MetadataManager mm;
    //MetadataHeader mh;

/**
 * @details Writing the CSV information for the MetadataHeader
 * @param Metadata - Vector
*/

//NOT SURE IF WE NEED ONE FOR HEADER AND MANAGER
/*
void writeCSVMetaH(std::string outFileName, std::vector<Metadata> metadatas){

    std::ofstream outFile;
    outFile.open(outFileName);
    
    for(Metadata& md : metadatas){
        if((md.getID().empty()) || (md.getBuffer().empty())){
            std::cout << "No metadata present" << std::endl;

        }
        outFile << md.getID() << ": " << md.getBuffer() << std::endl; //Other information that might be needed
    }

    
}*/

};

#endif //METADATA_HEADER_H