
#ifndef FIBLFSR_H 
#define FIBLFSR_H 

#include <iostream>
#include <string>
#include <vector>

class FibLFSR {
public:
	FibLFSR(std::string seed);
	// constructor to create LFSR with the given initial seed and ta

	int step(void);
	// simulate one step and return the new bit as 0 or 1

	int generate(int k);
	// simulate k steps and return k-bit integer

	friend std::ostream& operator<< (std::ostream& outputStream, const FibLFSR& fibLFSR);
	//overloading the output operator

private:
	std::vector<int> bitVector;	// what we put the seed into and use for step()
	int vectorLength;		// size of the vector
	int tapBits[4];			// these are the bits you XOR together
	int resultValue;		// the value returned after step() or generate()

};

std::ostream& operator<< (std::ostream& outputStream, const FibLFSR& fibLFSR);

class FibLFSRException
{
public:
	FibLFSRException(std::string message);

private:
	std::string errorMessage;
};

#endif



