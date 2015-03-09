/*
 * =====================================================================================
 *
 *       Filename:  inputTools.cpp
 *
 *    Description:  Implementation file for input tools
 *
 *        Version:  1.0
 *        Created:  02/07/2015 01:27:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "UserInput.h"
#include <iostream>

using namespace std;

int getInt(const char prompt[])
{
    int value;

    //prompt
    cout << "\n" << prompt;
    cin >> value;

    //error handling for bad int
    while(!cin)
    {
        //restor stream
        cin.clear();
        cin.ignore(100, '\n');

        //prompt again
        cout << "Sorry! Invalid integer, please try again: ";
        cin >> value;

    }

    //toss the junk input
    cin.ignore(100, '\n');

    return value;
}

double getDouble(const char prompt[])
{
    double valDouble;

    //prompt
    cout << "\n" << prompt;
    cin >> valDouble;

    while(!cin)
    {
        //restore stream
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Sorry that is an invalid float please retry: ";
        cin >> valDouble;
    }

    return valDouble;
}

char getChar(const char prompt[])
{
    char inChar;
    cout << '\n' << prompt;
    cin >> inChar;
    inChar = tolower(inChar);
    cin.ignore(100, '\n');
    
    return inChar;
}

//this will reas a cstring ann discard the rest, max char is MAX
//_CHAR -1 the new line char will be disgarded
void getString(const char prompt[], char inStr[], int maxChar)
{
    //prompt and get line up to maxchar or newline
    cout << '\n' << prompt;
    cin.get(inStr,maxChar, '\n');

    while(!cin)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Oops! Invalid string please retry: ";
        cin.get(inStr,maxChar, '\n');
    }
    //toss newlinechar
    cin.ignore(100,'\n');
}
