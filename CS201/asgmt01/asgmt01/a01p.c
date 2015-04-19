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
    unsigned int checkEnd = 1;
    char *endChar         = ( char*) & checkEnd;

    if(*endChar == 1)
        printf("byte order: little-endian\n\n");
    else
        printf("byte order: big-endian \n\n");
}

// get next int (entered in hex) using scanf()
// returns 1 (success) or 0 (failure)
// if call succeeded, return int value via i pointer
int getNextHexInt(unsigned int *i)
{
    int ret = 0;
    if(scanf("%x", i) == 1)
        ret = 1;
    else 
        ret = 0;

    return ret;
}

// print requested data for the given number
void printNumberData(int i)
{
    //check the sign bit
    int signBit = 0;
    if((i & 0x80000000) == 0x80000000)
    {
        printf("signBit 1, "); //neg
        signBit = 1;
    }
    else
    {
        printf("signBit 0, "); //pos
        signBit = 0;
    }

    //bit control flow var
    int expBits  = 0;
    int fracBits = 0;
    int norm     = 1;

    //mask exp and frac bits
    expBits  = i & 0x7F800000; //mask sign and frac
    expBits  = expBits >> 23; //shift bits to right
    fracBits = i & 0x007FFFFF; //mask frac
    fracBits = i & 0x007FFFFF; //mask frac

    //output info
    printf("expBits %3d, fractBits 0x%08X\n", expBits, fracBits);
    
    //check norm
    if(expBits == 0)
    {
        if(fracBits != 0)
        {
            norm = 0;
            printf("denormalized: exp = %d", (expBits - 126));
        }
        else
        {
            norm = 0;
            if(signBit == 0)
            {
                printf("+zero");
            }
            else
            {
                printf("-zero");
            }
        }

    }
    else
    {
        if (expBits == 0xff)
        {
            if(fracBits == 0)
            {
                printf("+/- Infinity");
            }
            else
            {
                printf("%cNan\n\n", fracBits < 0x400000 ? 'S' : 'Q');
            }
        }

        if(expBits != 0 && expBits != 0xff)
        {
            norm = 1;
            printf("normalize: exp = %d", (expBits - 127));
        }
    }
    printf("\n\n");


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
