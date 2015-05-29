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
 *       Compiler:  gcc -std=gnu99
 *
 *         Author:  Jonathon Sonesen
 *         Source:  Michael Trigiboff PhD.
 *   Organization:  CS201 PCC Computer Systems
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*ERROR HANDLING*/
#define READ_ERR        -2
#define WRITE_ERR       -3
#define PROTOCOL_ERR    -1

/*PROTOCOL CMD DEF*/
#define OPEN_CMD        -12
#define ACK_CMD         -10
#define CLOSE_CMD       -13

static int toChild[2];    
static int fromChild[2];  

static int in, out;

char readPipe ()
{
    char ch;
    
    if(read(in, &ch, 1) == 1)
        return ch;
    else {
        printf("readPipe: read err\n");
        exit(READ_ERR);
        }
}

void writePipe (char ch)
{
    if(write(out, &ch, 1) != 1) {
        printf("writePipe: err\n");
        exit(WRITE_ERR);
        }
}

void getCmd (char cmd)
{
    char ch = readPipe();

    if(ch == cmd) 
        writePipe(ACK_CMD);
    else {
        printf ("getCmd: protocol err\n");
        exit(PROTOCOL_ERR);
        }
}

void sendCmd (char cmd)
{
    char ch;
    writePipe(cmd);
    if((ch = readPipe()) != ACK_CMD) {
        printf("sendCmd: protocol err, read '%d' 0x%X\n", ch, ch & 0xFF);
        exit(PROTOCOL_ERR);
        }
}

char getData ()
{
    char ch = readPipe();
    writePipe(ACK_CMD);
    return ch;
}

void sendData (char ch)
{
    char c;
    
    writePipe(ch);
    if ((c = readPipe()) != ACK_CMD) {
        printf("sendCmd: protocol err, read '%d' 0x%X\n", ch, ch & 0xFF);
        exit(PROTOCOL_ERR);
        }
    printf("parents: '%c' acknowledged\n", ch);
}

int main (int argc, char **argv)
{
    int         status;
    pid_t       pid;
    char        ch;
    int         nChars;
    int         i;

    /* set up pipe to child */
    if (pipe(toChild)) {
        printf("pipe to child: err\n");
        return -1;
        }
    /* set up pipe from child */
    if (pipe(fromChild)) {
        printf( "pipe from child: err\n");
        return -1;
        }
    
    /* create parent and child process */
    pid = fork();

    /* fork() fails */
    if (pid <0){
        printf("fork err %d/n", pid);
        return -1;
        }
    else if (pid == 0) {
        
        /*setup pipes for child proc*/
        close(fromChild[0]);
        out = fromChild[1];
        in  = toChild[0];
        close(toChild[1]);

        /*do childish things*/
        printf("child: waiting for OPEN\n");
        getCmd(OPEN_CMD);
        printf("child: received OPEN\n");
        nChars = getData();
        printf("child: received nChars = %d\n", nChars);
        for (i = 0; i < nChars; i++) {
            ch = getData();
            printf("child: received '%c'\n", ch);
            sleep(1); //1 second
            }
        getCmd(CLOSE_CMD);
        close(in);
        close(out);
        printf("child: exits\n");
        return 210;
        }
    /* this runs the parent process */
    else {
       
        /* if prog runs with arg initialize proc with char */
        ch      = argc > 1 ? argv[1][0] : 'a';

        /* if argv[2] is present set number of characters to send */
        nChars  = argc > 2 ? atoi(argv[2]) : 3;
        
        /* setup  pipes for parent proc */
        close(toChild[0]);
        out = toChild[1];
        in = fromChild[0];
        close(fromChild[1]);

        /* do parental things */
        printf( "parent: send OPEN\n");
        sendCmd(OPEN_CMD);
        printf("parent: send nChars = %d\n", nChars);
        sendData(nChars);
        for ( i = 0; i < nChars; i++) {
            printf("parent: send '%c'\n", ch);
            sendData(ch++);
            }
        printf("parent: send CLOSE\n");
        sendCmd(CLOSE_CMD);
        waitpid(pid, &status, 0);
        printf("parent: reaps child status 0x%08X/n", status);
        if (WIFEXITED(status))
            printf("parent: child exited normally with %d\n", WEXITSTATUS(status));
        close(in);
        close(out);
        printf("parent: exits\n");
        return 0;
        }
        
}
