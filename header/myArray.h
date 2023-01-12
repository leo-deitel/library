#ifndef _MYARRAY
#define _MYARRAY


int inputArr(int* arr, int size);


void printArr(int* arr, int size);

//return l'indice della prima occorrenza, altrimenti -1 se non l'ho trovato
int searchElem(int* arr, int size, int x);

//return 0 se i due array hanno gli stessi valori negli stessi indici
//return -1 e il primo array ha il carattere discorde maggiore o se l'array è di dimensione maggiore
//return 1 se il secondo array ha il carattere discorde maggiore o se l'array è di dimensione maggiore
int arrCompare(int* arr1, int size1, int* arr2, int size2);


int countOccurrency(int* arr, int size, int x);


void scambiaInt(int* a, int* b);

//n e la dimensione massima del array
//trova la pos maggiore e ritorna l indice
int trovaPosMaxInt(int v[], int n);


//Usata in insert sort
//v[]:	L'array dentro cui inserire in modo corretto l'elemento
//pos:	La posizione a cui si trova l'elemento da inserire
void insOrdInt(int v[], int pos);

//sorting array tramite naive sort (arr e dimesione)
void naiveSortInt(int* arr, int size);

//sorting array tramite bubble sort (arr e dimesione)
void bubbleSortInt(int* arr, int size);

//sorting array tramite insert sort (arr e dimesione)
void insertSortInt(int* arr, int size);

//funzione di merge che fa lavoro 'sporco'
void mergeInt(int v[], int i1, int i2, int fine, int vout[]);

//suddivide l array
void mergeSortInnerInt(int v[], int first, int last, int vout[]);

//mergeSort(chiama mergeSortInner)
void mergeSortInt(int* in_arr, int size, int* out_arr);

//vera quicksort che viene chiamata da quickSort, solo che e' invocata iniz = 0 e fine = size
void quickSortInnerInt(int a[], int iniz, int fine);

//quickSort
void quickSortInt(int* arr, int size);

#endif