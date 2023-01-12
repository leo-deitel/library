#ifndef _LIST
#define _LIST

#include "myType.h"
#include <stdlib.h>

//Definisco un elemento della mia lista contenente elementi myType (in quello del prof 'Element' al posto di 'myType')
typedef struct item_struct {
	myType value;
	struct item_struct* next;
} item;

//puntatore alla lista (primo elemento)
typedef item* list;

/* PRIMITIVE  */
list emptyList(void);
boolean empty(list l);

//costruttore che aggiunge in testa alla lista
list cons(myType e, list l);
myType head(list l);
list tail(list l);

void showlist(list l);
void showlistRic(list l);
void freelistRic(list l);
void freelist(list* l);


// Restituisce l'elemento all'indice index
//	l: Il puntatore alla lista
//	index: L'indice del valore di cui faccio return
//	return elemento (di tipo myType) all indice desiderato
myType get(list l, int index);



//restituisce indice della prima occorenza di 'elem' di tipo myType (-1 se non c'e' o se la lista e' NULL)
int findInList(myType elem, list l);


int member(myType el, list l);

// restituisce la lunghezza della lista (return 0 se e' vuota)
int lengthList(list l);

int lengthListRic(list l);


//appende la seconda lista in coda alla prima. C'e' structure sharing, quindi NON fare la free leonardone (si sto parlando con me stesso)
//chissa se passo l esame
list appendList(list l1, list l2);

//copia una lista in un altra area di memoria e restituisce il puntatore alla nuova lista.
//non ce structure sharing
list copyList(list l);


//capovolge la lista
list reverseList(list l);


//riempie un array con gli elementi della lista.
//E' necessario dargli anche la dimensione dell array, e se questultima non e abbastanza grande: return -1
//fa return di elementi inseriti nell'array
int listToArray(list l, myType* arr, int arr_size);


//return un puntatore alla lista degli elementi di un array
//return NULL se e' vuoto
list arrayToList(myType arr[], int dim);

// Restituisce il puntatore all'elemento numero index della lista, se lista vuota o non esiste return NULL
list getPointer(list l, int index);


// cancella elemento all'indice index della lista, fa la free sulla sua cella e poi riattacca tutti gli elementi dopo di lui alla lista.
// return 1 se tutto ok, -1 se non esiste quell indice , -2 se la lista è vuota
int removeIndex(list* l, int index);




// nella funzione ordinaLista
list insOrd(myType el, list l);

// return lista ordinata con insOrd
list ordinaList(list l);




//int member(myType el, list l);


#endif