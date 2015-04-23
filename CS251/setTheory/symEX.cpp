/*
 * =====================================================================================
 *
 *       Filename:  symEX.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/15 14:37:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h> //set_symmetric_difference example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_symmetric_difference, std::sort
#include <vector>       // std::vector
#include <gmpxx.h>
using namespace std;
int main () 
{   
    mpz_class factorial = 0;
    mpz_class sum = 2;
    mpz_class first[18];
    mpz_class second[20];
    vector<int> v(20);                      // 0  0  0  0  0  0  0  0  0  0
    vector<int>::iterator it;
    
    for(int i = 0; i < 20; i++)
    {
        if (i < 2)
        {
            first[i]  = 1;
            second[i] = 1;
            factorial = 1;
        }else if( i > 2)
        factorial += factorial * (i - 1);

        if (i < 18)
            first[i] = factorial;
        else if( i >= 18)
            first[i] = '\0';
        second[i] = factorial;
        cout << first[i] << " " << second[i] << endl;
    }
    it=set_symmetric_difference (first, first+18, second, second+20, v.begin()); //  5 15 25 30 40 50  0  0  0  0
    v.resize(it-v.begin());                      //  5 15 25 30 40 50
    cout << "The symmetric difference has " << (v.size()) << " elements:\n";
    for (it=v.begin(); it!=v.end(); ++it)
        cout << ' ' << *it;
      cout << '\n';
    return 0;                                                                           
}
