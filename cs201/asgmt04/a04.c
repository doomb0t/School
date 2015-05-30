#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.

// The code you submit must have these two values.
#define N_TIMES		600000
#define ARRAY_SIZE	 10000

int main(void)
{
	double	*array = calloc(ARRAY_SIZE, sizeof(double));
	double	sum = 0;
	int     i;
	// You can add variables between this comment ...

	// ... and this one.

	// Please change 'your name' to your actual name.
	printf("CS201 - Asgmt 4 - Jonathon Sonesen \n"); 
    
	for (i = 0; i < N_TIMES; i++) {

		// You can change anything between this comment ...

    	        int j = 0;
                while(ARRAY_SIZE > j + 1) {
		// ... and this one. But your inner loop must do the same
		// number of additions as this one does.
                    sum += array[j] + array[j + 1];
                    j += 2; 
                    }
                
                if (j < ARRAY_SIZE)
                    sum += array[j];
        }
	// You can add some final code between this comment ...

	// ... and this one.

	return 0;
}
