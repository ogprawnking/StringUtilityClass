// StringUtilityClass.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstring>
#include "String.h" // my header file



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
    // second way of using param./overloade. constructor
    String string2b("written through overloaded");


    String string3(string2b);
}