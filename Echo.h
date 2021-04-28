/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef ECHO_H
#define ECHO_H

class Echo {

	int newDelay;

public:
	
	Echo() = default;
	explicit Echo(int delay);
	void processBuffer(unsigned char *buffer, int bufferSize);

};

#endif

