/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Set Theory Application to identify subset of two data sets
 *
 *        Version:  1.0
 *        Created:  03/19/2015 10:27:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS250
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int ARRAY_MAX = 8192;
void checkFloat(float const float_Set_A[], float const float_Set_B[], int m, int n);
void checkChar(char const char_Set_A[], char const char_Set_B[], int m, int n);
void checkInt(int const int_Set_A[], int const int_Set_B[], int m, int n);
void checkString(string const string_Set_A[], string const string_Set_B[],int m,int n);

int main()
{   
    char char_Set_A[ARRAY_MAX];
    char char_Set_B[ARRAY_MAX];
    
    string string_Set_A[ARRAY_MAX];
    string string_Set_B[ARRAY_MAX];
    string data_Type;

    int int_Set_A[ARRAY_MAX];
    int int_Set_B[ARRAY_MAX];
    int m = 0;
    int n = 0;
 
    float float_Set_A[ARRAY_MAX];
    float float_Set_B[ARRAY_MAX];
    
    cout << "Enter m ( 1 <= m <= 8192): ";
    cin >> m;
    cout << endl;

    cout << "Enter n ( 1 <= n <= 8192):";
    cin >> n;
    cout << endl;

    cout << "Enter data type (char string float int): ";
    cin >> data_Type;
    cout << endl;

    cout << "Please enter m elements of set A: ";
    for (int i = 0; i < m; i++)
    {
        if (data_Type == "char")
        {   
            cin >> char_Set_A[i];
            cin.ignore(100, '\n');
        }
        if (data_Type == "string") 
        {   
            cin.ignore(100,'"');
            getline(cin, string_Set_A[i],'"');
        }

        if (data_Type == "int") 
        {
            cin >> int_Set_A[i];
            cin.ignore(100,'\n');
        }
     
        if (data_Type == "float") 
        {  
            cin >> float_Set_A[i];
            cin.ignore(100, '\n');
        }
    }
    cout << "Please enter n elements of set B: ";
    for (int i = 0; i < n; i++)
    {
        if (data_Type == "char")
        {   
            cin >> char_Set_B[i];
            cin.ignore(100, '\n');
        }

        if (data_Type == "string")
        {
            
            cin.ignore(100, '"');
            getline(cin, string_Set_B[i], '"');
        }
        if (data_Type == "int") 
        {
            cin >> int_Set_B[i];
            cin.ignore(100, '\n');
            
        }
        if (data_Type == "float") 
        {   cin >> float_Set_B[i];
            cin.ignore(100, '\n');
        }
    }

    if (data_Type == "char")
        checkChar(char_Set_A, char_Set_B, m, n);
    
    if (data_Type == "string")
        checkString(string_Set_A, string_Set_B, m, n);
    
    if (data_Type == "float")
        checkFloat(float_Set_A, float_Set_B,m, n);
    
    if (data_Type == "int")
        checkInt(int_Set_A, int_Set_B, m, n);
    
    return 0;
}

void checkFloat(float const float_Set_A[], float const float_Set_B[], int m, int n)
{   
    bool found;

    for (int i = 0; i < m; i++)
    {
        found = false;
        for (int j = 0; j < n; j++)
        {
            if(float_Set_A[i] == float_Set_B[j])
            {
                found = true;
            }
        
        }
        if (found == false)
        {    
            cout << "A is not a subset of B\n";
            return;
        }

    }
    cout << "A is a subset of B\n";
    return;
}

void checkChar(char const char_Set_A[], char const char_Set_B[], int m, int n)
{ 
    bool found;
    for (int i = 0; i < m; i++)
    {
        found = false;
        for (int j = 0; j < n; j++)
        {       
            if(char_Set_A[i] == char_Set_B[j])
            {
                found = true;
            }
        }
        if (found == false)
        {    
            cout << "A is not a subset of B\n";
            return;
        }
        
    }
    cout << "A is a subset of B\n";
    return;
}

void checkInt(int const int_Set_A[], int const int_Set_B[], int m, int n)
{
    bool found;
    for (int i = 0; i < m; i++)
    {
        found = false;
        for (int j = 0; j < n; j++)
        {  
            if(int_Set_A[i] == int_Set_B[j])
            {
                found = true;
            }
        }

        if (found == false)
        {    
            cout << "A is not a subset of B\n";
            return;
        }
    }
    cout << "A is a Subset of B\n";
    return;
}

void checkString(string const string_Set_A[], string const string_Set_B[], int m, int n)
{
    bool found;
    for (int i = 0; i < m; i++)
    {
        found = false;
        for (int k = 0; k < n; k++)
        {  
            if(string_Set_A[i].compare(string_Set_B[k].c_str()) == 0)
            {
                found = true;
            }
        
        }
        if (found == false)
        {    
            cout << "A is not a subset of B\n";
            return;
        }
    }
    cout << "A is a subset of B\n";
    return;
}
