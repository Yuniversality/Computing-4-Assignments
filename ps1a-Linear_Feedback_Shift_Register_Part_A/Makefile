CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic
BOOST_ARG = -lboost_unit_test_framework
OBJ = FibLFSR.o test.o
EXE = ps1a

all: ps1a

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o $(BOOST_ARG)

ps1a: $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(BOOST_ARG)

clean:
	rm -f $(EXE) $(OBJ) *.o


