#define _CRT_SECURE_NO_WARNINGS

// Dillon Johnson
// 1/24/16
// CptS 223
// EOLDS

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;

class MyString
{
	private:
		char* string_value;							//When 'setting' the string, this is the string that is entered to be the current string.
		int startIndex;								//A non negative number that is less than the length of the string, indicating the index of which to start the command.
		int lengthOfLine;							//The length of the string.
		int length;									//The entered length to parse throught the string.

	public:
		MyString ();								//Constructor for the MyString class.
		~MyString ();
		void initial (string);						//Initial function called in main to initialize all variables.
		void setString (const char* test);			//Sets the string to the entered user value, prints nothing.
		MyString Substring (int startIndex, int length) const;	//Creates a substring of the current string according to the parameters entered by the user and then prints the resulting string.
		void indexof (string, int);					//Dispalys an integer that is the starting indec of the substring within the current string, accepts a substring and the starting index as an int.
		void Write(std::ostream& stream) const;		//Writes the passed in string to the screen.
		void bad_char_table (void);					//Builds and Displays the bad char table for the intital set string.
		void Split(char c, std::vector<MyString>& outputVector) const;	//Splits the string by the entered character, therefore replacing that character with a comma.
		int GetAnagrams(std::vector<MyString>& candidates, std::vector<MyString>& output);
		void Write (std::ostream& stream, char* stringPrint) const;
		void Write (std::ostream& stream, int intPrint) const;
		void Write (std::ostream& stream, int intPrint, char commaPrint) const;
		void Write (std::ostream& stream, char charPrint) const;
		string line;								//Initial Line variable holding the read in line from getline().
};
