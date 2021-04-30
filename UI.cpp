#include "UI.h"

int UI::getMenuChoice(){
    int option, amountChoosen;
    std::cout << "How many things would you like to do to the audio file. 0 to EXIT" << std::endl; //Add the amount between things in print statement
    std::cin >> amountChoosen;
    if(amountChoosen != 0){
        std::cout << "Please select the first option you would like to choose." << std::endl << "Normalization - 1" << std::endl << "Noisegating - 2" << std::endl << "Echo - 3" << std::endl << "EXIT - 0" << std::endl; 
    }
    for(int i = 0; i < amountChoosen; i++){
        std::cout << "Please pick an option" << std::endl;
        std::cin >> option;
        //Might use switch statement ask TA or Lancaster if its allowed
        if(option == 0){
            //Exit Option
            return 0;
        }
        else if(option == 1){
            //call cpp file for Normalization
            std::cout << "option 1" << std::endl;
        }
        else if(option == 2){
            //call cpp file for Noisegating
            std::cout << "option 2" << std::endl;
        }
        else if(option == 3){
            //call cpp file for Echo
            std::cout << "option 3" << std::endl;
        }
        
    }
}