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

int isnum(char *test)
{
    if(test[1] != '\0') return 0;
    
    if (*test < 46 && *test > 58) return 0;
    else
    return 1;
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
    int test = 1;
    if (isnum(argv[1]) == 1)
        sscanf(argv[1],"%d", &arg1);
    else
        test = 0;
    
    if (isnum(argv[3]) == 1)
        sscanf(argv[3],"%d", &arg2);
    else
        test = 0;
    
    if (test != 1 )
    {
        exception();
        return -1;
    }
   
    op(argv[2], arg1, arg2);
    
    return 0;
}
