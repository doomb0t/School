/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Function Module Application
 *
 *        Version:  1.0
 *        Created:  04/22/15 16:38:50
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS251
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <vector>
#include <cmath>
#include <iterator>
#include <gmpxx.h>

using namespace std;
void splitLine(vector <string> &words, string currentLine, mpz_class limit);
void injectiveCheck(vector <string> &oneToOne, string *set1, string *set2, int base, const mpz_class n1, const mpz_class n2);
void swap(string *a, string *b);
void printVector(vector <string> inComing);
mpz_class calcElem(mpz_class n1, mpz_class n2);
mpz_class elementCount(string currentLine);

int main()
{
    //init variables
    mpz_class nSet1  = 0;
    mpz_class nSet2  = 0;
    mpz_class nTest1 = 0;
    mpz_class nTest2 = 0;
    //input
    string s_setA, s_setB;
    vector <string> lineArray, v_setA, v_setB, V_Injective;

    cout << "Enter number of elemets in sets (seperated by spaces : ";
    cin >> nSet1 >> nSet2;
    cin.ignore(100, '\n');
    
    cout << "Enter set A (elements seperated by a space: ";
    getline(cin, s_setA);
    
    cout << "Enter set B (elements seperated by a space: ";
    getline(cin, s_setB);

    if (elementCount(s_setA) >= nSet1 && elementCount(s_setB) >= nSet2)
    {
        splitLine(v_setA, s_setA, nSet1);
        splitLine(v_setB, s_setB, nSet2);
        string* p_setA = &v_setA[0];
        string* p_setB = &v_setB[0];

    }
}

