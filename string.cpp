#include "string.h"

MyString::MyString ()
{
	//Initializing all variables in the object.
	startIndex		= -1;
	lengthOfLine	= -1;
	length			= -1;
	string_value = new char[1];
	string_value[0] = 0;
}

MyString::~MyString ()
{
	if (string_value)
	{
		delete [] string_value;
		string_value = NULL;
	}
}

void MyString::initial (string line)
{
	lengthOfLine = line.length();   //Gets the length of the string and assigns the value to 'length'.
	return;
}

void MyString::setString (const char* str)
{
	if (!string_value)
	{
		delete [] string_value;
	}
	
	if (str)
	{
		int lengthofstr = strlen(str);	//Setting lengthofstr to the length of 'str'
		char* temp   = new char[lengthofstr + 1];	//Creating a temporary char*
		strcpy(temp, str);	//Setting temp = str.

		int i = 0, j = 0, k = 0, z = 0;

		while (str[i] != '(')
		{
			i++;	//Getting index of '('
		}
		while (str[j] != ')')
		{
			j++;	//Getting index of ')'
		}

		string_value = new char[1];	//Allocating data for string_value

		for (k = i+1; k < j; k++)	//Loop starting at i (the first parenthesis) and continuing to j (2nd parenthsis).
		{
			string_value[z] = str[k];
			z++;
		}

		string_value[z] = '\0';	//Adding a null character to the end of the string after the contents of the parenthesis have been added.
	}
	
	return;
}

MyString MyString::Substring (int startIndex, int length) const
{
	char* sub_str = new char[strlen(string_value)+1];	//Allocating memory for the sub_str char* that is one bigger than the sizeof the orig string. (This is incase the substring is the entire string, the null character will have room).
	int origIndex = 0;
	int i = 0;

	origIndex = startIndex;	//Essentially making a copy of the starting Index that will be manipulated.

	for (i = 0; i < length; i++)	//For loop that assigns the new sub_str a string starting at the 'startIndex' and that's 'length' long.
	{
		sub_str[i] = string_value[origIndex];
		origIndex++;
	}

	sub_str[i] = '\0';	//Setting the next value in the string to NULL

	//cout << sub_str;

	this->Write(cout, sub_str);
	
	return *(this);
}

void MyString::indexof (string substring, int startingIndex)
{
	int i = 0, j = 0, lengthCount = 0, correctCount = 0, lengthOfOrig = 0;

	j = startingIndex;	//Setting J to starting index that way the user dicatates how far in the originals string they would like to start.

	while (substring[lengthCount] != '\0')
	{
		lengthCount ++; //After looping lengthCount is now equal to the length of the substring.
	}
	while (string_value[lengthOfOrig] != '\0')
	{
		lengthOfOrig ++;
	}
	
	while (j <= lengthOfOrig)	//loops until the original string has reached its end+1, therefore if it does there was no match.
	{
		if (substring[i] == string_value[j])
		{
			correctCount++;		//If the values are equivilent correctCount is increased by one (once correctCound == lengthCount the entire string matches).
			i++;				//Increase I and J to move to the next character in each string.
			j++;
		}
		else if (substring[i] != string_value[j])
		{
			correctCount = 0;
			i=0;	//the substring is reset to the beggining and the original string continues to be parsed through.
			j++;
		}
		if (correctCount == lengthCount)
		{
			//The substring has been found in the original string, now printing the starting index of the found substring.
			int startingIndexInString = -1;
			startingIndexInString = j - lengthCount;	//Setting the startingIndexInString to j - lengthCount, AKA the final index - the length.
			this->Write(cout, startingIndexInString);
			//cout << startingIndexInString;
			return;
		}
	}

	if (j > lengthOfOrig)
	{
		this->Write(cout, -1);
		//cout << "-1";
	}

	return;
}

void MyString::bad_char_table ()
{
	int* table = new int[256];	//Initializing a table of 256 integers, to represent the ascii table.

	for (int i = 0; i < 256; i++)
	{
		table[i] = -1;	//Initialized the table and now setting its contents all to -1, AKA empty table.
	}

	int length = 0;

	while (string_value[length] != '\0')
	{
		length++;	//Returns the length of the string.
	}
	length = length + 1;	//Increases count by one to make sure the null terminator is included.

	for (int j = 0; j < length; j++)
	{
		table[(int)string_value[j]] = j;	//Sets the cell (ascii value of current CHAR) to the current J value (The last occurence of that CHAR).
	}

	for (int i = 0; i < 256; i++)
	{
		this->Write(cout, table[i], ',');
	}

	return;
}

void MyString::Split(char c, std::vector<MyString>& outputVector) const
{
	int i = 0;

	while (string_value[i] != '\0')
	{
		if ((int)c != (int)string_value[i])	//If c is not equal to the character of the string, print out that character and increment i.
		{
			this->Write(cout, string_value[i]);
		}
		else if ((int)c == (int)string_value[i])	//If C is equal to the current character of the string print out a coma and increment.
		{
			this->Write(cout, ',');
		}
		i++;
	}

	return;
}

int MyString::GetAnagrams(std::vector<MyString>& candidates, std::vector<MyString>& output)
{
	int i = 0, size = 0, j = 0, k = 0, outputSize = 0;
	
	for (i = 0; i < strlen(line.c_str()); i++)	//Converted line to a c_str, line is equal to the contents of the parenthesis.
	{
		if (line[i] == ',')
		{
			size++;	//When a comma is reached in the line, size is incremented. Therefore if there are 2 commas, size = 2, and the total number of string will be 3. (works since 0 based)
		}
	}

	candidates.resize(size+1);	//Resizes the candidates vector to hold the correct ammount of classes.
	output.resize(size+1);		//Resizes the ouput vector to be able to hold all candidates incase all are anagrams.

	for (i = 0; i <= size; i++)
	{
		while (line[j] != ',' && line[j] != '\0')	//While the original line[j] is not a comma, add that value to the string value (copying).
		{
			candidates[i].string_value[k] = line[j];
			k++;
			j++;
		}
		candidates[i].string_value[k] = '\0';	//Ends the string after the characters have been copied.
		k = 0;	//Reset k since it will be a new variable.
		j++;	//J is incremented so we skip over the comma.
		//cout << candidates[i].string_value << endl;
	}

	int lengthOfString = strlen(string_value);	//Returns the length of the string.
	int vecStrLen = 0;

	//Building a frequency table
	int* string_value_table = new int[256];	//Initializing a table of 256 integers, to represent the ascii table.
	int* vector_table       = new int[256];	//Only have to make one vector table since it will be evaluated and the reused.
	for (int i = 0; i < 256; i++)
	{
		string_value_table[i] = 0;	//Initialized the table and now setting its contents all to 0, to represent no characters.
	}
	for (int j = 0; j < lengthOfString; j++)
	{
		string_value_table[(int)string_value[j]] ++;	//Increments the cell containing the current char.
	}

	///////////////////////////////////////////
	/*for (int i = 0; i < 256; i++)
	{
		cout << string_value_table[i] <<",";
	}*/



	for (i = 0; i <= size; i++)		//Loops through the vector strings to check if they are equal in length to the line. If they are, they are further processed.
	{
		vecStrLen = strlen(candidates[i].string_value);

		if (vecStrLen == lengthOfString)	//Possible anagram.
		{
			for (int i = 0; i < 256; i++)
			{
				vector_table[i] = 0;	//Initialized the table and now setting its contents all to 0, to represent no characters.
			}
			for (int j = 0; j < vecStrLen; j++)	//Loops until the end of the string.
			{
				vector_table[(int)candidates[i].string_value[j]] ++;	//Increments the cell containing the current char.
			}
/////////////////////////////////////////////////////////////////////
			/*cout << endl;
			for (int i = 0; i < 256; i++)
			{
				cout << vector_table[i] <<",";
			}*/

			int z = 0, count = 0;
	
			while (z < 256)
			{
				if (string_value_table[z] == vector_table[z])
				{
					count++;
				}
				z++;
			}
			
			if (count == 256)
			{
				strcpy(output[i].string_value, candidates[i].string_value);	//If the string_value_table is = to the vector_table then we copy the current vector into the ouput vector, and increment output sizer to resize the output vector.
				outputSize++;
			}

		}

		else if (vecStrLen != lengthOfString)	//Not possible to be an anagram.
		{
			break;
		}
	}

	output.resize(outputSize+1);
	for (i=0; i <=outputSize; i++)
	{
		this->Write(cout, output[i].string_value);
	}

	return 0;
}

void MyString::Write (std::ostream& stream) const
{
	stream << string_value;
}

void MyString::Write (std::ostream& stream, char* stringPrint) const
{
	stream << stringPrint;
}

void MyString::Write (std::ostream& stream, int intPrint) const
{
	stream << intPrint << "\n";
}

void MyString::Write (std::ostream& stream, char charPrint) const
{
	stream << charPrint;
}

void MyString::Write (std::ostream& stream, int intPrint, char commaPrint) const
{
	stream << intPrint << commaPrint;
}
