// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextFloat()
//      * printNumberData()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>

static char *studentName = "I. Forgot";

// report whether machine is big or small endian
void bigOrSmallEndian()
{
}

// get next float using scanf()
// returns 1 (success) or 0 (failure)
// if call succeeded, return float value via f pointer
int getNextFloat(float *f)
{
    // replace this code with the call to scanf()
    *f = 0.0;
    return 1;                               // in C, a zero value means false, anything else means true
}

// print requested data for the given number
void printNumberData(float f)
{
}

// do not change this function in any way
int main(int argc, char **argv)
{
    float   f;                              // number currently being analyzed
    int     nValues;                        // number of values successfully parsed by scanf

    printf("CS201 - A01 - %s\n\n", studentName);
    bigOrSmallEndian();
    for (;;) {
        if (argc == 1)                      // allow grading script to control ...
            printf("> ");                   // ... whether prompt character is printed
        nValues = getNextFloat(&f);
        if (! nValues) {                    // encountered bad input
            printf("bad input\n");
            while (getchar() != '\n') ;     // flush bad line from input buffer
            continue;
            }
        printNumberData(f);
        if (f == 0.0)
            break;
        }
    printf("\n");
    return 0;
}
