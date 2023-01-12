#define _CRT_SECURE_NO_WARNINGS
#ifndef _MYTYPE
#define _MYTYPE
#include <stdlib.h>

typedef struct {
	int field1;//qualcosa (modificalo in base al tipo!)
} myType;

typedef enum {
	False, True
} boolean;

//1 se sono uguali, 0 altrimenti.
int equalsMyType(myType a, myType b);


// -1: a maggiore b
// 0: a uguale  b
// 1: a minore b
int compareMyType(myType a, myType b);

#endif