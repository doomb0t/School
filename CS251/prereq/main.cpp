/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: Prints the summation as required of prereq assignment 
 *
 *        Version:  1.0
 *        Created:  03/31/2015 01:58:33 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS251
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <gmpxx.h>
#include <iostream>
using namespace std;
int main()
{
    mpz_class sum, n;
    string userIn;

    cout << "Please enter the upper limit n: ";
    getline(cin, userIn);
    n = userIn.c_str();

    for (mpz_class i = 0; i < n; i++)
        sum += i;
    cout << sum << endl;
    return 0;
}
