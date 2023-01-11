#ifndef _FILEH
#define _FILEH

#include "myRealType.h"

//Legge un carattere per volta e continua ad inserire nel buffer finché non incontra il separatore o il fine linea
//funzione che dato un file e un carattere di separazione sep, estragga, partendo dalla posizione corrente nel file, il campo terminato da sep e lo inserisca
//in un buffer anch’esso dato
//Il carattere di fine linea funge sempre e comunque da separatore, dunque evitare separatore + fine linea
int readField(char buffer[], char separator, FILE* f);

/// <summary>
/// legge un file di testo che contiene anche separatori (tipo nomi staccati o ;, virgole ec..)
/// </summary>
/// <param name="nomeFile">nome del file che apre in modalita read text</param>
/// <param name="elenco">array di myRealType</param>
/// <param name="i">indice</param>
void letturaFileTxtSeparatori(char* nomeFile, myRealType* elenco, int* i);



//apre il file in sola lettura e in modalità binaria
//legge dal file specificando la dimensione dell’elemento (myRealType) e il numero massimo di elementi da leggere (dimensione array) (!!! devi mettere dim corretto, pre quello e' coimmentato)
//chiude il file
int readFromBin(char* nomeFile, myRealType* arrayMyRealType);

//apre il file in sola scrittura e in modalità binaria
//scrive sul file specificando la dimensione dell’elemento (myRealType) ed il numero effettivo di elementi da scrivere (presenti nell’array)
//chiude il file
void writeToBin(char* nomeFile, myRealType* arrayMyrealtype, int count);

#endif