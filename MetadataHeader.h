#ifndef METADATA_HEADER_H
#define METADATA_HEADER_H

struct MetadataHeader{
    char listID[4];
    int listSize;
    char infoID[4];
};

#endif //METADATA_HEADER_H