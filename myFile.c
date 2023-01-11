#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myFile.h"
#include "myRealType.h"

int readField(char buffer[], char separator, FILE* f) {

	int i = 0;
	char c = fgetc(f);

	while (c != separator && c != '\n' && c != EOF) {

		buffer[i] = c;
		i++;
		c = fgetc(f);

	}

	buffer[i] = '\0';
	return i;
}

void letturaFileTxtSeparatori(char* nomeFile, myRealType* elenco, int* i) {

	myRealType temp;
	int continua = 1;
	FILE* file;

	*i = 0;
	file = fopen(nomeFile, "rt");
	if (file == NULL)
		exit(1);

	while (continua) {

		//continua = readField(temp.cognome, ';', file);

		//if (continua)
		//	continua = readField(temp.nome, ';', file);

		//if (continua)
		//	continua = fscanf(file, "%d/%d/%d %c\n", &(temp.nascita).giorno, &(temp.nascita).mese, &(temp.nascita).anno, &temp.sesso);

		//if (continua) {
		//	elenco[*i] = temp;
		//	(*i)++;
		//}
	}

	fclose(file);

}


int readFromBin(char *nomeFile, myRealType* arrayMyRealType) {

	int count = 0;
	FILE* f = fopen(nomeFile, "rb");
	
	if (f == NULL)
		exit(1);

	//count = fread(arrayMyRealType, sizeof(myRealType), DIM, f);
	//fclose(f);
	
	return count;
}



void writeToBin(char *nomeFile, myRealType* arrayMyrealtype, int count)
{
	FILE* f = fopen(nomeFile, "wb");
	
	if (f == NULL)
		exit(1);

	fwrite(arrayMyrealtype, sizeof(myRealType), count, f);

	fclose(f);
}




