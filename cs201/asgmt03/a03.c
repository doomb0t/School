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

static int fd;

void read_from_pipe (char** in)
{
    char ch;
    if(read(fd, &in, 1) == 1)
        return;
    else {
        printf("readFromPipe: read err\n");
        }
}



int main(int argc, char **argv)
{
	// set up pipe


	// call fork()

	if (0 /* replace 0 with test for parent vs child, delete this comment */) {
		// -- running in child process --
		int     nChars = 0;

		// Receive characters from parent process via pipe
		// one at a time, and count them.

		// Return number of characters counted to parent process.
		return nChars;
		}
	else {
		// -- running in parent process --
		int     nChars = 0;

		printf("CS201 - Assignment 3 - I. Forgot\n");

		// Send characters from command line arguments starting with
		// argv[1] one at a time through pipe to child process.

		// Wait for child process to return. Reap child process.
		// Receive number of characters counted via the value
		// returned when the child process is reaped.

		printf("child counted %d characters\n", nChars);
		return 0;
		}
}
