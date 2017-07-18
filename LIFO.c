/*********************************************************/
/**	File: LIFO.c					**/
/**	Author: Mael "ADDRMeridan" MOULIN		**/
/**	Made for holiday practice			**/
/**	Last Modified: 18/07/2017			**/
/**	Music: Buckethead - Electric Tears		**/
/**	Drink: Coca-Cola				**/
/*********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "LIFO.h"
#include "colors.h"

//Cell structure
struct cell {
	
	FIFO_el el;
	struct cell *next;
};

//LIFO Structure
struct str_LIFO {

	struct cell *first;
	unsigned int nbEl;
};

/*****CONSTRUCTOR*****/

LIFO createLIFO() {

	LIFO tmp = malloc(sizeof(struct str_LIFO));
	if(tmp == NULL) {
		fprintf(stderr, ANSI_RED"createLIFO: failed to malloc"
			" LIFO.\n"ANSI_RESET);
		return NULL;
	}
	tmp->nbEl = 0;
	tmp->first = NULL;
	return tmp;
}

/*****FUNCTIONS*****/

bool isLIFOEmpty(LIFO l) {

	return l->first == NULL;
}

bool isLIFOFull(LIFO l) {

	return l->nbEl >= LIFO_MAX_SIZE;
}

LIFO_el topLIFO(LIFO l) {

	return l->first;
}

LIFO addLIFO(LIFO_el toAdd, LIFO l) {

	struct cell tmp;
	tmp->el = toAdd;
	tmp->next = topLIFO(l);

	return l;
}

//TO REMOVE BEFORE PULLING
int main(int argc, char *argv[]) {

	return 0;
}
