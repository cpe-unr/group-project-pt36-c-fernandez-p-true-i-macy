test: main.cpp Metadata.o MetadataManager.o Wav.o WavManager.o Data.o Noisegate.o
	g++ -std=c++11 -o test main.cpp Metadata.o MetadataManager.o Wav.o WavManager.o Data.o Noisegate.o

Metadata.o: Metadata.cpp Metadata.h
	g++ -std=c++11 -c Metadata.cpp

MetadataManager.o: MetadataManager.cpp MetadataManager.h MetadataHeader.h
	g++ -std=c++11 -c MetadataManager.cpp

Wav.o: Wav.cpp Wav.h WavHeader.h
	g++ -std=c++11 -c Wav.cpp

WavManager.o: WavManager.cpp WavManager.h
	g++ -std=c++11 -c WavManager.cpp

Noisegate.o: Noisegate.cpp Noisegate.h
	g++ -std=c++11 -c Noisegate.cpp

Data.o: Data.cpp Data.h
	g++ -std=c++11 -c Data.cpp

clean:
	rm *o
