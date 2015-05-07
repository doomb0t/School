/*
 * =====================================================================================
 *
 *       Filename:  lab03.c
 *
 *    Description:  Takes integer values and an operator, parses input performs operation
 *                  also check for bad or none existent input
 *
 *        Version:  1.0
 *        Created:  04/25/2015 09:30:35M
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

<<<<<<< HEAD
int isnum (char *test);
int opid(char *test);

int main(int argc, char **argv)
{
    char first[100] = {};
    int first  = 0;
    int secend = 0;
    int op     = 0
    for ( int i = 0; i < argc; i++ )
    {
        if (isnum(argv[i]) == 1)
            first[i] = *argv[i];
        else
        {
        }
    }
    return 0;
}

int isnum(char *test)
{
    if (*test < 46 || *test > 58)
        return 0;
    else
    return 1;
}

int opid(char *test)
{
    if ( *test == '+')
        return  1;
    
    if ( *test == '-')
        return 2;
    
    if ( *test == '*')
        return 3;
    
    if( *test == '/')
        return 4;
    
=======
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
>>>>>>> f14afd253896133bccaae72d4d2277902f96281a
    return 0;
}
