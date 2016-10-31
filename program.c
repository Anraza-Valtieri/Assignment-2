/*
 * ICT1002 Assignment 2, 2016-17 Trimester 1.
 *
 * This file contains all of the functions for manipulating the prograim
 * in memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blogo.h"

/* declare all of the types and global variables associated with your program here */
#define ID_LEN 20
char **orderedIds;
int arrayPointer = 0;


void initArray(size_t initialSize) {
    orderedIds = malloc(initialSize * sizeof(char*));
}

void insertArray(int point, char element) {
    orderedIds[point] = malloc((ID_LEN+1) * sizeof(char));
}

void freeArray() {
    free(orderedIds);
}

/*
 * De-allocate the memory used by the program.
 */
void program_close() {
	
	/* to be implemented */
	
}


/*
 * Initialise the program. The program begins without any
 * lines in it.
 */
void program_init() {
	
	/* to be implemented */
	
}


/*
 * Execute the program.
 *
 * Returns:
 *   the number of command successfully executed.
 */
int program_execute() {
	
	/* to be implemented */
	
	return 0;
	
}


/*
 * Read a program from a file. This replaces the existing program.
 *
 * Input:
 *   f - the file
 *
 * Returns:
 *  the number of lines successfully read
 */
int program_read(FILE *f) {
	
	/* to be implemented */
	
	return 0;
	
}


/*
 * Update a line of the program as follows:
 *
 *   If a line with the given line number already exists, it will be replaced.
 *   If the command is NULL or empty, the line will be deleted.
 *   Otherwise, the line will be added to the program.
 *
 * Input:
 *   line_no - the number of the line to be updated
 *   command - the command on this line (may be NULL or empty)
 *   arg - the argument on this line (may be NULL or empty)
 *
 * Returns:
 *   line_no, on success
 *   0, if memory could not be allocated
 */
int program_update(int line_no, const char *command, const char *arg) {

	/* to be implemented */ 

	return line_no;
	
}


/*
 * Write the program to a file.
 *
 * Input:
 *   f - the file
 */
void program_write(FILE *f) {
	
	/* do be implemented */
	
}


