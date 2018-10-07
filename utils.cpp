//function definition of input validation function

#include "utils.hpp"
#include <iostream>

// constants to indicate ASCII range of integers
const int ASCII_INT_MIN = 48;
const int ASCII_INT_MAX = 57;

// input validation requires two ints, to indicate the allowed range for input
// the function will prompt a user to enter an int until 
// an appropriate one is entered
int getInt(int min, int max)
{
	std::string retString; // string to hold input value
	std::getline(std::cin, retString);
	bool isGoodInput=false;
	int nIter=0;
	char tempChar;
	bool isNeg=false;
	int retInt=0;

	while (!isGoodInput)
	{
		isGoodInput = true; //assume good input until proven otherwise
		// get input again if required
		if (nIter>0)
		{
			std::cout<<"Bad input! Please enter an integer between "
				<<min<<" and "<<max<<"."<<std::endl;
			std::getline(std::cin, retString);
		}

		// process the string, char by char, to see if it's a numeric
		for (int i=0; i<retString.length(); i++)
		{
			tempChar = static_cast<char>(retString[i]);
			// check if first character is negative sign
			if (i==0 & tempChar=='-')
			{
				isNeg=true;
				continue;
			}
			else 
			{
				// if char is numeric, update the return int
				if (tempChar>=ASCII_INT_MIN && 
						tempChar<=ASCII_INT_MAX) 
				{
					retInt = retInt*10+
						(static_cast<int>(tempChar)-
							ASCII_INT_MIN);
				}
				// otherwise bad input, break for loop
				else 
				{
					isGoodInput = false;
					break;
				}
			}
		}

		// if the input is numeric and is negative, make it negative 
		if (isGoodInput && isNeg)
		{
			retInt = (-1)*retInt;
		}
		
		// if ths input is numeric and outside desired range, bad input
		if (isGoodInput && (retInt<min || retInt>max))
		{
			isGoodInput = false;
		}

		//if loop has finished with bad input, reset tracker values 
		if (!isGoodInput) 
		{
			retInt=0;
			isNeg=false;
		}
			
		nIter++;
	}

	return retInt;
}
