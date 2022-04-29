#include<iostream>
#include<string>
using namespace std;

/**
 	@mainpage Most Frequent Letter
	@author Dakota Bosch
 */

 /**	\file concat_primes.cpp
 \brief Returns most common character and returns count

 Program takes in user inputed string of letters. It compares them to a string containing alphabet. Tracks frequency and finally outputs most frequency letter and it's total count

 */
int get_max_count()
{
char value[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int frequency[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 , 0, 0, 0, 0, 0, 0};
char letter='0';

cout << "Enter as many letters as you'd like, and I'll count them up!\nWhen you're done, enter a ? character.\n\n";


        while (letter != '?')                   // loop used to keep storing user inputed letters until '?'
        {
                cin >> letter;
                for (int i = 0; i < 26; i++)            //loop used to track frequency of each letter
                        if (letter == value[i])
                        frequency[i] = frequency[i]++;
        }

		int counter = 0;                //used to track most used letters

        for(int i = 0; i < 26; i++)             // counts max amount of usage of any letter
        {
                if (frequency[i] > counter)
        counter = frequency[i];
    }
		
        cout << counter << "\n\n";
   return 0;
}


int main()
{
get_max_count() 
    return 0;
}
