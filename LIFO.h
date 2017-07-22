/*********************************************************/
/**	File: LIFO.h					**/
/**	Author: Mael "ADDRMeridan" MOULIN		**/
/**	Made for holiday practice			**/
/**	Last Modified: 22/07/2017			**/
/**	Music: Buckethead - Electric Tears		**/
/**	Drink: Coca-Cola				**/
/*********************************************************/

#ifndef LIFO_H
#define LIFO_H

#include <stdbool.h>

#define LIFO_MAX_SIZE 5 //Maximum size of your LIFO
//Can be set from 0 to the maximum of an unsigned int

typedef int LIFO_el; //Change the LIFO element type here

typedef struct str_LIFO *LIFO; //Define the type LIFO

/*****CONSTRUCTOR*****/

//Initialize a new LIFO
//Returns NULL if something goes wrong
LIFO createLIFO();

/*****FUNCTIONS*****/

//Returns if the LIFO is empty or not
bool isLIFOEmpty(LIFO l);

//Returns if the LIFO is full or not (based on LIFO_MAX_SIZE defined higher)
bool isLIFOFull(LIFO l);

//Returns the last element added to LIFO. If LIFO is empty, returns NULL
LIFO_el topLIFO(LIFO l);

//Adds a LIFO_el (defined higher) to the given LIFO.
//Returns the given LIFO even if modification hasn't been made.
LIFO addToLIFO(LIFO_el toAdd, LIFO l);

//Returns the number of elements contained in the LIFO.
unsigned int nbElLIFO(LIFO l);

//Removes the top element of given LIFO and frees the memory used by it.
//Returns the given LIFO even if modification hasn't been made.
LIFO popLIFO(LIFO l);

/*****DESTRUCTOR*****/

//Frees the memory used by the LIFO and his elements.
void deleteLIFO(LIFO l);

#endif
