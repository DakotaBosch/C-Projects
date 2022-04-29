q
/**
 *  @brief Implementation of class Roman.
	@Dakota Bosch
 */

#include <string>
#include "roman.hpp"

std::string convertIntToRoman(int);
int convertRomanToInt(std::string);

Roman::Roman() {
   romanStr = "";
}

Roman::Roman(std::string s) {
   SetRoman(s);
}

Roman::Roman(int n) {
   SetRoman(n);
}


Roman::~Roman() {
}


void Roman::SetRoman(std::string s) {
    romanStr = s;
}

void Roman::SetRoman(int n) {
    romanStr = convertIntToRoman(n);
}


std::string Roman::GetRoman() const{
    return romanStr;
}

int Roman::GetInt() const{
    return convertRomanToInt(romanStr);
}


/**
 * \brief Updates current object's romanStr by adding num's romanStr

   \param num object of class Roman
 */
void Roman::IncreaseWith(const Roman & num)
{
romanStr += num;
}

/**
  \brief Convert an integer to a Roman numeral string

  \function takes in an integer and converts the integer into a roman numeral
  string. returns roman numeral string. Starts with the thousands digit and 
  works downward one digit at a time.

  \param n is the input integer
  \return result is the output Roman numeral string
*/
std::string convertIntToRoman(int n)
{
/* declared string that will be used to store Roman numeral string */
  std::string result = "";

/* finds thousands place digit, then adds corresponding roman numeral to string */
  int x = n / 1000;

	  for(int i = 0; i < x; i++)
	  {
		  result += "M";
	  } 
/* reduces n to only a 3 digit number. */  
  n = n % 1000;
 
/* finds the value of the hundreds place and inserts proper roman numeral 
  into result string
 */     
      if (n >= 900)
	  {
	      result += "CM";
	  }

	  else if(n >= 500)
	  {
		  result += "D";
		  x = (n-500) / 100 ;
		  
		  for(int i = 0; i < x; i++)
	  		 {	
			 result += "C";
			 }

	  else if(n >= 400)
	  {  
		  result += "CD";
	  }
	  
	  else
	  {
		    x = n / 100;

 	 	  for(int i = 0; i < x; i++)
	        	 {
		  	 result += "C";			  }	
		 	 }
/* reduces n to only a 2 digit number*/
  n = n % 100;

/*find value of the tens place, then assigns proper roman numeral to string*/	
      if (n >= 90)
	  {
	      result += "XC";
	  }

	  else if(n >= 50)
	  {
		  result += "L";
		  x = (n-50) / 10 ;
		  
		  for(int i = 0; i < x; i++)
			  {
			  result += "X";
			  }	  
			  
	  }

	  else if(n >= 40)
	  {  
		  result += "XL";
	  }
	  
	  else
	  {
		    x = n / 10;
	  	  for(int i = 0; i < x; i++)
			  {
            		  result += "X";
			  }	
	  }
/* reduces n to only 1 digit number */
  n = n % 10;

/* finds value of ones place and adds final roman numerals to string */
	        if (n >= 9)
	  {
	      result += "IX";
	  }

	  else if(n >= 5)
	  {
		  result += "V";
		  x = (n-5);
		  
		  for(int i = 0; i < x; i++)
			  {
	 		  result += "I";
			  }	  
			  
	  }

	  else if(n >= 4)
	  {  
		  result += "IV";
	  }
	  
	  else if(n > 0)
	  {
		    x = n;
	
		  for(int i = 0; i < x; i++)
			  {
              		  result += "I";
			  }	
	  }

  return result;
}


/**
  \brief Convert an integer to a Roman numeral string

  \funtion takes in a string of roman numerals and converts them into an
   integer that is returned. Begins adding up roman numerals starting at
  the end of the string.

  \param instr is the input string
  \return result is the output integer
*/
int convertRomanToInt(std::string instr)
{
  int result = 0;
/* intializes x to be used in the loop
  edits string in order for loop to funciton  
 */
  int x = instr.length();  
  instr.insert(0,1,'a'); 

/* loop that allows for each Roman numeral in the string to be added together.
  loop starts at the end of the string. After a roman numeral is added to the 
  int the place in the string is reduced.
 */ 
  for(int i = x; i > 0; i--)
  {
	  if(instr[i] == 'M')
	  {
		  if(instr[i-1] == 'C')
			  {
				  result += 900;
/* decreases string position by addition one in order to compensate for two
 roman numerals representing one value */
				  i--;		
		      }
		  else
			  result += 1000;
	  }
	  else if(instr[i] == 'D')
	  {
		  if(instr[i-1] == 'C')
		  {
			  result += 400;
			  i--;
		  }
		  else
			  result += 500;
	  }
	   else if(instr[i] == 'C')
	  {
		  if(instr[i-1] == 'X')
		  {
			  result += 90;
			  i--;
		  }			
		  else
			  result += 100;
	  }
	   else if(instr[i] == 'L')
	  {
		  if(instr[i-1] == 'X')
		  {
			  result += 40;
			  i--;
		  }
		  else
			  result += 50;
	  }
	    else if(instr[i] == 'X')
	  {
		  if(instr[i-1] == 'I')
		  {
			  result += 9;
			  i--;
		  }
		  else
			  result += 10;
	  }
	    else if(instr[i] == 'V')
	  {
		  if(instr[i-1] == 'I')
		  {
			  result += 4;
			  i--;
		  }
		  else
			  result += 5;
	  }
		else if(instr[i] == 'I')
			result += 1;
  }

  return result;
}
