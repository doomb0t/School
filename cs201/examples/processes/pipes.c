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
    else {
        printd("readPipe: read err\n");
        exit(READ_ERR);
        }
}

void writePipe (char ch)
{
    if(write(out, &ch, 1) != 1)
        writePipe(out, &ch, 1)
    else {
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
        exit(PROTOCL_ERR);
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

int main (int argc. char **argv)
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
        printf("child: received nChars = %d\n");
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
    else {
        
        } 
}
