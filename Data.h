/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef DATA_H
#define DATA_H

#include <fstream>

class Data{
private:
    unsigned char* buffer = NULL;
public:
    Data() = default;
    Data(std::ifstream&, int);
    virtual ~Data();
    unsigned char* getBuffer() const;
};

#endif // DATA_H