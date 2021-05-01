test: main.cpp Wav.a WavManager.o Noisegate.o Driver.o Echo.h Algorithm.h
	g++ -std=c++11 -o test main.cpp Wav.a WavManager.o Noisegate.o Driver.o

Wav.a: Wav.o MetadataManager.o Metadata.o
	ar suvr Wav.a Wav.o MetadataManager.o Metadata.o

Wav.o: Wav.cpp Wav.h WavHeader.h
	g++ -std=c++11 -c Wav.cpp

MetadataManager.o: MetadataManager.cpp MetadataManager.h MetadataHeader.h
	g++ -std=c++11 -c MetadataManager.cpp

Metadata.o: Metadata.cpp Metadata.h
	g++ -std=c++11 -c Metadata.cpp

WavManager.o: WavManager.cpp WavManager.h
	g++ -std=c++11 -c WavManager.cpp

Noisegate.o: Noisegate.cpp Noisegate.h
	g++ -std=c++11 -c Noisegate.cpp

#Echo.o: Echo.cpp Echo.h
#	g++ -std=c++11 -c Echo.cpp

Driver.o: Driver.cpp Driver.h
	g++ -std=c++11 -c Driver.cpp

clean:
	rm *o *a
