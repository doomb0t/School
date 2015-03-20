/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Induction THM chcker using GMP
 *
 *        Version:  1.0
 *        Created:  03/02/2015 01:13:33 AM
 *       Revision:  1
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

using namespace std;

void theorem1_2(mpz_class m, mpz_class n);

mpz_class theorem3Control(mpz_class n);
mpz_class theorem3ToCheck(mpz_class n);
mpz_class factorial(mpz_class n, mpz_class k);

int main()
{
    mpz_class limit, m, n, th3Known,th3Check;
    string inLimit, inN;
    
    //prompt and receive input
    cout << "Please enter limit\n";
    getline(cin, inLimit);
    cout << "Please enter n\n";
    getline(cin, inN);
    
    //assign large ints
    limit = inLimit.c_str();
    n = inN.c_str();
    theorem1_2(limit, n);

    for(mpz_class i = 0; i < n; i++)
    {   
        //assign control variables
        th3Known = theorem3Control(i);
        th3Check = theorem3ToCheck(i);

        //compare
        if(th3Check != th3Known)
        {    
            cout << "Theorem 3 misses an element of the catalan i = " << th3Check << ".\n";
            cout << "The correct value is " << th3Known << ".\n";
        }   
    }        
    cout << "Theorem 3: Valid\n";
    return 0;

}

void theorem1_2(mpz_class limit, mpz_class n)
{
    mpz_class k,m,sum,temp;
    bool found = false;
    bool hypothesis = false;
    for (mpz_class i = -10; i <= 10; i++)
    {
        m = limit + 2*i;
        sum = 0; 
        //Display hypothesis status
        if (hypothesis == false && m % 2 == 0)
        {
            cout << "** Since m is even the hypothesis for theorem 1 is not true**\n";
            hypothesis = true;
        }else if (hypothesis == false && m %2 != 0)
        {
            cout << "** Since m is odd the hypothesis for theorem 2 is not true**\n";
            hypothesis = true;
        }
        //summation
        for (k = 0; k < m; k++) 
        {
            sum = sum + (n + k);
        }
                 
        temp = sum % m;
        if (temp != 0 && found == false)
        {   
            cout << "Theorem 1: Counter example found at sum = " << sum;
            cout << " and m = " << m << " with a remainder of" << temp << endl;
            cout << "Theorem 2: Counter example found at sum = " << sum;
            cout << " and m = " << m << " with a remainder of" << temp << endl;
            found = true;
        }
    }

    if(found == false)
    {
        cout << "Theorem 1: No counter example found \n";
        cout << "Theorem 2: No counter example found \n";
    }
    return;
}



//Evaluate known
mpz_class theorem3Control(mpz_class n)
{
    mpz_class  c = factorial(2*n, n);   
    c = c / (n + 1);
    return  c;
}
//Evaluate unknown 
mpz_class theorem3ToCheck(mpz_class n)
{
    mpz_class  c = factorial(2*n+2, n+1);
    c = c / (4*n + 2);
    return c;
}

//function to evaluate binomial coefficient
mpz_class factorial(mpz_class n, mpz_class k)
{
    mpz_class result = 1;                            
    
    if ( k > n)
        return 0;
    if (k * 2 > n)
        k = n - k;
    if(k == 0)
        return 1;
    for (mpz_class i = 0; i < k; ++i)     
    {
        result = result * (n - i);   
        result = result / (i +1);
    } 
    return result;          
}
