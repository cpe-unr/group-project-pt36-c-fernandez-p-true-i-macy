test: main.cpp Metadata.o MetadataManager.o Wav.o
	g++ -std=c++11 -o test main.cpp Metadata.o MetadataManager.o Wav.o

Metadata.o: Metadata.cpp Metadata.h
	g++ -std=c++11 -c Metadata.cpp

MetadataManager.o: MetadataManager.cpp MetadataManager.h MetadataHeader.h
	g++ -std=c++11 -c MetadataManager.cpp

Wav.o: Wav.cpp Wav.h WaveHeader.h
	g++ -std=c++11 -c Wav.cpp

clean:
	rm *o