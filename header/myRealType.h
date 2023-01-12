#ifndef _MYREALTYPE
#define _MYREALTYPE

#include <stdlib.h>

typedef struct {

	int fieldA;

} myRealType;//mettilo magari con la maiuscola al compito


//return 1 se sono uguali
//return 0 se NON sono uguali
//MODIFICALA in base al modo in cui le due strutture sono uguali
int equalsMyRealType(myRealType a, myRealType b);



//return -1:			a è maggiore di b
//return  0:			a è uguale a b
//return  1:			a è minore di b
//MODIFICALA in base al modo in cui compararle
int compareMyRealType(myRealType a, myRealType b);


//per i sorting, scambai due valori di tipo myRealType
void scambiaMyRealType(myRealType* a, myRealType* b);


//cerca max element e ne resitusice l indice
//n sarebbe la dimensione massima dell array
int trovaPosMaxMyRealtype(myRealType v[], int n);

//in insert sort
void insOrdMyRealType(myRealType v[], int pos);

//sort array tramite naive sort, l arrray e di tipo myRealType
void naiveSortMyRealType(myRealType* arr, int size);

//sort aray bubbleSort
void bubbleSortMyRealType(myRealType* arr, int size);

//sort array insertSort
void insertSortMyRealType(myRealType* arr, int size);

//funzione di merge ma per myRealType
void mergeMyRealType(myRealType v[], int i1, int i2, int fine, myRealType vout[]);

// dentro mergeSortMyRealType, cosi' posso metto meno parametri quando chiamo la merge sort
void mergeSortInnerMyRealType(myRealType v[], int first, int last, myRealType vout[]);

//sort array mergeSort 
void mergeSortMyRealType(myRealType* in_arr, int size, myRealType* out_arr);


//sarebbe quickSort ma va dento quickSort cosi' posso concedermi il lusso di inserire meno parametri in quickSort
void quickSortInnerMyRealType(myRealType a[], int iniz, int fine);

//sort array quickSort
void quickSortMyRealType(myRealType* arr, int size);


#endif