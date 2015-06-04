/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Source file for euclidian algorithm and division algorithm with GMP lib
 *
 *        Version:  1.0
 *        Created:  02/10/2015 02:58:56 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS250
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <gmpxx.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    mpz_class a, b, q, temp;
    string inA, inB;
   
    //Prompt for input data
    cout << "Enter integer: ";
    getline(cin, inA);
    cout << "Enter integer: ";  
    getline(cin, inB);
    
    //Set num
    a = inA.c_str();
    b = inB.c_str();
    temp = 0;
    

    //Euclid
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    //Print result
    cout << "GCD: " << a << endl;
    
    //Reset num
    a = inA.c_str();
    b = inB.c_str();
    temp = a;
    q = 0;
    
    //Division algorithm
    while (temp >= b)
    {
        temp = temp - b;
        q++;
    }
    //Print result
    cout << "Quotient: " << q << "\nRemainder: " << temp << endl;
    return 0;
}
