#include <stdio.h>
#include "bisezione.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

double myFunzione(double x) {

	return x * x - 2 * x;

}


int myBisezione(int a, int b, int maxIterazioni,
	double epsilon, double* zeroDiFunzione)
{
	double tempA, tempB, funcA, funcB;
	double tempMeta, funcMeta;
	double stop = 0;
	int i;

	if (a > b) {
		tempA = b;
		tempB = a;
	}
	else
	{
		tempA = a;
		tempB = b;
	}



	i = 0;
	while (i < maxIterazioni && !stop)
	{
		tempMeta = (tempA + tempB) / 2;

		funcA = myFunzione(tempA);
		funcB = myFunzione(tempB);
		funcMeta = myFunzione(tempMeta);

		if (funcMeta * funcA < 0)
			tempB = tempMeta;
		else
			tempA = tempMeta;

		stop = (funcMeta == 0.0 || fabs(tempB - tempA) < epsilon);
	}


	if (stop) {
		*zeroDiFunzione = tempMeta;
		return EXIT_SUCCESS;
	}

	else
		return EXIT_FAILURE;

}