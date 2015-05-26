/*
 * =====================================================================================
 *
 *       Filename:  symetDif.cpp
 *
 *    Description:  to check symmetric difference of a given set
 *
 *        Version:  1.0
 *        Created:  04/11/15 20:17:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <gmpxx.h>
#include <math.h>
using namespace std;
int main()
{
    mpz_class prod, sum, limit ,i;
    mpz_class setX[18], setY[20];
    setX[0] = '1';
    setY[0] = '1';
    
    setX[1] = 1;
    setY[1] = 1;
    for (int i = 2; i < 20; i++)
    {
         sum += i*(i -1);
        if(i <= 18)
            setX[i] = sum;
         setY[i] = sum;
    }

    for (int i = 0; i < 20; i++)
    {
        if(i <= 18)
            cout << setX[i] << " ";
        cout << "\n" << setY[i] << " ";
    }
    return 0;
}
