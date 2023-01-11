#include "myMath.h"
#include <math.h>

double myMin(double a, double b) {

	if (a < b)
		return a;

	else if (a > b)
		return b;

	else
		return 0;
}

double myMax(double a, double b) {

	if (a > b)
		return a;

	else if (a < b)
		return b;

	else
		return 0;

}

int mcd(int a, int b) {
	
	int r;

	a = abs(a);
	b = abs(b);

	r = a % b;
	while (r > 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int mcm(int a, int b) {
	
	int result;
	a = abs(a);
	b = abs(b);

	result = (a * b) / mcd(a, b);
	return result;
}

void msToTime(int* ms, int* sec, int* min) {

	*ms = abs(*ms);
	*sec = *ms / 1000;
	*ms = *ms % 1000;
	*min = *sec / 60;
	*sec = *sec % 60;

	return;
}

int contaCifre(int n) {
	
	int cifre = 0;
	n = abs(n);

	if (n == 0)
		return 0;

	else
	{
		while (n >= 1) {
			n = n / 10;
			cifre++;
		}
	}
	return cifre;
}

int invertiNumero(int n) {
	int inv = 0;
	int cifre = contaCifre(n);
	int i;

	for (i = cifre; i > 0; i--) {
		inv = inv + n % 10 * (int)pow(10, (double)i - 1);
		n = n / 10;
	}

	return inv;
}
