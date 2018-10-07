/********************************************************************* 
** Program name: Determinant Calculator
** Author: Christina Brasco
** Date: October 6, 2018
** Description: This program prompts the user to define a matrix size
** and the values that fill that matrix, then calculates and returns
** the determinant of that matrix
*********************************************************************/

#include "determinant.hpp"
#include "utils.hpp"
#include <iostream>
#include <climits>

// to run this program, enter matrix size and filler ints when prompted
int main()
{
	//define variables to hold 2d matrix, size, and value of the determinant
	int ** mat;
	int matSize, detValue;

	//prompt user for matrix size
	std::cout<<"Please enter your desired matrix size (2 or 3):"<<std::endl;
	matSize=getInt(2,3);

	// dynamically allocate array memory, fill with user input
	mat = new int*[matSize];
	for (int i=0; i<matSize; i++)
	{
		mat[i] = new int[matSize];
		for (int j=0; j<matSize; j++)
		{
			std::cout<<"Please enter a number for matrix location ["
				<<i<<", "<<j<<"]: "<<std::endl;
			// allow user to enter any allowed int
			mat[i][j] = getInt(INT_MIN, INT_MAX); 
		}
	}

	// get determinant value
	detValue = determinant(mat, matSize);


	//print matrix and determinant
	std::cout<<"Matrix:"<<std::endl;
	for (int j=0; j<matSize; j++)
	{
		for (int i=0; i<matSize; i++)
			std::cout<<mat[j][i]<<" ";
		std::cout<<std::endl;
	}

	std::cout<<"Determinant: "<<detValue<<std::endl;

	//un-allocate memory
	for (int j=0; j<matSize; j++)
	{	
		delete [] mat[j];
	}
	delete [] mat;

	return 0;
}   
