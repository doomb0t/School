#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.

// The code you submit must have these two values.
#define N_TIMES		600000
#define ARRAY_SIZE	 10000
int main(void)
{
 
    double  *array = calloc(ARRAY_SIZE, sizeof(double));
    double  sum = 0;
    int     i;
    // You can add variables between this comment ...
    register double  sum2 = 0;
    register double* j = array + (ARRAY_SIZE - 1);     
    // ... and this one.
    // Please change 'your name' to your actual name.
    printf("CS201 - Asgmt 4 - Jonathon Sonesen \n"); 
    for (i = 0; i < N_TIMES; i++) {
        
        j = array + (ARRAY_SIZE - 1);     
        while(array < j - 1) {      
            sum2 += *j + *(j -1);
            j-=2;
            }
       
        if (j > array) {
            sum2 += *j;
            }
    }
    // You can add some final code between this comment ...
    
    /* BOTTLE NECK */
    sum = sum2;      //this operation is what destroys time performance.
    // ... and this one.
    return 0;
}

