CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic -O2 -g
#BOOST_ARG = -lboost_unit_test_framework
SFML = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window
OBJ = CircularBuffer.o StringSound.o KSGuitarSim.o
EXE = KSGuitarSim

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(SFML)

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp -o CircularBuffer.o
	
StringSound.o: StringSound.cpp StringSound.h
	$(CC) $(CFLAGS) -c StringSound.cpp -o StringSound.o
	
KSGuitarSim.o: KSGuitarSim.cpp
	$(CC) $(CFLAGS) -c KSGuitarSim.cpp -o KSGuitarSim.o $(SFML)

clean:
	rm $(EXE) *.o
	

