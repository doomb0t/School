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
#include <string.h>
void eatline()
{
    while(getchar() != '\n');
}

int main ()
{
    double firstNum, scndNum, sum;
    int nparsed;
    char c;   
    //read and check input
    printf("First number:\0 ");
    nparsed = scanf("%lf%c\0", &firstNum, &c);
    
    while (nparsed != 1)
    {
        printf("--bad input--\nFirst Number: ");
        nparsed = scanf("%lf%c\0", &firstNum, &c);
        eatline();
    }

    printf("Second number: \0");
    nparsed = scanf("%lf%c\0", &scndNum, &c);
    
    while (nparsed != 1)
    {   
        printf("--bad input--\nSecond Number: ");
        nparsed = scanf("%lf%c\0", &scndNum, &c);
        eatline();
    }


    sum = firstNum + scndNum;
    printf("%11.2f\n", firstNum);
    printf("+%10.2f\n", scndNum);
    printf("-----------\n");
    printf("%11.2f\n", sum);

    return 0;
}

