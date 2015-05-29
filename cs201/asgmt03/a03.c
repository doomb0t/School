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

static int fdIn, fdOut;
static int to_child[2];
static int from_child[2];

void read_from_pipe (char** in)
{
    char c;

    if(read(fdIn, &c, 1) == 1) {
        in = (char**)&c;
        }
    else {
        printf("read_from_pipe: read err\n");
        exit(WRITE_ERR);
        }
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
            fdOut = from_child[1];
            fdIn = to_child[0];
            close(to_child[1]);
            
            
	    // Receive characters from parent process via pipe
	    // one at a time, and count them.

	    // Return number of characters counted to parent process.
	    return nChars;
	    }
	else {
	    // -- running in parent process --
	    int     nChars = 0;

	    printf("CS201 - Assignment 3 - Jonathon Sonesen\n");

	    // Send characters from command line arguments starting with
	    // argv[1] one at a time through pipe to child process.

	    // Wait for child process to return. Reap child process.
	    // Receive number of characters counted via the value
	    // returned when the child process is reaped.

	    printf("child counted %d characters\n", nChars);
	    return 0;
	    }

        
}
