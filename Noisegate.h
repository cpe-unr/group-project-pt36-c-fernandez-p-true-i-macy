/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef NOISE_GATE_H
#define NOISE_GATE_H

class Noisegate {

	int newNum;

public:

	Noisegate() = default;
	Noisegate(int numbers);
	void processBuffer(unsigned char* buffer, int bufferSize);

};

#endif
