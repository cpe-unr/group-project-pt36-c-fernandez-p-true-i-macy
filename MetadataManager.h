#ifndef METADATA_MANAGER_H
#define METADATA_MANAGER_H

#include <vector>
#include "Metadata.h"
#include "MetadataHeader.h"

class MetadataManager{
private:
    MetadataHeader mh;
    std::vector<Metadata> metadatas;
public:
    MetadataManager() = default;
    MetadataManager(std::ifstream&);
    void print();
    int getSize() const;
};

#endif // METADATA_MANAGER_H