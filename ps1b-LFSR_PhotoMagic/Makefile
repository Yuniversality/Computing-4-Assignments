CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic
SFML = -lsfml-graphics -lsfml-window -lsfml-system
OBJ = FibLFSR.o PhotoMagic.o

all: PhotoMagic

PhotoMagic: PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o PhotoMagic PhotoMagic.o FibLFSR.o $(SFML)

PhotoMagic.o: PhotoMagic.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o
	
FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

clean:
	rm PhotoMagic *.o


