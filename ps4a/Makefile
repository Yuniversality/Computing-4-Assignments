CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic -O1 -g
BOOST_ARG = -lboost_unit_test_framework
OBJ = CircularBuffer.o test.o
EXE = ps4a

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(BOOST_ARG)

ps4a.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp -o CircularBuffer.o
	
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o $(BOOST_ARG)
	
clean:
	rm $(EXE) *.o
	

