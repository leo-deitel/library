#include "header/myType.h"
#include "header/myList.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


list emptyList(void)		/* costruttore lista vuota */
{
	return NULL;
}


boolean empty(list l)	/* verifica se lista vuota */
{
	if (l == NULL)
		return True;
	else
		return False;
}

list cons(myType e, list l)
{
	list t;
	t = (list)malloc(sizeof(item));

	if (t == NULL)
		exit(-6);

	t->value = e;
	t->next = l;
	return t;
}

myType head(list l) /* selettore testa lista */
{
	if (l == NULL)
		exit(-2);
	else
		return (l->value);
}

list tail(list l)
{
	if (l == NULL || l->next == NULL)
		return NULL;

	else
		return l->next;
}

void showlist(list l) {

	list lTemp = l;
	printf("Stampo la lista:\n");
	
	if (lTemp == NULL) {
		printf("Lista vuota.\n");
	}
	else {
		//while (lTemp->next != NULL) {
		//	printf("%d, %s, %s\n", lTemp->value.id, lTemp->value.ingresso, lTemp->value.uscita);
		//	lTemp = lTemp->next;
		//}
		//printf("%d, %s, %s\n", lTemp->value.id, lTemp->value.ingresso, lTemp->value.uscita);
	}
}


void showlistRic(list l) {
	
	myType temp;
	
	if (l != NULL) {
		temp = head(l);
		//printf("%f %s %d\n",
		//	temp.costo, temp.tipo, temp.calorie);
		showlistRic(tail(l));
		return;
	}
	else {
		printf("\n\n");
		return;
	}
}



void freelistRic(list l) {
	if (l == NULL)
		return;
	else {
		freelistRic(tail(l));
		free(l);
	}
	return;
}



void freelist(list* l)
{
	list lTemp = *l;
	list nextNode;

	while (lTemp != NULL) {
		nextNode = lTemp->next;
		free(lTemp);
		lTemp = nextNode;
	}
	*l = NULL;
}



//void freelist(list* l)
//{
//	list lTemp = *l;
//
//	if (*l == NULL) {
//		return;
//	}
//	while (lTemp->next != NULL) {
//		list toKill = lTemp;
//		lTemp = lTemp->next;
//		free(toKill);
//	}
//	free(lTemp);
//	*l = NULL;
//}




myType get(list l, int index)
{
	list lTemp = l;
	int i = 0;
	
	while (lTemp != NULL && i != index) {
		i++;
		lTemp = tail(lTemp);
	}

	if (i == index) {
		return head(lTemp);
	}

	//altrimenti esce con codice 4
	else {
		exit(-4);
	}

}



int member(myType el, list l) {
	int result = 0;
	
	while (!empty(l) && !result) {
		result = (el.field1 == head(l).field1);
		if (!result)
			l = tail(l);
	}
	return result;
}


int findInList(myType elem, list l)
{
	int index = 0;
	if (l == NULL) {
		return -1;
	}
	
	list lTemp = l;
	
	while (lTemp->next != NULL) {
		if (equalsMyType(lTemp->value, elem)) {
			return index;
		}
		lTemp = lTemp->next;
		index++;
	}
	if (equalsMyType(lTemp->value, elem)) {
		return index;
	}
	return -1;
}


int lengthList(list l)
{
	int n = 0;
	while (!empty(l)) {// posso usare direttamente l tanto fa una copia
		n++;
		l = tail(l);
	}
	return n;
}


int lengthListRic(list l) {
	if (empty(l))
		return 0;
	else 
		return 1 + lengthListRic(tail(l));
}



list appendList(list l1, list l2)
{
	if (empty(l1))
		return l2;
	
	if (empty(l2))
		return l1;
	
	list pointer = l1;
	while (pointer->next != NULL) {
		pointer = pointer->next;
	}
	pointer->next = l2;

	return l1;
}

list copyList(list l) {
	
	if (empty(l))
		return l;
	else 
		return cons(head(l), copyList(tail(l)));
	
}



list reverseList(list l) {
	if (empty(l))
		return emptyList();
	else
		return appendList(reverseList(tail(l)), cons(head(l), emptyList()));
}




int listToArray(list l, myType* arr, int arr_size)
{

	int len, i;
	if (l == NULL) {
		return -1;
	}

	len = lengthList(l);
	if (arr_size < len)
		return -1;
	
	for (i = 0; i < len; i++) {
		arr[i] = get(l, i);
	}

	return len;
}



list arrayToList(myType arr[], int dim) {
	int i;
	list toReturn = emptyList();
	
	for (i = 0; i < dim; i++) {
		toReturn = cons(arr[i], toReturn);
	}

	return toReturn;
}



list getPointer(list l, int index) {
	
	if (l == NULL) {
		return NULL;
	}

	list pointer = l;
	int i = 0;

	while (pointer->next != NULL && i != index) {
		pointer = pointer->next;
		i++;
	}
	if (i != index) {
		return NULL;
	}
	else {
		return pointer;
	}

}



int removeIndex(list* l, int index)
{
	int len = lengthList(*l);
	if (l == NULL) {
		return -2;
	}
	else if (index >= len) {
		return -1;
	}
	else if (index == 0) {
		list toDel = *l;
		*l = getPointer(*l, 1);
		free(toDel);
		return 1;
	}
	else if (index + 1 == len) {
		list preToDel = getPointer(*l, len - 2);
		list toDel = preToDel->next;
		preToDel->next = NULL;
		free(toDel);
		return 1;
	}
	else {
		list preToDel = getPointer(*l, index - 1);
		list toDel = preToDel->next;
		list postToDel = toDel->next;
		preToDel->next = postToDel;
		free(toDel);
		return 1;
	}

}




list insOrd(myType el, list l) {
	if (empty(l))
		return cons(el, l);
	else if (compareMyType(el, head(l)) <= 0)// in questo caso minore uguale di zero se a precede b, sistemalo in base a come implementi la compare(nelle libreire e il contrario di qui)
		return cons(el, l);
	else
		return cons(head(l), insOrd(el, tail(l)));
}



list ordinaList(list l) {

	list lOrd = emptyList();

	while (!empty(l)) {
		lOrd = insOrd(head(l), lOrd);
		l = tail(l);
	}
	return lOrd;
}


//------------------------------------------



//int trovaPosMaxList(list l, int dim_to_consider) {
//	
//	int i, posMax = 0;
//	int n = dim_to_consider;
//	int test;
//	
//	for (i = 1; i < n; i++) {
//		
//		if ((test = compareMyType(get(l, posMax), get(l, i))) == 1)
//			posMax = i;
//
//	}
//	printf("%d", posMax);
//	return posMax;
//}
//
//void insOrd(list first_elem, int pos)
//{
//	int i = pos - 1;
//	myType x = get(first_elem, pos);
//
//	while (i >= 0 && compare(x, get(first_elem, i)) == 1)
//	{
//		getPointer(first_elem, i + 1)->value = getPointer(first_elem, i)->value; /* crea lo spazio */
//		i--;
//	}
//	getPointer(first_elem, i + 1)->value = x;
//}
//
//void merge(root first_elem, int i1, int i2, int fine, root second_elem)
//{
//	int i = i1, j = i2, k = i1;
//	while (i <= i2 - 1 && j <= fine) {
//		if (compare(get(first_elem, i), get(first_elem, j)) == 1)
//			getPointer(second_elem, k)->value = get(first_elem, i++);
//		else
//			getPointer(second_elem, k)->value = get(first_elem, j++);
//		k++;
//	}
//	while (i <= i2 - 1) {
//		getPointer(second_elem, k)->value = get(first_elem, i++);
//		k++;
//	}
//	while (j <= fine) {
//		getPointer(second_elem, k)->value = get(first_elem, j++);
//		k++;
//	}
//	for (i = i1; i <= fine; i++) {
//		getPointer(first_elem, i)->value = get(second_elem, i);
//	}
//}
//
//void mergeSortInner(root first_elem, int first, int last, root second_elem)
//{
//	int mid;
//	if (first < last) {
//		mid = (last + first) / 2;
//		mergeSortInner(first_elem, first, mid, second_elem);
//		mergeSortInner(first_elem, mid + 1, last, second_elem);
//		merge(first_elem, first, mid + 1, last, second_elem);
//	}
//}
//
//void quickSortInner(root first_elem, int iniz, int fine)
//{
//	int i, j, iPivot;
//	myType pivot;
//	if (iniz < fine)
//	{
//		i = iniz;
//		j = fine;
//		iPivot = fine;
//		pivot = get(first_elem, iPivot);
//		do { /* trova la posizione del pivot */
//			while (i < j && (compare(get(first_elem, i), pivot) == 1 || compare(get(first_elem, i), pivot) == 0)) i++;
//			while (j > i && (compare(get(first_elem, j), pivot) == -1 || compare(get(first_elem, j), pivot) == 0)) j--;
//			if (i < j) swapElem(first_elem, i, j);
//		} while (i < j);
//		if (i != iPivot && compare(get(first_elem, i), get(first_elem, iPivot)) != 0)
//		{
//			swapElem(first_elem, i, iPivot);
//			iPivot = i;
//		}
//		/* ricorsione sulle sottoparti, se necessario */
//		if (iniz < iPivot - 1)
//			quickSortInner(first_elem, iniz, iPivot - 1);
//		if (iPivot + 1 < fine)
//			quickSortInner(first_elem, iPivot + 1, fine);
//	}
//}
//
//void naiveSort(root first_elem)
//{
//	int p;
//	int size = lenght(first_elem);
//	while (size > 1) {
//		p = trovaPosMax(first_elem, size);
//		if (p < size - 1) {
//			swapElem(first_elem, p, size - 1);
//		}
//		size--;
//	}
//}
//
//void bubbleSort(root first_elem)
//{
//	int i, ordinato = 0;
//	int size = lenght(first_elem);
//	while (size > 1 && !ordinato) {
//		ordinato = 1;
//		for (i = 0; i < size - 1; i++)
//			if (compare(get(first_elem, i), get(first_elem, i + 1)) == -1) {
//				swapElem(first_elem, i, i + 1);
//				ordinato = 0;
//			}
//		size--;
//	}
//}
//
//void insertSort(root first_elem)
//{
//	int size = lenght(first_elem);
//	int k;
//	for (k = 1; k < size; k++)
//		insOrd(first_elem, k);
//}
//
//void mergeSort(root* first_elem) {
//	root second_elem = newCopy(*first_elem);
//	mergeSortInner(*first_elem, 0, lenght(*first_elem) - 1, second_elem);
//	destroy(first_elem);
//	*first_elem = second_elem;
//}
//
//void quickSort(root first_elem)
//{
//	quickSortInner(first_elem, 0, lenght(first_elem) - 1);
//}


