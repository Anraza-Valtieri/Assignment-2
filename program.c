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
//
/* declare all of the types and global variables associated with your program here */
/* Arrays Matters */
#define ID_LEN MAX_INPUT
typedef struct {
    struct data *last;
    struct data *first;
    int last_line;
} Program;

Program program;

typedef struct data {
    int line_no;
    int element;
    struct data *next;
    struct data *prev;
} Data;


void initNodes() {
    // from our struct we create an array starting with 0 being used ;)
    program.first = NULL;
    program.last_line = 0;
}

void clearNodes() {
    if (program.first == NULL) {
        printf("clearNodes: Nothing to list.\n");
    }
    else {
        // Init lookup from last Line
        while (1) {
            Data *current_line;
            current_line = program.last;
            //printf("[DEBUG]:clearNodes: Line No: %d data: %d\n", current_line->line_no, current_line->element);
            /* We have reached the end of clearing Nodes. */
            if (current_line->prev == NULL) {
                program.first = NULL;
                program.last = NULL;
                program.last_line = 0;
                break;
            }
            else {
                /* Set pointer to previous Node and free current.*/
                if(current_line->prev != NULL){
                    program.last = current_line->prev;
                    free(current_line);
                }
            }
            
        }
    }
}


int insertNode(int line_no, int element) {
    if (element%MOD > MOD){
        printf("[ERROR]:insertNode: Failed to insert data, element > MOD.\n");
        return 0;
    }
    
    
    /*The program does not have entry so initialize the first one.*/
    if (program.first == NULL) {
        Data *new = malloc(sizeof(Data));
        new->line_no = line_no;
        new->element = element;

        new->next = NULL;
        new->prev = NULL;
        program.first = new;
        program.last = new;
        program.last_line = line_no;
        //printf("[DEBUG]:InsertNode: Insert Line_no %d Data %d.\n", line_no, element);
        
    }else{
        /*Line_no is larger than last registed last line.*/
        if (line_no > program.last_line) {
            Data *new = malloc(sizeof(Data));
            new->line_no = line_no;
            new->element = element;

            new->prev = program.last;
            new->next = NULL;
            
            program.last->next = new;
            program.last = new;
            program.last_line = line_no;
            //printf("[DEBUG]:InsertNode: Insert Line_no %d Data %d.\n", line_no, element);
        }
        else {
            Data *current_line;
            current_line = program.first;
            while (1) {
                /* Line_no already exist so we have to replace*/
                if (current_line->line_no == line_no) {
                    current_line->element = element;
                    //printf("[DEBUG]:InsertNode: Replace Line_no %d Data %d.\n", line_no, element);
                    break;
                }
                
                /* We are inserting inbetween lines here*/
                if (current_line->line_no > line_no) {
                    Data *new = malloc(sizeof(Data));
                    new->line_no = line_no;
                    new->element = element;

                    new->prev = current_line->prev;
                    new->next = current_line;
                    /* Tricky here, we somehow do not have a proper start in nodes so we have to create them
                        ex. we started with line 20 and now want to add in line 10.
                     */
                    if(current_line->prev != NULL){
                        current_line->prev->next = new;
                        current_line->prev = new;
                    }else{
                        current_line->prev = new;
                        program.first = new;
                    }
                    //printf("[DEBUG]:InsertNode: Insert Between Line_no %d Data %d.\n", line_no, element);
                    break;
                }
                
                /* Deadend.*/
                if (current_line->next == NULL) {
                    break;
                }
                else {
                    current_line = current_line->next;
                }
            }
        }
    }
    return line_no;
}

void program_print_All() {
    if (program.first == NULL) {
        printf("program_print_All: Nothing to list.\n");
    }else {
        // Init lookup from first Line
        Data *current_line;
        current_line = program.first;
        int value;
        while (1) {
            value = current_line->element;
            switch (value / MOD) {
                case 1:
                    printf("%d FORWARD %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    break;
                case 2:
                    printf("%d BACKWARD %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    break;
                case 3:
                    printf("%d LEFT %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    break;
                case 4:
                    printf("%d RIGHT %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    break;
                case 5: // PEN
                    if(value%MOD == PEN_UP){
                    printf("%d PEN UP %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    break;
                    }else{
                        printf("%d PEN DOWN %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                        break;
                    }
            }
            if (current_line->next == NULL) {
                break;
            }
            else {
                current_line = current_line->next;
            }
        }
    }
}


/*
 * De-allocate the memory used by the program.
 */
void program_close() {
	
	/* to be implemented */
    clearNodes();
	
}


/*
 * Initialise the program. The program begins without any
 * lines in it.
 */
void program_init() {
	// init the array
    initNodes();  // initially 1 elements
	
}


/*
 * Execute the program.
 *
 * Returns:
 *   the number of command successfully executed.
 */
int program_execute() {
	
	/* to be implemented */
    int totalCommands = 0, successfulCommands = 0;
    if (program.first == NULL) {
        printf("[ERROR]:program_execute: Nothing to execute.\n");
    }else {
        // Init lookup from first Line
        canvas_init();
        turtle_init();
        Data *current_line;
        current_line = program.first;
        int value = 0;
        while (1) {
            value = current_line->element;
            totalCommands++;
            switch (value / MOD) {
                case 1: // FORWARD
                    printf("%d FORWARD %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    do_forward(value%MOD);
                    successfulCommands++;
                    break;
                case 2: // BACKWARD
                    printf("%d BACKWARD %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    do_backward(value%MOD);
                    successfulCommands++;
                    break;
                case 3: // LEFT
                    printf("%d LEFT %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    do_left(value%MOD);
                    successfulCommands++;
                    break;
                case 4: // RIGHT
                    printf("%d RIGHT %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    do_right(value%MOD);
                    successfulCommands++;
                    break;
                case 5: // PEN
                    printf("%d RIGHT %d data: %d\n", current_line->line_no, current_line->element%MOD, current_line->element);
                    if(value%MOD == PEN_UP)
                        do_pen("UP");
                    else
                        do_pen("DOWN");
                    
                    successfulCommands++;
                    break;
            }
            if (current_line->next == NULL) {
                break;
            }
            else {
                
                current_line = current_line->next;
            }
        }
    }
    printf("program_execute completed with a total of %d commands and %d successful.\n", totalCommands,successfulCommands);
    return successfulCommands;
    
	
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
	//CLEAR MEMORY FIRST
	clearNodes();
	char *buffer = (char *)malloc(sizeof(char) * MAX_INPUT - 1);	/* buffer for holding a line of input from file */
	char *command = (char *)malloc(sizeof(char) * MAX_INPUT - 1);	/* buffer for holding the current command */
	char *arg = (char *)malloc(sizeof(char) * MAX_INPUT - 1);		/* buffer for holding the current argument */
	while (!feof(f)) {
		if (fscanf(f, "%s%s%s", buffer, command, arg) == 3) {
			program_update(atoi(buffer), command, arg);
            totalCommands++;
		}
	}
	fclose(f);
	free(buffer);
	free(command);
	free(arg);

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
    //printf("[DEBUG]:program_update: Adding new entry at %d\n", line_no);
    if(atoi(arg) < 0){
        printf("[ERROR]:program_update: Failed adding new entry at %d. Arg < 0\n", line_no);
        return 0;
    }
        
    if (compare_token(command, "backward") == 0)
        return insertNode(line_no,((BACKWARDS*MOD)+ atoi(arg)));
    else if (compare_token(command, "forward") == 0)
        return insertNode(line_no, ((FORWARD*MOD)+ atoi(arg)));
    else if (compare_token(command, "left") == 0){
        if (atoi(arg) != 45 && atoi(arg) != 90 && atoi(arg) != 135 && atoi(arg) != 180) {
            printf("[ERROR]:program_update: Please enter a degree of 45, 90, 135 or 180.\n");
            return 0;
        }else{
            return insertNode(line_no,((LEFT*MOD)+ atoi(arg)));
        }
    }
    else if (compare_token(command, "list") == 0)
        do_list(arg);
    else if (compare_token(command, "load") == 0)
        printf("[ERROR]:program_update:Unrecognised command with line number: %s.\n", command);
    else if (compare_token(command, "output") == 0)
        do_output(arg);
    else if (compare_token(command, "pen") == 0){
        if(strcmp(arg, "UP") == 0 || strcmp(arg, "Up") == 0 || strcmp(arg, "up") == 0)
            return insertNode(line_no,((PEN*MOD)+PEN_UP));
        else if(strcmp(arg, "DOWN") == 0 || strcmp(arg, "Down") == 0 || strcmp(arg, "down") == 0)
            return insertNode(line_no,((PEN*MOD)+PEN_DOWN));
    }
    else if (compare_token(command, "print") == 0)
        printf("[ERROR]:program_update:Unrecognised command with line number: %s.\n", command);
    else if (compare_token(command, "right") == 0){
        if (atoi(arg) != 45 && atoi(arg) != 90 && atoi(arg) != 135 && atoi(arg) != 180) {
            printf("[ERROR]:program_update: Please enter a degree of 45, 90, 135 or 180.\n");
            return 0;
        }else{
            return insertNode(line_no,((RIGHT*MOD)+ atoi(arg)));
        }
    }
    else if (compare_token(command, "run") == 0)
        printf("[ERROR]:program_update:Unrecognised command with line number: %s.\n", command);
    else if (compare_token(command, "save") == 0)
        printf("[ERROR]:program_update:Unrecognised command with line number: %s.\n", command);
    else if (compare_token(command, "exit") == 0)
        printf("[ERROR]:program_update:Unrecognised command with line number: %s.\n", command);
    else
        printf("[ERROR]:program_update:Unrecognised command: %s.\n", command);
    
    return 0;
    
}


/*
 * Write the program to a file.
 *
 * Input:
 *   f - the file
 */
void program_write(FILE *f) {
	printf("program_write Called\n");

	Data *current_line;
	current_line = program.first;
	if (current_line != NULL) {
		int value;
		while (1) {
			value = current_line->element;
			switch (value / MOD) {
			case 1:
				fprintf(f, "%d FORWARD %d\n", current_line->line_no, current_line->element%MOD);
				break;
			case 2:
				fprintf(f, "%d BACKWARD %d\n", current_line->line_no, current_line->element%MOD);
				break;
			case 3:
				fprintf(f, "%d LEFT %d\n", current_line->line_no, current_line->element%MOD);
				break;
			case 4:
				fprintf(f, "%d RIGHT %d\n", current_line->line_no, current_line->element%MOD);
				break;
            case 5:
                if(value%MOD == PEN_UP){
                    fprintf(f,"%d PEN UP\n", current_line->line_no);
                    break;
                }else{
                    fprintf(f,"%d PEN DOWN\n", current_line->line_no);
                    break;
                }
			}
			if (current_line->next == NULL) {
				break;
			}
			else {
				current_line = current_line->next;
			}
		}
	}
	else {
		printf("Nothing stored in program yet...\n");
	}
	printf("File saved successfully!\n");
	fclose(f);
}


