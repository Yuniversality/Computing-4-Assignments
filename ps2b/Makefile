CC = g++
CFLAGS = -Wall -Werror -ansi -std=c++17 -pedantic -O1
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJ = NBody.o main.o
ASSETS = earth.gif mars.gif mercury.gif sun.gif venus.gif starfield.jpg Worship_the_Endless.ogg OpenSans-Regular.ttf
EXE = NBody


all: $(EXE)

$(EXE): $(OBJ) $(ASSETS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(SFML)

NBody.o: NBody.cpp NBody.h
	$(CC) $(CFLAGS) -c NBody.cpp -o NBody.o
        
main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm $(EXE) *.o


