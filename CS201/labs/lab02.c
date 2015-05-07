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
    char c;
    double firstNum, scndNum, sum;
    
    //read and check input
    printf("First number: ");
    scanf("%lf%c", &firstNum, &c); 

    while(c != '\n')
    {
        eatline();
        printf("-- bad input --\n");
        printf("First number: ");
        scanf("%lf%c", &firstNum, &c);
    }
    c = '\0'; 
    printf("Second number: ");
    scanf("%lf%c", &scndNum, &c);

    while(c != '\n')
    {
        eatline();
        printf("--bad input--\n");
        printf("Second number: ");
        scanf("%lf%c", &scndNum, &c);
    }


    sum = firstNum + scndNum;
    printf("%11.2f\n", firstNum);
    printf("+%10.2f\n", scndNum);
    printf("-----------\n");
    printf("%11.2f\n", sum);

    return 0;
}

