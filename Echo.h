/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef ECHO_H
#define ECHO_H

#include "Algorithm.h"

template<typename T>
class Echo : public Algorithm<T>{

	int newDelay;

public:
	
	Echo() = default;
	explicit Echo(int delay);
	void processBuffer(unsigned char *buffer, int bufferSize);

};

#endif

