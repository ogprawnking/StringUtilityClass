// StringUtilityClass.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstring>
#include "String.h" // my header file

using namespace std;


int main()
{
    // ----- 1 -----
    // constructor with NO ARGUMENTS
    // class nameOfInstance;
    String string1;
    
    // ----- 2 -----
    // covert a "string" to char array for input as variable(temp)
    char temp[] = "written through char[]";
    String string2a(temp);
    cout << temp << endl;
        // ALTERNATE WAY
    String string2b("written through overloaded");
    

    // ----- 3 -----
    String string3(string2b);
    cout << string3.CStr() << endl;

    // ----- 4 -----
    // doesn't include 'SPACE' as a character
    size_t index = 9;
    String string4aNonConst = "4.written Non Const";

    char& character = string4aNonConst.CharacterAt(index);
    cout << "Character " << character << " is at position " << index << " of the string: " << string4aNonConst.CStr() << endl;

        // ALTERNATE WAY (const version)
    const String constString("4.written as Const");
    const char& character1 = constString.CharacterAt(index);
    cout << "Character " << character1 << " is at position " << index << " of the string: " << constString.CStr() << endl;
    
    // ----- 5 -----
    String stringL = "Hello";
    size_t StrLength = stringL.Length();
    cout << "The length of " << stringL.CStr() << " is: " << StrLength << endl;

    // ----- 6 -----
    String compare1 = "Hello there!";
    String compare2 = "Hello there!"; //change one of these strings to change outcome
    
    if (compare1.EqualTo(compare2) == 1)
        cout << "The strings are the same" << endl;
    else cout << "The strings are NOT the same" << endl;


    // ----- 7 -----


    String str1("Hello ");
    String str2("World");
    cout << "Source string: " << str1.CStr() << endl;
    cout << "String to append: " << str2.CStr() << endl;
    str1.Append(str2).Append("!");
    cout << str1.CStr() << endl;

    String ogVar = "world";
    String PrependVar = ("Hello ");
    cout << "Source string: " << ogVar.CStr() << endl;
    cout << "String to Prepend: " << PrependVar.CStr() << endl;
    ogVar.Prepend(PrependVar);
    cout << ogVar.CStr() << endl;


    // ----- 8 -----
    // this allows you to use the 'cout <<' on your string (as per below)
    String str3("can 'cout << string.CStr()' to console now!");
    cout << str3.CStr() << endl;

    // cout << str3 << endl; // <------This is a problem without it. Value is a char** (pointer to a pointer) not char* (just a pointer)


    // ----- 9 -----

    String str4 = "TO LOWER CASE\n";
    str4.ToLower();
    cout << str4.CStr();


    // ----- 10 -----
    String str5 = "to uppercase\n";
    str5.ToUpper();
    cout << str5.CStr();

    

    // ----- 11 -----

    String str11("Hello, world");
    cout << "Total string: " << str11.CStr() << "\n";
    
    String substr11("world");

    //call function to search for substr
    size_t pos = str11.Find(substr11);
    if (pos != std::string::npos)
    {
        cout << "Substring found at position: " << pos << endl;
    }
    else
    {
        cout << "Substring not found." << endl;
    }

    cout << "Yo momma \n";


    //  // Create an instance of the String class
    //String str("Hello, world!");

    //// Call the Find method to search for a substring and capture the result
    //size_t index = str.Find("world");

    //// Check if the substring was found
    //if (index != static_cast<size_t>(-1)) 
    //{
    //    std::cout << "Substring found at index: " << index << std::endl;
    //}
    //else 
    //{
    //    std::cout << "Substring not found." << std::endl;
    //}
    return 0;
}