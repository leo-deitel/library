
#include "myRealType.h"
#include <stdlib.h>
#include <stdio.h>


int equalsMyRealType(myRealType a, myRealType b)
{
	if (a.fieldA == b.fieldA) {//ed altro che non so..
		return 1;
	}

	else {
		return 0;
	}
}

int compareMyRealType(myRealType a, myRealType b)
{
	if (a.fieldA > b.fieldA) {
		return -1;
	}

	else if (equalsMyRealType(a, b)) {
		return 0;
	}

	else {
		return 1;
	}
}

//void printArrMyRealType(myRealType* arr, int dim)
//{
//	int i;
//
//	printf("Stampo array:\n");
//	for (i = 0; i < dim; i++) {
//		printMyRealType(arr[i]);
//	}
//}

void scambiaMyRealType(myRealType *a, myRealType *b)
{
	myRealType temp = *a;
	*a = *b;
	*b = temp;
}

int trovaPosMaxMyRealType(myRealType v[], int n)
{
	int i, posMax = 0;
	
	for (i = 1; i < n; i++) {
		
		if (compareMyRealType(v[posMax], v[i]) == 1)
			posMax = i;

	}
	return posMax;
}

void insOrdMyRealType(myRealType v[], int pos)
{
	int i = pos - 1;
	myRealType x = v[pos];

	while (i >= 0 && compareMyRealType(x, v[i]) == 1)
	{
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}

	v[i + 1] = x;
}

void naiveSortMyRealType(myRealType* arr, int size)
{
	int p;
	while (size > 1) {
		p = trovaPosMaxMyRealType(arr, size);
		if (p < size - 1) {
			scambiaMyRealType(&arr[p], &arr[size - 1]);
		}
		size--;
	}
}

void bubbleSortMyRealType(myRealType* arr, int size)
{
	int i, ordinato = 0;
	while (size > 1 && !ordinato) {
		
		ordinato = 1;
		for (i = 0; i < size - 1; i++) {
			
			if (compareMyRealType(arr[i], arr[i + 1]) == -1)
			{
				scambiaMyRealType(&arr[i], &arr[i + 1]);
				ordinato = 0;
			}
		}

		size--;
	}
}

void insertSortMyRealType(myRealType* arr, int size)
{
	int k;
	for (k = 1; k < size; k++)
		insOrdMyRealType(arr, k);
}

void mergeMyRealType(myRealType v[], int i1, int i2, int fine, myRealType vout[])
{
	int i = i1,
		j = i2,
		k = i1;
	
	while (i <= i2 - 1 && j <= fine){
		if (compareMyRealType(v[i], v[j]) == 1)
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		
		k++;
	}
	while (i <= i2 - 1){
		vout[k] = v[i++];
		k++;
	}
	while (j <= fine){
		vout[k] = v[j++];
		k++;
	}
	
	for (i = i1; i <= fine; i++)
		v[i] = vout[i];
	
}

void mergeSortInnerMyRealType(myRealType v[], int first, int last, myRealType vout[])
{
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSortInnerMyRealType(v, first, mid, vout);
		mergeSortInnerMyRealType(v, mid + 1, last, vout);
		mergeMyRealType(v, first, mid + 1, last, vout);
	}
}

void mergeSortMyRealType(myRealType* in_arr, int size, myRealType* out_arr)
{
	mergeSortInnerMyRealType(in_arr, 0, size - 1, out_arr);
}

void quickSortInnerMyRealType(myRealType a[], int iniz, int fine)
{
	int i, j, iPivot;
	myRealType pivot;
	
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do { /* trova la posizione del pivot */
		
			while (i < j && (compareMyRealType(a[i], pivot) == 1 || compareMyRealType(a[i], pivot) == 0))
				i++;
			while (j > i && (compareMyRealType(a[j], pivot) == -1 || compareMyRealType(a[j], pivot) == 0))
				j--;
			if (i < j)
				scambiaMyRealType(&a[i], &a[j]);

		} while (i < j);
		
		if (i != iPivot && equalsMyRealType(a[i], a[iPivot]) == 0)
		{
			scambiaMyRealType(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortInnerMyRealType(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortInnerMyRealType(a, iPivot + 1, fine);
	}
}

void quickSortMyRealType(myRealType* arr, int size)
{
	quickSortInnerMyRealType(arr, 0, size - 1);
}

