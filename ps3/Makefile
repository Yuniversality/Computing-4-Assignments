CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic -O2 -g
SFML = -lsfml-system
OBJ = ps3.o main.o
EXE = ED

all: $(EXE)

$(EXE): $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(SFML)
	
ps3.o: ps3.cpp ps3.h
	$(CC) $(CFLAGS) -c ps3.cpp -o ps3.o
	
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	
clean:
	rm $(EXE) *.o
	

