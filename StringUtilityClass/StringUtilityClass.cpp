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
        // ALTERNATE WAY
    String string2b("written through overloaded");

    // ----- 3 -----
    String string3(string2b);

    // ----- 4 -----
    // doesn't include 'SPACE' as a character
    size_t index = 9;
    String string4aNonConst = "4. written Non Const";

    char& character = string4aNonConst.CharacterAt(index);
        // ALTERNATE WAY (const version)
    const String constString("4. written as Const");
    const char& character1 = constString.CharacterAt(index);
    
    // ----- 5 -----
    String stringL = "Henlo";
    size_t StrLength = stringL.Length();

    // ----- 6 -----
    String compare1 = "Hello there!";
    String compare2 = "Hello there!"; //change one of these strings to change outcome
    
    compare1.EqualTo(compare2);

    // ----- 7 -----

    String str1("Hello ");
    String str2("World");
    str1.Append(str2).Append("!");

    String ogVar = "world";
    String PrependVar = ("Hello ");
    ogVar.Prepend(PrependVar);


    // ----- 8 -----
    // this allows you to use the 'cout <<' on your string (as per below)
    String str3("Hello ");
    cout << str3.CStr() << endl;

    // cout << str3 << endl; // <----------This is a problem without it. Value is a char** (pointer to a pointer) not char* (just a pointer)


    // ----- 9 -----

    String str4 = "HELLO\n";
    str4.ToLower();
    cout << str4.CStr();


    // ----- 10 -----

    str4.ToUpper();
    cout << str4.CStr();

    return 0;

    // ----- 11 -----

    String stringFind("Hello, world");
    cout << "Total string: " << stringFind.CStr() << "\n";
    
    size_t indexString = stringFind.Find("w");
    cout << "Index of string to find is at index: " << indexString << "\n\n\n\n";


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

}