/**
@mainpage Concatenated Primes
@author Dakota Bosch
*/

/**	\file concat_primes.cpp
\brief Print 5 digits of concatenated primes starting at user inputed index

Program takes in user inputed integer equal or greater than zero but not larger than 999 (using stdin). The program then creates a string of length 1000 of concatenated primes. The user inputed integer is then used to index the string. The indexed integer plus the following four integers are then outputed.

*/

#include<iostream>
#include<string>

/** \brief function to concatenate first 1000 prime number digits into a string

Function takes in no parameters and is called upon by main. Uses a loop to create a string that holds 1000 digits of increasing prime numbers starting at two.

*/
std::string get_concatenated_primes()
{

	std::string primes;       /* string used to store concatenated primes */

	for (int i = 2; primes.length() < 1001; i++)	/*for loop that tests for prime numbers until string length is over 1000 */
	{
		bool k = true;
		for (int j = i - 1; j != 1; j--)
		{
			if (i % j == 0)
			{
				k = false;
			}

		}

		if (k == true)	/* takes all primes found and compiles them within the primes string*/
		{
			primes = primes + std::to_string(i);
		}
	}


	return primes;
}

/**	\brief uses index to find five integers from string

Takes in two parameters; the prime numbers string and the user inputed index. Using the index integer the corresponding string int and following four ints are returned.

*/

std::string get_slice_of_5(const std::string & primes, const int index)
{
	std::string slice;
	for (int i = index; i < index + 5; i++)
	{
		if (i < 1000)
		{
			slice = slice + primes[i];
		}

	}
	return slice;
}

/**     \brief function used to read stdin and call upon other functions

Reads in user int then calls upon get_concatenated_primes function. Using these two parameters it then calls upon get_slice_of_5. Finally using cout it tells the user the return from get_slice_of_5.

*/

int main()
{
	int n;

	while (std::cin >> n)
	{
		std::string concat_primes = get_concatenated_primes();
		std::cout << get_slice_of_5(concat_primes, n) << std::endl;
	}
	return 0;
}
