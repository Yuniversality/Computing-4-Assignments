#include "ps3.h"
static int penalty(char a, char b);
static int min(int a, int b, int c);
const int EDGE_VAL = 99999; 	//arbitrarily large number used to denote the edge of the matrix

ED::ED(std::string initRowString, std::string initColumnString)
{
	rowString = initRowString;			//string for the y-axis of matrix
	columnString = initColumnString;	//string for the x-axis of matrix
	
	//The <= is to get an extra row for the - row at the end
	for (unsigned int i = 0; i <= rowString.length(); ++i)
	{
		//Set up the y-axis
		std::vector<int> row;
		matrix.push_back(row);

		//The <= is to get an extra column for the - column at the end
		for (unsigned int j = 0; j <= columnString.length(); ++j)
		{
			//Set up the x-axis, fill each entry with 0
			matrix[i].push_back(0);
		}
	}
}

int ED::OptDistance(void)
{
	int bottomRow = matrix.size() - 1;
	int rightmostColumn = matrix[bottomRow].size() - 1;

	//Start from the bottom row, then move up
	//Fills the right edge of matrix
	for (int i = bottomRow; i >= 0; --i)
	{
		matrix[i][rightmostColumn] = ((bottomRow - i) * 2);
	}

	//Start from the rightmost column, then move to the left
	//Fills in the bottom edge
	for (int j = rightmostColumn; j >= 0; --j)
	{
		matrix[bottomRow][j] = ((rightmostColumn - j) * 2);
	}

	//Fill in the rest of the entries
	for (int r = bottomRow - 1; r >= 0; --r)
	{
		for (int c = rightmostColumn - 1; c >= 0; --c)
		{
			int rightVal = matrix[r][c + 1];
			int diagonalVal = matrix[r + 1][c + 1];
			int bottomVal = matrix[r + 1][c];
			int diagonalPenalty = penalty(rowString[r], columnString[c]);

			matrix[r][c] = min(rightVal + 2, diagonalVal + diagonalPenalty, bottomVal + 2);
		}
	}

	/*
	//Test to see if matrix is set up right
	for (unsigned int i = 0; i < matrix.size(); ++i)
	{
		for (unsigned int j = 0; j < matrix[i].size(); ++j)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	*/

	return matrix[0][0];
}

std::string ED::Alignment(void)
{
	int bottomRow = matrix.size() - 1;
	int rightmostColumn = matrix[bottomRow].size() - 1;
	std::string pathMessage = "";
	int r = 0;
	int c = 0;

	while ((r != bottomRow) || (c != rightmostColumn))
	{
		int rightVal, diagonalVal, bottomVal;

		if (c != rightmostColumn) 
		{
			rightVal = matrix[r][c + 1];
		}
		else
		{
			rightVal = EDGE_VAL;
		}

		if (r != bottomRow)
		{
			bottomVal = matrix[r + 1][c];
		}
		else
		{
			bottomVal = EDGE_VAL;
		}

		if (!((rightVal == EDGE_VAL) || (bottomVal == EDGE_VAL)))
		{
			diagonalVal = matrix[r + 1][c + 1];
		}
		else
		{
			diagonalVal = EDGE_VAL;
		}

		int penaltyVal = penalty(rowString[r], columnString[c]);

		//If the next step is to the diagonal entry
		if (matrix[r][c] == (diagonalVal + penaltyVal))
		{
			pathMessage = pathMessage + rowString[r] + " " 
				+ columnString[c] + " " + std::to_string(penaltyVal) + "\n";
			r = r + 1;
			c = c + 1;
		}

		//If the next step is to the bottom entry
		else if (matrix[r][c] == (bottomVal + 2))
		{
			pathMessage = pathMessage + rowString[r]
				+ " - " + std::to_string(2) + "\n";
			r = r + 1;
		}

		//If the next step is to the right entry
		else if (matrix[r][c] == (rightVal + 2))
		{
			pathMessage = pathMessage + "- " + columnString[c] +
				" " + std::to_string(2) + "\n";
			c = c + 1;
		}
		else
		{
			std::cout << "Idk what happened \n";
			pathMessage = pathMessage;
		}
	}
	
	return pathMessage;
}

//Aligning 2 characters that match = 0, mismatch = 1
static int penalty(char a, char b)
{
	return !(a == b);
}

//Finds the minimum of 3 values
static int min(int a, int b, int c)
{
	int minimum = a;
	if (b < minimum)
	{
		minimum = b;
	}
	if (c < minimum)
	{
		minimum = c;
	}

	return minimum;
}


