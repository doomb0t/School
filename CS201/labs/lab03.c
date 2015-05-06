/*
 * =====================================================================================
 *
 *       Filename:  lab03.c
 *
 *    Description:  Takes integer values and an operator, parses input performs operation
 *                  also check for bad or none existent input
 *
 *        Version:  1.0
 *        Created:  04/25/2015 09:30:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  PCC CS201
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc,char **argv)
{
    int arg1 = 0;
    int arg2 = 0;
    
    if(argc == 0)
    {
        printf("Not enough arguments please try again.");
        return -1;
    }
    for(int i = 0; i < argc; i++)
    {
        if(isdigit(argv[i]))
            arg1 = (int)argv[i]
    }
    return 0;
}
