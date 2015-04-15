/*
 * =====================================================================================
 *
 *       Filename:  lab02.c
 *
 *    Description:  Lab 02
 *
 *        Version:  1.0
 *        Created:  04/07/15 12:17:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen   
 *   Organization:  CS201
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

void eatline()
{
    while(getchar() != '\n');
}

int main ()
{
    double firstNum, scndNum, sum;
    int nparsed;
    
    //read and check input
    printf("First number: ");
    nparsed = scanf("%lf\0", &firstNum);
    while(nparsed !=1)
    {
        eatline();
        printf("-- bad input --\n");
        printf("First number: ");
        nparsed = scanf("%lf\0", &firstNum);
    }
    
    printf("Second number: \0");
    nparsed = scanf("%lf\0", &scndNum);
    while(nparsed !=1)
    {
        eatline();
        printf("--bad input--\n");
        nparsed = scanf("%lf\0", &firstNum);
        printf("First number: ");
        
    }

    sum = firstNum + scndNum;
    printf("%11.2f\n", firstNum);
    printf("+%10.2f\n", scndNum);
    printf("-----------\n");
    printf("%11.2f\n", sum);

    return 0;
    

}

