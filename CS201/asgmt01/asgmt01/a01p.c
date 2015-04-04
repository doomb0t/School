// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextHexInt()
//      * printNumberData()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>

static char *studentName = "I. Forgot";

// report whether machine is big or small endian
void bigOrSmallEndian()
{
}

// get next int (entered in hex) using scanf()
// returns 1 (success) or 0 (failure)
// if call succeeded, return int value via i pointer
int getNextHexInt(unsigned int *i)
{
	// replace this code with the call to scanf()
	*i = 0;
	return 1;
}

// print requested data for the given number
void printNumberData(int i)
{
}

// do not change this function in any way
int main(int argc, char **argv)
{
	unsigned int	i;					// number currently being analyzed
	int				nValues;			// number of values successfully parsed by scanf

	printf("CS201 - A01p - %s\n\n", studentName);
	bigOrSmallEndian();
	for (;;) {
	if (argc == 1)						// allow grading script to control ...
		printf("> ");					// ... whether prompt character is printed
	nValues = getNextHexInt(&i);
	printf("0x%08X\n", i);
	if (! nValues) {					// encountered bad input
		printf("bad input\n");
		while (getchar() != '\n') ;		// flush bad line from input buffer
		continue;
		}
	printNumberData(i);
	if (i == 0)
		break;
	}
	printf("\n");
	return 0;
}
