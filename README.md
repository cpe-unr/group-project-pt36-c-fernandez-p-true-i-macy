# CS 202 Semester Project Template

- Chris Fernandez
- Parker True
- Ilana Macy

Responsibilities:

Chris - Running Doxygen, UML Diagram, Echo, NoiseGate, CSV Metadata

Parker - Wav files, Metadatas, Editing, Normalization, Echo, NoiseGate, Metadata,

Ilana - Doxygen, Normalization, CSV Metadata Overwriting, Documentation Page

DESCRIPTION:

- The user can run their files through a command line argument where the input directory is read into a WavManager object, and each file is saved as a Wav object in a vector. The Main menu is then accessible by the user and the user can choose whether to apply processor, select new file, output to .wav file, output to .csv file, or edit metadata. The user then has the option to choose what type of processing and how many processes they want their input file to go through. The options being normalization, noise gating, or echo. The option(s) they choose are then processed and are outputted to the user’s respective decision to either write to a .wav or .csv file.


Metadata: 

- All the information of the input file from the user is constructed into a Metadata chunk where the ID, size, calcSize, and buffer are all included 

Wav: 

- Wav is where the input file is constructed into a Wav object which allows the input file to be processed and used in this project. Vectors are included in this section as well containing lists of filenames already used and .wav files are created through here in order to output those files. There is a vector for Wavs as well where the .csv files are created and outputted like the .wav files do. Other features included in this part are getting the bufferSize, getting the bits per sample, printing the metadata. 

Processor: 
- The base template for the processor algorithms is the class we implemented called IAlgorithm. The three processing options are normalization, noise gating and echo and each have the common method “processBuffer()” in common where the buffer and bufferSize are taken from the Wav files and Metdata files.

- UML listed under "Final_Project_UML.png"

CHALLENGES:

- The Doxygen Command Failed to work on some members terminals.

- Chris' pulling decided to not work and needed to be adjusted so he could pull code

- Learning Wav File Format
