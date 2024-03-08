#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <cstring> // gives access to 'str' functions (i.e. strlen, strcmp etc.)

using namespace std;

// Default  constructor. string = '\0'
	String::String()
{
	mystring = new char[1];
	mystring[0] = '\0';
	//cout << "PART1		++ default constructor called" << endl;
}

// constructor w/ 1 argument
// allocates space for inputted _str to mystring
// then copies _str into the space of mystring
String::String(const char* _str) // overloaded or parameterized
{
	if (_str != nullptr) // if string is inputted
	{
		mystring = new char[strlen(_str) + 1]; // +1 makes space for nullchar
		strcpy(mystring, _str);
		mystring[strlen(_str)] = '\0'; // adds nullchar to the end of array.
		//cout << "PART 2		++ Parameterized constructor called" << endl;
		//cout << "The string entered is: " << mystring << endl;
	}
	else // make empty string
	{
		mystring = new char[1];
		mystring[0] = '\0';
		//cout << "PART 2		++ Overlaoded constructor called" << endl;
		//cout << "Invalid input. Empty string created.\n" << endl;
	}
}

// copy constructor (deep copy)
// enter reference to another class and object
String::String(const String& _other)
{
	// make space for the inputted object
	mystring = new char[strlen(_other.mystring) + 1];
	// copy _other.mystring(existing string) to mystring of this new class made.
	strcpy(mystring, _other.mystring);
	mystring[strlen(_other.mystring)] = '\0'; // --good practice--

	//cout << "PART 3		++ copy constructor called" << endl;
	//cout << "String copied is: " << mystring << endl;
}

String::~String()
{
	delete[] mystring;
	mystring = nullptr;
	
	cout << "-- string DESTRUCTOR called" << endl;
}

char& String::CharacterAt(size_t _index)
{
	if (_index >= strlen(mystring) || _index < 0)
	{
		// Return '\0' if index is out of range... Ensures empty string.
		char nullChar = '\0';
		//cout << "PART 4		++characterAt constructor called" << endl;
		//cout << "Index out of range. Empty string created";
		return nullChar;
	}
	else
		//cout << "PART 4		++CharacterAt Constructor called" << endl; 
		//cout << "character at index " << _index << " is: " << mystring[_index] << "\n" << endl;
		return mystring[_index]; // character at index inputted
}

// The return type is a reference to a const char, which means that the caller cannot modify the character retrieved through this function.
//body is the same as the one before... just uses const instead of non-const.
const char& String::CharacterAt(size_t _index) const // const after means it won't change what was inputted.
{
	if (_index >= strlen(mystring) || _index < 0)
	{
		// Return '\0' if index is out of range... Ensures empty string.
		char nullChar = '\0';
		//cout << "PART 4		++CONSTcharacterAt constructor called" << endl;
		//cout << "Index out of range. Empty string created";
		return nullChar;
	}
	else
	//cout << "PART 4 ALT	++CONSTcharacterAt Constructor called" << endl;
	//cout << "const character at index " << _index << " is: " << mystring[_index] << "\n" << endl;
	return mystring[_index]; // character at index inputted
}

// Returns an integer representing the count of characters up to the null termination character
size_t String::Length() const
{
	// store length of (mystring) in length variable.
	size_t length = strlen(mystring);

	// if length > 0 then -1 (for nullChar). Else return 0;
	//cout << "PART 5		++Length constructor called" << endl;
	//cout << "Length of string is: " << length << "\n" << endl;
	return (length > 0) ? (length) : 0;
}

//				OR use below method.

//size_t String::Length() const
//{
//	// store length of (mystring) in length variable.
//	size_t length = 0;
//	while (mystring[length] != '\0')
//		length++;
//		return length;
//}




// Returns true if str contains the same characters.
bool String::EqualTo(const String& _other) const
{
	// Are both strings same length?
	if (Length() == _other.Length())
	{
		// compare each character from input string and  known string.
		for (size_t i = 0; i < Length(); i++)
		{
			// If char's aren equal return true.
			if (mystring[i] == _other.mystring[i])
				//cout << "PART 6		++EqualTo constructor called" << endl;
				//cout << "The strings ARE equal. \n" << endl;
				return true;
		}
	// else false
	return false;
	}
	else
		//cout << "PART 6		++EqualTo constrcutor called" << endl;
		//cout << "The strings are NOT equal. \n" << endl;
		return false;
}
// Adds _str to end of string
String& String::Append(const String& _str)
{
	// add sizes of strings together
	size_t sizeNewString = Length() + _str.Length();
	
	// allocate memory for full string(newstring)
	char* newString = new char[sizeNewString + 1]; // +1 for nullchar

	// copy current string to newString
	//	newstring = mystring
	strcpy(newString, mystring);

	// concatenate newinput data (_str) to newString
	strcat(newString, _str.mystring);

	// delete old memory from old string
	delete[] mystring;

	// update to point to new string
	mystring = newString;
	
	//cout << "PART 7		++Append constructor called" << endl;
	//cout << "Appended string is: " << mystring << "\n" << endl;

	// return reference to modified object
	return *this;

}
// Adds _str to the beginning of the string
String& String::Prepend(const String& _str)
{
	// add size of both strings together
	size_t sizeOfNewString = Length() + _str.Length();
	// allocate memory for full string
	char* newString = new char[sizeOfNewString + 1];
	// copy current string to newString
	// newstring = mystring
	strcpy(newString, _str.mystring);
	// concatenate newinput data (_str) to newstring)
	strcat(newString, mystring);
	// delete old memory from old string
	delete[] mystring;
	// update old string to point to new string
	mystring = newString;
	//cout << "PART 8		++Prepend constructor called" << endl;
	//cout << "Prepended string is: " << mystring << "\n" << endl;

	 return *this;
}

// retrieves underlying C-style string from Strin object.
// Use with std::cout to print string.
const char* String::CStr() const
{
	return mystring;
}

String& String::ToLower()
{
	for (int i = 0; i < Length(); i++)
	{
		mystring[i] = tolower(mystring[i]);
	}
	return *this;
}


String& String::ToUpper()
{
	for (int i = 0; i < Length(); i++)
	{
		mystring[i] = toupper(mystring[i]);
	}
	return *this;
}

size_t String::Find(const String& _str)
{
	// Returns the location of the findString.If not found, return -1
	size_t len = Length(); // length of original string
	size_t subLen = _str.Length(); // length of input string

	if (subLen > len) return string::npos;// if substring longer than og string. return -1 OR string::npos

	// iterate through mains tring while searching for substring
	for (size_t i = 0; i <= len - subLen; i++)
	{
		// check if substring matches the portion of the main string
		bool found = true;
		for (size_t j = 0; j < subLen; j++)
		{
			if (mystring[i + j] != _str.mystring[j])
			{
			found = false;
			break; // break inner loop if chars don't match
			}
		}
		//if found, return starting index
		if (found)
		{
			//cout << "String found! Beginning at index: " << i << "\n";
			return i;
		}
	}

	return string::npos; // Substring not found or string::npos
}

//size_t String::Find(size_t _startIndex, const String& _str)
//{
//	return size_t();
//}
//
//String& String::Replace(const String& _find, const String& _replace)
//{
//	// TODO: insert return statement here
//}
//
//String& String::ReadFromConsole()
//{
//	// TODO: insert return statement here
//}
//
//String& String::WriteToConsole()
//{
//	// TODO: insert return statement here
//}
//
//bool String::operator==(const String& _other)
//{
//	return false;
//}
//
//bool String::operator!=(const String& _other)
//{
//	return false;
//}
//
//String& String::operator=(const String& _str)
//{
//	// TODO: insert return statement here
//}
//
//char& String::operator[](size_t _index)
//{
//	// TODO: insert return statement here
//}
//
//const char& String::operator[](size_t _index) const
//{
//	// TODO: insert return statement here
//}
