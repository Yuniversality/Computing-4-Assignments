#include "FibLFSR.h"

const int ASCII_0 = 48;
const int ASCII_1 = 49;
const int NUM_BITS_WE_WANT = 16;
const int LEFTMOST_BIT_POSITION = 0; //15
const int TAP_BIT_POSITION_1 = 2; //13 
const int TAP_BIT_POSITION_2 = 3; //12
const int TAP_BIT_POSITION_3 = 5; //10

std::ostream& operator<< (std::ostream& outputStream, const FibLFSR& fibLFSR)
{
	for (int i = 0; i < fibLFSR.vectorLength; i++)
	{
		outputStream << fibLFSR.bitVector[i];
	}

	outputStream << "\t" << fibLFSR.resultValue;
	return outputStream;
}

FibLFSRException::FibLFSRException(std::string message)
{
	errorMessage = message;
}

FibLFSR::FibLFSR(std::string seed)
{
	tapBits[0] = TAP_BIT_POSITION_1;
	tapBits[1] = TAP_BIT_POSITION_2;
	tapBits[2] = TAP_BIT_POSITION_3;
	tapBits[3] = LEFTMOST_BIT_POSITION;

	resultValue = 0;
	vectorLength = seed.length();

	if (vectorLength != NUM_BITS_WE_WANT)
	{
		throw FibLFSRException("Incorrect number of bits");
	}

	for (int i = 0; i < vectorLength; i++)
	{
		if (seed[i] == ASCII_0 || seed[i] == ASCII_1)
		{
			bitVector.push_back(seed[i] - ASCII_0);
			//since seed[i] is a char, we need to adjust it to its int value
		}
		else
		{
			throw FibLFSRException("Non-binary digit detected");
		}
	}
}

int FibLFSR::step(void)
{
	int xorResult = 0;

	xorResult = (bitVector[TAP_BIT_POSITION_1] ^ bitVector[TAP_BIT_POSITION_2]) 
		^ (bitVector[TAP_BIT_POSITION_3] ^ bitVector[LEFTMOST_BIT_POSITION]);

	bitVector.erase(bitVector.begin());	//Erase the first element of the bitVector
	bitVector.push_back(xorResult);		//Add the xor result to the back of the bitVector

	resultValue = xorResult;

	return xorResult;
}

int FibLFSR::generate(int k)
{
	int resultInteger = 0;

	for (int i = 0; i < k; i++)
	{
		resultInteger = (resultInteger << 1) + this->step();
		//left shift the bitVector then add the XOR bit to the end
	}

	resultValue = resultInteger;

	return resultInteger;
}



