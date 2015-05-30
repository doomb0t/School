/*
 * =====================================================================================
 *
 *       Filename:  a03.c
 *
 *    Description:  reads argv char one at a time from child to parent
 *                  outputs how many char's  the proc counts through pipe
 *
 *        Version:  1.0
 *        Created:  05/29/2015 01:42:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathon Sonesen
 *         Source:  starter code by Michael Trigiboff PhD.
 *   Organization:  PCC CS201 Computer Systems
 *
 * =====================================================================================
 */

// Characters from command line arguments are sent to child process
// from parent process one at a time through pipe.
//
// Child process counts number of characters sent through pipe.
//
// Child process returns number of characters counted to parent process.
//
// Parent process prints number of characters counted by child process.

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*ERROR HANDLING*/
#define READ_ERR        -2
#define WRITE_ERR       -3
#define PROTOCOL_ERR    -1

/*PROTOCOL CMD DEF*/
#define OPEN_CMD        -12
#define ACK_CMD         -10
#define CLOSE_CMD       -13

static int fd_in, fd_out;
static int to_child[2];
static int from_child[2];

char read_pipe ()
{
    char c;

    if(read(fd_in, &c, 1) == 1) {
        return c;
        }
    else {
        printf("read_pipe: read err\n");
        exit(WRITE_ERR);
        }
}

void write_pipe (char c)
{
    if(write(fd_out, &c, 1) != 1) {
            printf("write_pipe: err\n");
            exit(WRITE_ERR);
            }   
}

void get_cmd (char cmd)
{
    char c = read_pipe();

    if(c == cmd)
        write_pipe(ACK_CMD);
    else {
        printf("get_cmd: protocol err\n");
        exit(PROTOCOL_ERR);
        }
}

void send_cmd (char cmd)
{
    char c;
    write_pipe(cmd);
    if((c =  read_pipe()) != ACK_CMD) {
        printf("send_cmd: protocol err, read '%d' 0x%X\n", c, c & 0xFF);
        exit(PROTOCOL_ERR);
        }
}

char get_data (char cmd)
{
    char c = read_pipe();
    write_pipe(ACK_CMD);
    return c;
}

void send_data (char cmd)
{
    char c;
    write_pipe(cmd);
    if((c = read_pipe()) != ACK_CMD) {
        printf("send_data: err\n");
        exit(PROTOCOL_ERR);
        }
    printf("parents: '%c' acknowledged\n", c);
}
int main(int argc, char **argv)
{
    pid_t pid;
    char c;
    int i;
	
    // set up pipe to child
    if(pipe(to_child)) {
        printf("pipe: to child: err\n");
        return -1;
        }  

    //pipe from child
    if(pipe(from_child)) {
        printf("pipe from child err\n");
        return -1;
        }
        
    // create parent and child 
    pid = fork();
        
    //error handling
    if(pid < 0) {
        printf("fork err%d\n", pid);
        }
    // -- running in child process --
    else if (pid == 0) {
	int     nChars = 0;
        close(from_child[0]);
        fd_out = from_child[1];
        fd_in = to_child[0];
        close(to_child[1]);
                        
        while(read_pipe() != '\0' && read_pipe() != '\n')
            nChars++;
        return nChars;
	// Receive characters from parent process via pipe
	// one at a time, and count them.
            
	// Return number of characters counted to parent process.
	return nChars;
	}
    else {
	// -- running in parent process --
	int     nChars = 0;

	printf("CS201 - Assignment 3 - Jonathon Sonesen\n");

	printf("child counted %d characters\n", nChars);
	return 0;
	} 
}
