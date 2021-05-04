/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/


#ifndef METADATA_MANAGER_H
#define METADATA_MANAGER_H

#include <vector>
#include "Metadata.h"
#include "MetadataHeader.h"

class MetadataManager{
private:
    int oldListSize;
    MetadataHeader mh;
    std::vector<Metadata> metadatas;
public:
    MetadataManager() = default;
    MetadataManager(std::ifstream&);
    void print();
    int getSize() const;
    void writeFile(std::ofstream&);
    void setListSize();
    int getListSize();
    int getOldListSize();
    void writeCSVMetaM(std::ofstream&);
};

#endif // METADATA_MANAGER_H