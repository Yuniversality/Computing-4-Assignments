#include "ps3.h"
#include <SFML/System.hpp>

int main(int argc, char* argv[])
{
	sf::Clock clock;
	sf::Time t;
	
	std::string rowString;		//string for the y-axis of matrix
	std::string columnString;	//string for the x-axis of matrix
	std::cin >> rowString >> columnString;
	
	//Lambda function
	auto runProgram = [rowString, columnString]()
	{
		ED test(rowString, columnString);
		int optimalDistance = test.OptDistance();
		std::cout << "Edit Distance = " << optimalDistance << std::endl;
		std::string pathMessage = test.Alignment();
		std::cout << pathMessage << std::endl;
	};

	runProgram();
	
	//Return program run time
	t = clock.getElapsedTime();
	std::cout << "Execution time is " << t.asSeconds() << " seconds \n";

	return 0;
}


