test: main.cpp WavManager.a Driver.o
	g++ -std=c++11 -o test main.cpp WavManager.a Driver.o

WavManager.o: WavManager.cpp WavManager.h
	g++ -std=c++11 -c WavManager.cpp

Wav.o: Wav.cpp Wav.h WavHeader.h
	g++ -std=c++11 -c Wav.cpp

MetadataManager.a: MetadataManager.cpp MetadataManager.h MetadataHeader.h
	g++ -std=c++11 -c MetadataManager.cpp

Metadata.o: Metadata.cpp Metadata.h
	g++ -std=c++11 -c Metadata.cpp

WavManager.a: WavManager.o Wav.o MetadataManager.o Metadata.o
	ar suvr WavManager.a WavManager.o Wav.o MetadataManager.o Metadata.o

Driver.o: Driver.cpp Driver.h IAlgorithm.h Echo.h Noisegate.h Normalization.h
	g++ -std=c++11 -c Driver.cpp

clean:
	rm *o *a
