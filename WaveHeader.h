#ifndef WAVEHEADER_H
#define WAVEHEADER_H

/*
 * This header copied from https://gist.github.com/Jon-Schneider/8b7c53d27a7a13346a643dac9c19d34f
 * https://docs.fileformat.com/audio/wav/
 * 
 *  Positions:	(Sample) Value: Description:
 *  1-4	        “RIFF”	        Marks the file as a riff file. Characters are each 1 byte long.
 *  5-8	        fileSize        Size of overall file - 8 (in bytes). 32-bit integer. Typically, you’d fill this in after creation.
 *  9-12	    “WAVE”	        File type header. Always equals “WAVE”.
 *  13-16	    “fmt "	        Format chunk marker. Includes 'space' as 4th character.
 *  17-20	    16              Length of format chunk (in bytes).
 *  21-22	    1	            Type of format (always 1 for PCM). 
 *  23-24	    numChannels	    Number of Channels - 2 byte integer
 *  25-28	    44100	        Sample Rate - 32 byte integer. Common values are 44100 (CD), 48000 (DAT). Sample Rate = Number of Samples per second, or Hertz.
 *  29-32	    176400	        (Sample Rate * BitsPerSample * Channels) / 8.
 *  33-34	    bytesPerBlock	(BitsPerSample * Channels) / 8.1 - 8 bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo
 *  35-36	    bitsPerSample	Bits per sample
 *  37-40	    “data”	        “data” chunk header. Marks the beginning of the data section.
 *  41-44	    dataChunkSize 	Size of the data section.
 */

typedef struct wav_header {
    char riff_header[4];
    int wav_size; 
    char wave_header[4];
    char fmt_header[4];
    int fmt_chunk_size;
    short audio_format;
    short num_channels;     // numChannels
    int sample_rate;
    int byte_rate;
    short sample_alignment; // bytesPerBlock (bytesPerSample * numChannels)
    short bit_depth;        // bitsPerSample
    char data_header[4];
    int data_bytes;         // bufferSize
} wav_header;

#endif //WAVEHEADER_H