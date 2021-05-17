#ifndef PS3_H
#define PS3_H

#include <iostream>
#include <vector>
#include <string>

class ED {
public:
	ED(std::string initRowString, std::string initColumnString);
	int OptDistance(void);
	std::string Alignment(void);

private:
	std::string rowString;
	std::string columnString;
	std::vector<std::vector<int>> matrix;
};

#endif


