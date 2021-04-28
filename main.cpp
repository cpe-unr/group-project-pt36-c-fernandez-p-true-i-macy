/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

/** @file */
#include "WavManager.h"
#include <iostream>

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */

/**
 * Purpose of function
 * What does it do
*/
void fn(){

}

/**
 * Purpose of function
 * What does it do
 * What does it print
 * @param argc - amount in command line
 * @param argv - filename
 * @return - 0
*/
int main(int argc, char* const argv[]){
    // Read input directory into WavManager object
    // Each file saved as Wav object in WavManager.wavs vector
    if(argc != 2){
        std::cout << "Correct usage:" << std::endl;
        std::cout << argv[0] << " path (ex: \"./test audiofiles\")" << std::endl;
        return 0;
    }
    
    WavManager wm(argv[1]);
    for(int i = 0; i < wm.getSize(); ++i){
        std::cout << "File #" << i << ": " << wm.getWav(i)->getFileName() << std::endl;
        wm.getWav(i)->printMetadata();
        std::cout << std::endl;
    }

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
    
    return 0;
}
