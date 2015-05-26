// starter file for Assignment 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function for checking that your assembly code is computing the correct result
double sphereVolumeC(double r)
{
	double	pi = 3.14;					// get value of pi from the chip instead

	return 4.0 * pi * r * r * r / 3.0;
}

double sphereVolume(double r)
{
	// write assembly code below to calculate the volume of the sphere
	asm(
		/* Delete the line below. It's only there to allow the starter code
		 * to compile. You will be replacing it with your own code.				*/
		"		mov		$0, %%eax			\n"
		:									// outputs
		:									// inputs
		: "eax"								// clobbers
	);

	return 0;
}

// do not change this function, except to print your own name
int main(int argc, char **argv)
{
	double	radius;
	double	volume, volumeC;

	printf("CS201 - Assignment 2 - I. Forgot\n");	// print your own name instead
	if (argc != 2) {
		printf("need 1 argument: radius of sphere\n");
		return -1;
		}
	radius = atof(argv[1]);
	volume = sphereVolume(radius);
	volumeC = sphereVolumeC(radius);

	printf("sphereVolume(%.3f) = %.3f, %.3f\n", radius, volume, volumeC);

	return 0;
}
