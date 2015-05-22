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
int op(char *test, int arg1, int arg2);
void exception();

void exception()
{
    printf
    (
            "call as: lab03 <n1> <op> <n2>                    \n\n"

            "       <op>        arithmetic operations +, -, *, /\n"
            "       <n1>, <n2>  the two numbers                 \n"
    );
}


int op(char *test, int arg1, int arg2)
{

    if (test[1] != '\0') 
    {
        exception();
        return 0;
    }

    if (*test == 43)
    {
        printf("%d %s %d = %d \n", arg1, test, arg2, arg1 + arg2);
        return  arg1 + arg2;
    }    
    
    if ( *test == 45)
    { 
        printf("%d %s %d = %d \n", arg1, test, arg2, arg1 - arg2);
        return  arg1 - arg2;
    }
    if ( *test == 42)
    {
        printf("%d %s %d = %d \n", arg1, test, arg2, arg1 * arg2);
        return arg1 * arg2;
    }
    if ( *test == 47)
    {
        printf("%d %s %d = %d \n", arg1, test, arg2, arg1 / arg2);
        return arg1 * arg2;
    }
    return 0; 
}  

int main(int argc,char **argv)
{
    int arg1 = 0;
    int arg2 = 0;
    char trail[32] = {};
    if(argc < 4) 
    {
        exception();
        return -1;
    }
    sscanf(argv[1],"%d%s", &arg1, &trail[0]);
    
    sscanf(argv[3],"%d%s", &arg2, &trail[0]);
    
    if (trail[0] != '\0' )
    {
        exception();
        return -1;
    }
   
    op(argv[2], arg1, arg2);
    
    return 0;
}
