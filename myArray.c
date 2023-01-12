#include "header/myArray.h"
#include <stdio.h>
#include <stdlib.h>

int inputArr(int* arr, int size)//riempie un array manualmente
{
	int stop = 0;
	int i = 0;
	int val;

	do {
		printf("\nValore all indice '%d' dell'array: ", i);
		scanf_s("%d", &val);
		if (val != 0) {
			arr[i] = val;
			i++;
		}
		else
			stop = 1;
		
	} while (i < size && stop == 0);

	return i;
}

void printArr(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("\nValore all indice '%d' dell'array: %d", i, arr[i]);

}

int searchElem(int* arr, int size, int x)
{
	int i;
	int trovato = 0;
	int val = -1;

	for (i = 0; i < size && trovato == 0; i++) {
		
		if (arr[i] == x) {
			val = i;
			trovato = 1;
		}
	}

	return val;//indice della prima occorrenza di x dentro arr (-1 se non trovato)
}

int arrCompare(int* arr1, int size1, int* arr2, int size2)// (strcmp)
{
	int i;

	for (i = 0; i < size1 && i < size2; i++) {
		if (arr1[i] > arr2[i]) {
			return -1;
		}
		else if (arr1[i] < arr2[i]) {
			return 1;
		}
	}
	if (size1 == size2) {
		return 0;
	}
	else if (size1 > size2) {
		return -1;
	}
	else {
		return 1;
	}

}


int countOccurrency(int* arr, int size, int x)
{
	int i;
	int count = 0;

	for (i = 0; i < size; i++) {
		if (arr[i] == x)
			count++;

	}
	return count;
}

void scambiaInt(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int trovaPosMaxInt(int v[], int n) {
	int i, posMax = 0;

	for (i = 1; i < n; i++) {
		if (v[posMax] < v[i])
			posMax = i;
	}

	return posMax;
}



void naiveSortInt(int* arr, int size)
{
	int p;
	while (size > 1) {
		p = trovaPosMaxInt(arr, size);
		if (p < size - 1) {
			scambiaInt(&arr[p], &arr[size - 1]);
		}
		size--;
	}
}

void bubbleSortInt(int* arr, int size)
{
	int i, ordinato = 0;
	while (size > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < size - 1; i++)
			if (arr[i] > arr[i + 1]) {
				scambiaInt(&arr[i], &arr[i + 1]);
				ordinato = 0;
			}
		size--;
	}
}

void insOrdInt(int v[], int pos)
{
	int i = pos - 1;
	int x = v[pos];
	while (i >= 0 && x < v[i]) {
		v[i + 1] = v[i];
		i--;
	}
	v[i + 1] = x;
}


void insertSortInt(int* arr, int size)
{
	int k;
	for (k = 1; k < size; k++)
		insOrdInt(arr, k);
}

void mergeInt(int v[], int i1, int i2, int fine, int vout[])
{
	int i = i1, j = i2, k = i1;
	
	while (i <= i2 - 1 && j <= fine) {
		if (v[i] < v[j])
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}


	while (i <= i2 - 1) {
		vout[k] = v[i++]; k++;
	}

	while (j <= fine) {
		vout[k] = v[j++]; k++;
	}

	for (i = i1; i <= fine; i++) {
		v[i] = vout[i];
	}
}


void mergeSortInnerInt(int v[], int first, int last, int vout[])
{
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSortInnerInt(v, first, mid, vout);
		mergeSortInnerInt(v, mid + 1, last, vout);
		mergeInt(v, first, mid + 1, last, vout);
	}
}

void mergeSortInt(int* in_arr, int size, int* out_arr)
{
	mergeSortInnerInt(in_arr, 0, size - 1, out_arr);
}

void quickSortInnerInt(int a[], int iniz, int fine)
{
	int i, j, iPivot, pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do { /* trova la posizione del pivot */
			
			while (i < j && a[i] <= pivot) i++;
			while (j > i && a[j] >= pivot) j--;
			
			if (i < j) scambiaInt(&a[i], &a[j]);
		} while (i < j);
		
		if (i != iPivot && a[i] != a[iPivot])
		{
			scambiaInt(&a[i], &a[iPivot]);
			iPivot = i;
		}
		
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortInnerInt(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortInnerInt(a, iPivot + 1, fine);
	}
}

void quickSortInt(int* arr, int size)
{
	quickSortInnerInt(arr, 0, size - 1);
}
