/*
 * =====================================================================================
 *
 *       Filename:  lab04.c
 *
 *    Description:  A program that reads in hex integer value and masks bits 4-3
 *                  then shifts them to the right to use them as numbers
 *                  then the program prints their sum
 *
 *        Version:  1.0
 *        Created:  05/16/15 23:22:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS201 Computer Systems
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>


int main (int argc, char **argv)
{
    int   hex = 0;
    int   sum = 0;
    char  trailing = '\0';
    sscanf(argv[1], "%x, %s\n", &hex, &trailing);
    char * p = (char *)&hex;
    
    for(int i = 0; i < 4; i++)
    {
        sum +=( p[i] & 0x18) >> 3;
    
    }
    
    printf("Sum: %d \n", sum);
    return 0;
}
