/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

/** @file */
#include "WavManager.h"
#include "Driver.h"

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
    if(wm.getSize() < 1){
        return 0;
    }
        ///////////////////////////////////////////////////////////////////////////////////
        wm.getWav(1)->printMetadata(); // FOR SOME REASON DELETING THIS LINE BREAKS THE APP
        ///////////////////////////////////////////////////////////////////////////////////

    // Main Menu
    std::cout << "WAVE FILE PROCESSOR" << std::endl;
    Driver d(wm.selectWav());
    int option;
    do{
        std::cout << std::endl << "1) Apply Processor" << std::endl << "2) Select New File" 
            << std::endl << "3) Output To '.wav' File" << std::endl << "4) Output To '.csv' File" 
            << std::endl << "5) Edit Metadata" << std::endl << "0) EXIT" << std::endl << "SELECT AN OPTION: ";
        std::cin >> option;
        switch(option){
            case 0: break;
            case 1: d.processWav(); break;
            case 2: d.setWav(wm.selectWav()); break;
            case 3: d.outputWavFile(wm.getFileNames()); break;
            case 4: // d.outputCsvFile(); break;
            case 5: // d.editMetadata(); break;
            default: std::cout << std::endl << "Please enter a valid option." << std::endl;
        }
    } while(option != 0);
    
    return 0;
}
