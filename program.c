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


/* Arrays Matters
#define ID_LEN MAX_INPUT
typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;
Array orderedIds;*/

void initArray(Array *a, size_t initialSize) {
    // from our struct we create an array starting with 0 being used ;)
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 1;
    a->size = initialSize;
}

int insertArray(int line_no, Array *a, int element) {
    // If we require more space, create it!
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    // Normally -1 line_no comes from commands without line numbers
    if (line_no == -1){
        a->array[a->used++] = element;
		printf("insertArray -1: line_no: %d Element: %d.\n", line_no,element);
        return line_no;
    }else{ // The commands have a line number attached to it.
        a->array[line_no] = element;
        a->used++;
		printf("insertArray number attached: line_no: %d Element: %d.\n", line_no, element);
        return line_no;
    }
}

int addElement(int positionToInsertAt, Array *a, int element)
{
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    for (int i = a->used; i != 0; --i){
        if (i < positionToInsertAt){
            printf("addElement < i=%d positionToInsertAt=%d\n",i,positionToInsertAt);
            a->array[i] = a->array[i];
        }
    
        if (i == positionToInsertAt){
            printf("addElement == i=%d positionToInsertAt=%d\n",i,positionToInsertAt);
            a->array[i] = element;
            a->used++;
            return i;
        }
    
        if (i > positionToInsertAt){
            printf("addElement > i=%d positionToInsertAt=%d\n",i,positionToInsertAt);
            a->array[i] = a->array[i-1];
        }
    }
    return -1;
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
    initArray(&orderedIds, 1);  // initial 1 elements
    printf("freeArray called.\n");
}

void deleteArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
    printf("deleteArray called.\n");
}

/*
 * De-allocate the memory used by the program.
 */
void program_close() {
	
	/* to be implemented */
    deleteArray(&orderedIds);
	
}


/*
 * Initialise the program. The program begins without any
 * lines in it.
 */
void program_init() {
	// init the array
    initArray(&orderedIds, 1);  // initially 1 elements
	
}


/*
 * Execute the program.
 *
 * Returns:
 *   the number of command successfully executed.
 */
int program_execute() {
	
	/* to be implemented */
    int totalCommands, successfulCommands = 0;
    /* to be implemented */
    printf("program_execute completed with successfulCommands: %d and a total of %d commands.\n", successfulCommands, totalCommands);
    return totalCommands;
    
	
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
	printf("program_read Called.\n");
    int totalCommands = 0;
	/* to be implemented */
    freeArray(&orderedIds);
	printf("program_read completed with a total of %d commands.\n", totalCommands);
	return totalCommands;
	
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
	// If line number in 10s we are good
    if(line_no % 10 == 0){
        line_no = line_no/LINEMOD;
        printf("program_update: Adding new entry at %d\n", line_no);
        if (compare_token(command, "backward") == 0)
            return insertArray(line_no, &orderedIds,((BACKWARDS*MOD)+ atoi(arg)));
        else if (compare_token(command, "forward") == 0)
            return insertArray(line_no, &orderedIds,((FORWARD*MOD)+ atoi(arg)));
        else if (compare_token(command, "left") == 0)
            return insertArray(line_no, &orderedIds,((LEFT*MOD)+ atoi(arg)));
        else if (compare_token(command, "list") == 0)
            do_list(arg);
        else if (compare_token(command, "load") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else if (compare_token(command, "output") == 0)
            do_output(arg);
        else if (compare_token(command, "pen") == 0)
            return insertArray(line_no, &orderedIds,((PEN*MOD)+atoi(arg)));
        else if (compare_token(command, "print") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else if (compare_token(command, "right") == 0)
            return insertArray(line_no, &orderedIds,((RIGHT*MOD)+atoi(arg)));
        else if (compare_token(command, "run") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else if (compare_token(command, "save") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else if (compare_token(command, "exit") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else
            printf("Unrecognised command: %s.\n", command);
    }else{ // We are no longer in 10s means we want to insert inbetween some index
        line_no = (line_no/10)+1;
        printf("program_update: Inserting entry at %d\n", line_no);
        if (compare_token(command, "backward") == 0)
            return addElement(line_no, &orderedIds,((BACKWARDS*MOD)+ atoi(arg)));
        else if (compare_token(command, "forward") == 0)
            return addElement(line_no, &orderedIds,((FORWARD*MOD)+ atoi(arg)));
        else if (compare_token(command, "left") == 0)
            return addElement(line_no, &orderedIds,((LEFT*MOD)+ atoi(arg)));
        else if (compare_token(command, "list") == 0)
            do_list(arg);
        else if (compare_token(command, "load") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else if (compare_token(command, "output") == 0)
            do_output(arg);
        else if (compare_token(command, "pen") == 0)
            return addElement(line_no, &orderedIds,((PEN*MOD)+atoi(arg)));
        else if (compare_token(command, "print") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else if (compare_token(command, "right") == 0)
            return addElement(line_no, &orderedIds,((RIGHT*MOD)+atoi(arg)));
        else if (compare_token(command, "run") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else if (compare_token(command, "save") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else if (compare_token(command, "exit") == 0)
            printf("Unrecognised command with line number: %s.\n", command);
        else
            printf("Unrecognised command: %s.\n", command);
    }
    
    
    
    return 0;
    
}


/*
 * Write the program to a file.
 *
 * Input:
 *   f - the file
 */
void program_write(FILE *f) {
	
	/* do be implemented */
    printf("program_write Called\n");
	
}


