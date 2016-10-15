#include "string.h"

int main (void)
{
	cout << "Dillon Johnson, 11423048." << endl;

	MyString StringObject;

	while (true)
	{
		getline (std::cin, StringObject.line); //Gets the line from the user or file and places it into string line.
		StringObject.initial(StringObject.line);

		//Checking to see if the command is set.
		if (0 == StringObject.line.compare (0, 3, "set"))
		{
			/*char* test = new char[StringObject.line.length()+1];
			strcpy(test, StringObject.line.c_str());*/
			StringObject.setString (StringObject.line.c_str());	//Converted to a C_str.
		}

		else if (0 == StringObject.line.compare (0, 6, "substr"))
		{
			int commaIndex = StringObject.line.find (",");			//Finds the index of the comma in the line. This will be used to make our substrings with the two data fields passed in.
			int commaSearchAmount = commaIndex - 7;					//An int that is set to the index of the comma - the initial comma amount with the added parenthesis. AKA 6+1
			string tempStartIndex = StringObject.line.substr (7,commaSearchAmount);
			int startIndex = stoi(tempStartIndex);					//Converts the starting index string to an int.
			int lengthOfLine = StringObject.line.length();
			string tempLengthToParse = StringObject.line.substr (commaIndex + 1, (lengthOfLine - commaIndex - 2));
			lengthOfLine = stoi(tempLengthToParse);					//Converts the length string to an integer.

			StringObject.Substring(startIndex, lengthOfLine);
			cout << "\n";
		}

		else if (0 == StringObject.line.compare (0, 7, "indexof"))
		{
			int commaIndex = StringObject.line.find (",");			//Finds the index of the comma in the line. This will be used to make our substrings with the two data fields passed in.
			int commaSearchAmount = commaIndex - 8;					//An int that is set to the index of the comma - the initial comma amount with the added parenthesis.
			string substring = StringObject.line.substr (8,commaSearchAmount);
			int lengthOfLine = StringObject.line.length();
			string indexString = StringObject.line.substr (commaIndex + 1, (lengthOfLine - commaIndex - 2));
			int index = stoi(indexString);

			StringObject.indexof (substring, index);
			//cout << "\n";
		}

		else if (0 == StringObject.line.compare (0, 14, "bad_char_table"))
		{
			StringObject.bad_char_table();
			cout << "\n";
		}

		else if (0 == StringObject.line.compare (0, 5, "split"))
		{
			char c;
			int parenthesis = StringObject.line.find ("(");		//Finds the character between the parenthesis and sets it to 'c'.
			string characterSubstring = StringObject.line.substr (parenthesis+1, 1);
			c = characterSubstring[0];

			
			std::vector<MyString> splitString;
			StringObject.Split(c, splitString);
			cout << ",\n";
		}

		else if (0 == StringObject.line.compare (0, 8, "anagrams"))
		{
			vector<MyString> candidates, output;				//Initializing two vectors, one for candidates, and one for output.

			int finalP = StringObject.line.find (")");			//Finds the index of the ) in the line. This will be used to make our substrings with the two data fields passed in.
			int searchamount = finalP - 9;						//An int that is set to the index of the ) - the initial ) amount with the added parenthesis.
			string substring = StringObject.line.substr (9,searchamount);

			StringObject.line = substring;

			StringObject.GetAnagrams(candidates, output);
			cout << "\n";
		}

		else if (0 == StringObject.line.compare (0, 4, "quit"))
		{
			cout << "Done" << "\n";
			break;
		}

		else
		{
			cout << "Unknown Command: " << StringObject.line << "\n";
		}
	}

	return 0;
}
