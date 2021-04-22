#ifndef METADATA_HEADER_H
#define METADATA_HEADER_H

/*
 * This struct follows the data buffer of the wave file when metadata is present.
 *
 *  Positions	Sample Value	    Description
 *  1-4	        “LIST”	            List chunk marker. Characters are each 1 byte long.
 *  5-8	        List chunk size     Size of the list chunk - 8 bytes, in bytes (32-bit integer).
 *  9-12	    “INFO”	            Information Header. Always equals “INFO”.
*/

typedef struct MetadataHeader{
    char listHeader[4];
    int listSize;
    char infoHeader[4];
} MetadataHeader;

#endif //METADATA_HEADER_H