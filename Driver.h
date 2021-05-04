#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include "Wav.h"
#include "IAlgorithm.h"
#include "Echo.h"
#include "Noisegate.h"
#include "Normalization.h"

class Driver{
private:
    Wav* wav;

    /**
     * @details - processes input Wav with whatever Algorithm you select
    */
    template<typename T>
    void processBuffer(Wav* wav){
        IAlgorithm<T>* a = getProcessorChoice<T>();
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
    IAlgorithm<T>* getProcessorChoice(){
        int option;    
        do{
            std::cout << std::endl  << "1) Normalization" << std::endl << "2) Noisegating" << std::endl 
                << "3) Echo" << std::endl << "SELECT AN OPTION: ";
            std::cin >> option;
            switch(option){
                case 1: 
                    int max;
                    std::cout << std::endl << "ENTER MAX: ";
                    std::cin >> max;
                    std::cout << std::endl << "Normalization processed." << std::endl;
                    return new Normalization<T>(max);
                case 2: 
                    int threshold;
                    std::cout << std::endl << "ENTER THRESHOLD: ";
                    std::cin >> threshold; 
                    std::cout << std::endl << "Noisegate processed." << std::endl; 
                    return new Noisegate<T>(threshold);
                case 3: 
                    int delay;
                    std::cout << std::endl << "ENTER DELAY: ";
                    std::cin >> delay; 
                    std::cout << std::endl << "Echo processed." << std::endl;
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
    void outputWavFile(std::vector<std::string>);
    void outputCSVFile(std::vector<Wav*>);
    void editMetadata();
};

#endif // DRIVER_H