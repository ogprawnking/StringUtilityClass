#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <cstring> // gives access to 'str' functions (i.e. strlen, strcmp etc.)

using namespace std;

// constructor w/ no arguments. Set value to '\0'
String::String()
{
	mystring = new char[1];
	mystring[0] = '\0';
	cout << "++ default constructor called" << endl;
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
		cout << "++ Parameterized constructor called" << endl;
		cout << "The string entered is: " << mystring << endl;
	}
	else // make empty string
	{
		mystring = new char[1];
		mystring[0] = '\0';
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

	cout << "++ copy constructor called" << endl;
	cout << "String copied is: " << mystring << endl;
}

String::~String()
{
	delete[] mystring;
	mystring = nullptr;
	cout << "-- string destructor called" << endl;
}

char& String::CharacterAt(size_t _index)
{
	if (_index >= strlen(mystring) || _index < 0)
	{
		// Return '\0' if index is out of range... Ensures empty string.
		char nullChar = '\0';
		return nullChar;
	}
	else
		cout << "character at index " << _index << " is: " << mystring[_index] << endl;
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
		return nullChar;
	}
	else
		cout << "const character at index " << _index << " is: " << mystring[_index] << endl;
	return mystring[_index]; // character at index inputted
}

// Returns an integer representing the count of characters up to the null termination character
size_t String::Length() const
{
	// store length of (mystring) in length variable.
	size_t length = strlen(mystring);

	// if length > 0 then -1 (for nullChar). Else return 0;
	cout << "Length of string is: " << length << endl;
	return (length > 0) ? (length - 1) : 0;
}

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
				return true;
		}
		// else false
	return false;
	}
	else
		return false;
}

//String& String::Append(const String& _str)
//{
//	// TODO: insert return statement here
//}
//
//String& String::Prepend(const String& _str)
//{
//	// TODO: insert return statement here
//}
//
//const char* String::CStr() const
//{
//	return nullptr;
//}
//
//String& String::ToLower()
//{
//	// TODO: insert return statement here
//}
//
//String& String::ToUpper()
//{
//	// TODO: insert return statement here
//}
//
//size_t String::Find(const String& _str)
//{
//	return size_t();
//}
//
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
