/*
 * =====================================================================================
 *
 *       Filename:  pipes.c
 *
 *    Description:  implements a tiny communications "protocol" using a pipe
 *
 *        Version:  1.0
 *        Created:  05/22/2015 09:35:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *   Organization:  CS201 PCC Computer Systems
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*ERROR HANDLING*/
#define READ_ERR        -12
#define WRITE_ERR       -13
#define ACK_CMD         -10 

static int toChild[2];    
static int fromChild[2];  

char readPipe ()
{
    char ch;
    
    if(read(in, &ch, 1) == 1)
        return ch;
    else 
    {
        printd("readPipe: read err\n");
        exit(READ_ERR);
    }
}

void writePipe (char ch)
{
    if(write(out, &ch, 1) != 1)
        writePipe(out, &ch, 1)
    else
    {
        printf("writePipe: err\n");
        exit(WRITE_ERR);
    }
}

void getCmd (char cmd)
{
    char ch = readPipe();

    if(ch == cmd)
        writePipe(ACK_CMD);
    else
    {
        printf ("getCmd: protocol err\n");
        exit(PROTOCOL_ERR);
    }
}

