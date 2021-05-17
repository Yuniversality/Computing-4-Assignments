CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic
OTHER_FLAGS = -lboost_regex -lboost_date_time
OBJ = main.o
EXE = ps6

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(OTHER_FLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(OTHER_FLAGS)

clean:
	rm $(EXE) *.o


