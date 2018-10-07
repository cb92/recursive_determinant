#include <iostream>
#include "determinant.hpp"


// determinant function takes a 2D square array, and its size. It calculates
// the determinant using the recursive minor expansion formula and returns it
int determinant(int** detArray, int n)
{
	int det = 0, detMult=1, colsFilled=0;
	int ** tempSubArr;

	// the 1x1 matrix is the base case - in this case, return the value
	if (n == 1)
	{
		det = detArray[0][0];
	}
	else
	{
		//allocate memory for temporary array
		tempSubArr = new int*[n-1];
		for (int j=0; j<(n-1); j++)
		{
			tempSubArr[j] = new int[n-1];
		}

		// for every column in the matrix, iteratively add 
		// detArray[0,i]*determinant of minor array*(-1)^i 
		// that corresponds to the entry in the first row and column n
		for (int i=0; i<n; i++)
		{
			colsFilled=0;

			//fill every column of comatrix
			for (int j=0; j<n; j++)
			{
				if (i!=j)
				{
					for (int k=0; k<(n-1); k++)
					{
						tempSubArr[k][colsFilled]=
							detArray[k+1][j];
					}
					colsFilled++;
				}
			}

			// recursive definition of determinant 
			det = det + (detArray[0][i])*detMult*
					determinant(tempSubArr, n-1);
			detMult*=(-1); //next sub-matrix should be opposite sign
		}

		//de-allocate memory for temporary array 
		for (int j=0; j<(n-1); j++)
		{	
			delete [] tempSubArr[j];
		}
		delete [] tempSubArr;


	}
	return det;
}
