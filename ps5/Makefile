CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic
SFML = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window
OBJ = TFractal.o Triangle.o
EXE = ps5

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(SFML)

TFractal.o: TFractal.cpp 
	$(CC) $(CFLAGS) -c TFractal.cpp -o TFractal.o
	
Triangle.o: Triangle.cpp Triangle.h
	$(CC) $(CFLAGS) -c Triangle.cpp -o Triangle.o

clean:
	rm $(EXE) *.o
