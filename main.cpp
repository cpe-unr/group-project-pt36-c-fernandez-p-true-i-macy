/**
 * Authors: Parker True, Chris Fernandez, & Ilana Macy
 * Date Due: May 2, 2021
 * Assignment: Semester Project
*/

/** @file */
#include "WavManager.h"
#include "UI.h"

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
    for(int i = 0; i < wm.getSize(); ++i){
        std::cout << "File #" << i << ": " << wm.getWav(i)->getFileName() << std::endl;
        wm.getWav(i)->printMetadata();
        std::cout << std::endl;
    }

    UI ui;
    ui.getMenuChoice();
    
    return 0;
}
