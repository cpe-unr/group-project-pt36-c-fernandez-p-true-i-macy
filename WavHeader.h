/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

#ifndef WavHeader_H
#define WavHeader_H

struct WavHeader{
    char riffID[4];
    int fileSize; 
    char waveID[4];
    char fmtID[4];
    int fmtSize;
    short audioFmt;
    short numChannels;
    int sampleRate;
    int byteRate;
    short blockAlign; 
    short bitsPerSample;     
    char dataID[4];
    int dataSize;       
};

#endif //WAVEHEADER_H