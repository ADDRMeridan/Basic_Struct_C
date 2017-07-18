/*********************************************************/
/**	File: LIFO.h					**/
/**	Author: Mael "ADDRMeridan" MOULIN		**/
/**	Made for holiday practice			**/
/**	Last Modified: 18/07/2017			**/
/**	Music: Buckethead - Electric Tears		**/
/**	Drink: Coca-Cola				**/
/*********************************************************/

#ifndef LIFO_H
#define LIFO_H

#include <stdbool.h>

#define LIFO_MAX_SIZE 16 //Maximum size of your LIFO
//Can be set from 0 to the maximum of an unsigned int

typedef int *FIFO_el; //Change the FIFO element type here

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



#endif
