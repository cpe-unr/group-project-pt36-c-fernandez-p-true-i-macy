#ifndef DATA_H
#define DATA_H

#include <fstream>

// NOTE: currently only works with 18-bit mono

class Data{
private:
    unsigned char* buffer = NULL;
public:
    Data() = default;
    Data(std::ifstream&, int);
    ~Data();
    unsigned char* getBuffer() const;
};

#endif // DATA_H