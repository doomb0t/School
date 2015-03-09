/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Induction THM chcker using GMP
 *
 *        Version:  1.0
 *        Created:  03/02/2015 01:13:33 AM
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
void thereom1(mpz_class m, mpz_class n);
void thereom2(mpz_class m, mpz_class n);
void thereom3(mpz_class n);
mpz_class divideMPZ(mpz_class temp,mpz_class  b);
mpz_class choose(mpz_class temp, mpz_class b);
using namespace std;
int main()
{
    mpz_class limit, m, n;
    string inLimit, inN;

    cout << "Please enter limit\n";
    getline(cin, inLimit);
    cout << "Please enter n\n";
    getline(cin, inN);
    
    limit = inLimit.c_str();
    n = inN.c_str();
    thereom1(limit, n);
    thereom2(limit, n);
    thereom3(n);
    return 0;
}

void thereom1(mpz_class limit, mpz_class n)
{
    mpz_class m;
    for (mpz_class i = -10; i <= 10; i++)
    {
        m = limit + 2*i;

        for (mpz_class k = 0; k < m; k++)
        {
            if (m % 2 != 0 && (n + k)%m != 0)
            {
                cout << "Thereom 1: Counter example found at k = " << k << "and n = " << n << endl;
                return;
            }
        }
    }
    cout << "Thereom 1: No counter example foud\n";
    return;
}


void thereom2(mpz_class limit, mpz_class n)
{
    mpz_class m;
      for (mpz_class i = -10; i <= 10; i++)
    {
        m = limit + 2*i;

        for (mpz_class k = 0; k < m; k++)
        {
            if (m % 2 == 0 && (n + k)%m != 0)
            {
                cout << "Thereom 2: Counter example found at k = " << k << "and n = " << n << endl;
                return;
            }
        }
    }
    cout << "Thereom 2: No counter example foud\n";
    return;
}
void thereom3(mpz_class n)
{
    mpz_class biNomTop, biNomBottom, biNomResult,temp,cat;
    biNomTop = 2*n+2;
    biNomBottom = n+1;
    biNomResult = 1;
    if(biNomBottom > biNomTop - biNomBottom)
        biNomBottom = biNomTop - biNomBottom;

    for (mpz_class i = 0; i < biNomBottom; i++)
    {
        biNomResult = biNomResult * (n-i);
        cout << biNomResult << "\n";
        biNomResult = divideMPZ(i+1, biNomResult);
        cout << biNomResult << "\n";
    }

    cout << biNomResult << "\n";
    
    
     cat = biNomResult;
     cat = divideMPZ(4*n+2,cat);
     cout << "Thm3: " << cat << "\n";
    
}

mpz_class divideMPZ(mpz_class temp,mpz_class  b)
{
    mpz_class q = 0;
    while (temp >= b)
    {
        temp = temp - b;
        q++;
    }
    return q;
}
