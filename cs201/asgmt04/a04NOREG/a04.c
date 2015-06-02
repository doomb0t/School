#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.

// The code you submit must have these two values.
#define N_TIMES		600000
#define ARRAY_SIZE	 10000
int main(void)
{
 
    double  *array = calloc(ARRAY_SIZE, sizeof(double));
    double  sum = 0;          //using register double GREATLY decreases execution time
                                       //not sure if I am allowed to do this though
    int     i;
    // You can add variables between this comment ...
    register double* j;
    double sum0 = 0;
    double sum1 = 0;
    double sum2 = 0;
    double sum3 = 0;
    double sum4 = 0;
    
    // ... and this one.
    // Please change 'your name' to your actual name.
    printf("CS201 - Asgmt 4 - Jonathon Sonesen \n"); 

    for (i = 0; i < N_TIMES; i++) {
        
        j = array + (ARRAY_SIZE);     
        while(array < j - 15) {      
            sum0 += *j + *(j - 1) + *(j -2)+ *(j -3);
            sum1 += *j + *(j - 4) + *(j -5)+ *(j -6);
            sum2 += *j + *(j - 7) + *(j -8)+ *(j -9);
            sum3 += *j + *(j - 10) + *(j -11)+ *(j - 12);
            sum4 += *j + *(j - 13) + *(j -14)+ *(j -15);
            j-=15;
            }
       
        if (j > array) {
            sum += *j;
            }
    }
    // You can add some final code between this comment ...
    sum += (sum0 + sum1 + sum2 + sum3 + sum4);
     
    // ... and this one.
    return 0;
}

