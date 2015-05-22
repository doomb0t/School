// Characters from command line arguments are sent to child process
// from parent process one at a time through pipe.
//
// Child process counts number of characters sent through pipe.
//
// Child process returns number of characters counted to parent process.
//
// Parent process prints number of characters counted by child process.

#include <stdio.h>

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
