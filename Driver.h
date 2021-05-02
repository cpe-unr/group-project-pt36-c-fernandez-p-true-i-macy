#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include "Wav.h"
#include "Algorithm.h"
#include "Echo.h"

class Driver{
private:
    Wav* wav;

    /**
     * @details - processes input Wav with whatever Algorithm you select
    */
    template<typename T>
    void processBuffer(Wav* wav){
        Algorithm<T>* a = getProcessorChoice<T>();
        a->processBuffer(wav->getBuffer<T>(), wav->getBufferSize() / sizeof(T));
        if(wav->getBuffer2<T>() != NULL){
            a->processBuffer(wav->getBuffer2<T>(), wav->getBufferSize() / sizeof(T));
        }
        delete a;
    }

    /**
     * @returns - the Algorithm object you select
    */ 
    template<typename T>
    Algorithm<T>* getProcessorChoice(){
        int option;    
        do{
            std::cout << std::endl  << "1) Normalization" << std::endl << "2) Noisegating" << std::endl 
                << "3) Echo" << std::endl << std::endl << "SELECT AN OPTION: ";
            std::cin >> option;
            switch(option){
                case 1: std::cout << std::endl << "Normalization processed." << std::endl; break;
                    // return new Normalization<T>;
                case 2: std::cout << std::endl << "Noisegate processed." << std::endl; break;
                    // return new Noisegate<T>;
                case 3: 
                    int delay;
                    std::cout << std::endl << "Enter the delay: ";
                    std::cin >> delay; 
                    return new Echo<T>(delay);
                default:
                    std::cout << std::endl << "Please enter a valid option." << std::endl;
            }
        } while(option != 1 && option != 2 && option && 3);
        std::cout << std::endl <<"OPTION " << option << std::endl;
    }

public:
    Driver(Wav* wav) : wav(wav){}
    void setWav(Wav*);
    void processWav();
};

#endif // DRIVER_H