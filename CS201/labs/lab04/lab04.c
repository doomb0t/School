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
    int   hex1 = 0;
    int   hex2 = 0;
    char  trailing = '\0';
    
    sscanf(argv[1], "%x, %s\n", &hex1, &trailing);
    printf("You entered: %d, %d \n", hex1, hex2);

    hex2 = hex1 & 0x18 << 3;
    printf("%d\n", hex2);
    return 0;
}
