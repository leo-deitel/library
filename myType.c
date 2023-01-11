
#include "myType.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int equalsMyType(myType a, myType b)
{
	if (a.field1 == b.field1) {
		return 1;
	}
	else {
		return 0;
	}
}


int compareMyType(myType a, myType b)
{
	if (a.field1 > b.field1) {
		return -1;
	}
	else if (equalsMyType(a, b)) {
		return 0;
	}
	else {
		return 1;
	}
}

