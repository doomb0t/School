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

int isnum (char *test);
int opid(char *test);


int isnum(char *test)
{
    if (*test < 46 || *test > 58)
        return 0;
    else
    return 1;
}
int opid(char *test) { if ( *test == '+')
{
    if (*test == '+')
        return  1;
    
    if ( *test == '-')
        return 2;
    
    if ( *test == '*')
        return 3;
    
    if( *test == '/')
        return 4;
}    
int main(int argc,char **argv)
{
    int arg1 = 0;
    int arg2 = 0;
    
    if(argc == 0)
    {
        printf("Not enough arguments please try again.");
        return -1;
    }

    if(isnum(argv[0]))
        sscanf(argv[0],"%d", &arg1);
    
    if(isnum(argv[2]))
        sscanf(argv[0],"%d", &arg2);
    return 0;
    switch opid(argv[1])
    {
        case 1:
            printf("%d\n",arg1 + arg2);
            break;
        case 2:
            printf("%d\n",arg1 - arg2);
            break;
        case 3:
            printf("%d\n",arg1 * arg2);
            break;
        case 2:
            printf("%d\n",arg1 / arg2);
            break;
   }
    return 0;
}
