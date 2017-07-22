/*********************************************************/
/**	File: LIFO.c					**/
/**	Author: Mael "ADDRMeridan" MOULIN		**/
/**	Made for holiday practice			**/
/**	Last Modified: 22/07/2017			**/
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
	
	LIFO_el el;
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

	return l->first->el;
}

LIFO addToLIFO(LIFO_el toAdd, LIFO l) {

	//Check if enough space
	if(isLIFOFull(l)) {
		fprintf(stderr, ANSI_RED"addToLIFO: given LIFO is already"
			" full. LIFO not modified.\n"ANSI_RESET);
		return l;	
	}
	//Init New Cell
	struct cell *tmp = malloc(sizeof(struct cell));
	if(tmp == NULL) {
		fprintf(stderr, ANSI_RED"addToLIFO: failed to malloc"
			" a new cell.\n"ANSI_RESET);
	} else {
		tmp->el = toAdd;
		tmp->next = l->first;
		//Adding new cell
		l->first = tmp;
		++l->nbEl;	
	}
	return l;
}

unsigned int nbElLIFO(LIFO l) {

	return l->nbEl;
}

LIFO popLIFO(LIFO l) {

	if(isLIFOEmpty(l)) {
		fprintf(stderr, ANSI_RED"popLIFO: LIFO is empty."
			" LIFO not modified.\n"ANSI_RESET);
	} else {
		struct cell *tmp = l->first;
		l->first = l->first->next;
		free(tmp);
		--l->nbEl;
	}
	return l;
}

void deleteLIFO(LIFO l) {

	while(!isLIFOEmpty(l)) {
		l = popLIFO(l);
	}
	free(l);
}
