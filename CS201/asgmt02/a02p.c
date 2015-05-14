// starter file for Assignment 2p

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function for checking that your assembly code is computing the correct result
double quadraticRootC(double a, double b, double c)
{
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

double quadraticRoot(double a, double b, double c)
{
    double root = 0;
	// writeoassembly code below to calculate the quadratic root
	asm(
		/* Delete the line below. It's only there to allow the starter code
		 * to compile. You will be replacing it with your own code.				*/
		"fld    %[a]              \n"
                "fadd   %%ST              \n"
                "fld    %[a]              \n"
                "fld    %[c]              \n"
                "fmulp  &&ST(!)           \n"
                "fadd   %%ST              \n"
                "fchs                     \n"
                "fld    %[b]              \n"
                "fmulp  %%ST(1)           \n"
                "faddp  %%ST(1)           \n"
                "ftst                     \n"
                "fstsw  %%AX              \n"
                "sahf                     \n"
                "fsqrt                    \n"
                "fld    %b                \n"
                "fchs                     \n"
                "fdivp  %%ST(1)           \n"
                "mov    %[root], %%eax    \n"
                "fstp   %%qword, %%eax    \n"
                "mov    $1, %%eax         \n"
                "jmp    short done        \n"
                "done:                    \n"
                :[root] "=g"(root)
                :[a] "g"(a), [b] "g"(b), [c] "g"(c)
                    :"eax"
	);

	return 0;
}

// do not change this function, except to print your own name
int main(int argc, char **argv)
{
	double	a, b, c;
	double	root, rootC;

	printf("CS201 - Assignment 2p - I. Forgot\n");	// print your own name instead
	if (argc != 4) {
		printf("need 3 arguments: a, b, c\n");
		return -1;
		}
	a = atof(argv[1]);
	b = atof(argv[2]);
	c = atof(argv[3]);
	root = quadraticRoot(a, b, c);
	rootC = quadraticRootC(a, b, c);

	printf("quadraticRoot(%.3f, %.3f, %.3f) = %.3f, %.3f\n", a, b, c, root, rootC);

	return 0;
}
