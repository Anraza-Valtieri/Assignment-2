/*
 * ICT1002 Assignment 2, 2016-17 Trimester 1.
 *
 * This file implements all of the Logo commands using the functions provided
 * in other files.
 *
 * All of the functions in this file (except do_commnad) accept a single
 * argument, being a string containing the argument passed to the interpreter. 
 * This string may be NULL or empty if the command does not use an argument.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blogo.h"

//
/*
 * Execute a command.
 *
 * Input:
 *   command - a string containing the command (may be an empty string)
 *   arg - a string containing the argument (may be an empty string)
 *
 * Returns:
 *   0, if the interpreter should continue
 *   1, if the command indicates that the interpreter should exit
 */
int do_command(const char *command, const char *arg) {

	int done = 0;	/* return value */

	if (command == NULL || strlen(command) == 0) {
		/* blank line; do nothing and return */
		return 0;
	}
	
	/* determine which command was given and execute the appropriate function */
	if (compare_token(command, "backward") == 0)
		do_backward(arg);
	else if (compare_token(command, "forward") == 0)
		do_forward(arg);
	else if (compare_token(command, "left") == 0)
		do_left(arg);
	else if (compare_token(command, "list") == 0)
		do_list(arg);
	else if (compare_token(command, "load") == 0)
		do_load(arg);
	else if (compare_token(command, "output") == 0)
		do_output(arg);
	else if (compare_token(command, "pen") == 0)
		do_pen(arg);
	else if (compare_token(command, "print") == 0)
		do_print(arg);
	else if (compare_token(command, "right") == 0)
		do_right(arg);
	else if (compare_token(command, "run") == 0)
		do_run(arg);
	else if (compare_token(command, "save") == 0)
		do_save(arg);
	else if (compare_token(command, "exit") == 0)
		done = 1;
	else
		printf("[Error]: Unrecognised command: %s.\n", command);
	
	return done;
	
}


/*
 * BACKWARD command.
 */
void do_backward(const char *arg) {
	int steps = atoi(arg);
	turtle_move(-steps);
	canvas_write(NULL);
}


/*
 * FORWARD command.
 */
void do_forward(const char *arg) {

	int steps = atoi(arg);
	turtle_move(steps);
	canvas_write(NULL);
}


/*
 * LEFT command.
 */
void do_left(const char *arg) {
	int degree;
	degree = atoi(arg);
	if (degree != 45 && degree != 90 && degree != 135 && degree != 180) {
		printf("Please enter a degree of 45, 90, 135 or 180.\n");
	}
	else {
		turtle_turn(-degree);
	}
}


/*
 * LOAD command.
 */
void do_load(const char *arg) {
	
	/* Errors, we always need an arg. */
	if (arg && !arg[0]) {
		printf("[Error]: The save command requires an argument.\n");
		return;
	}
	FILE *f = fopen(strcat(arg, ".txt"), "r");
	if (f == NULL) {
		printf("File %s does not exists!\n", arg);
	}
	else { program_read(f); }
}


/*
 * LIST command.
 */
void do_list(const char *arg) {
	
	/* to be implemented*/
    program_print_All();
}
	

/*
 * OUTPUT command.
 */
void do_output(const char *arg) {
	printf("output command\n");
	canvas_write(NULL);
	/* to be implemented */
}


/*
 * PEN command.
 */
void do_pen(const char *arg) {
	if (strcmp(arg, "UP") == 0) {
		turtle_setpen(PEN_UP);
	}

	else if (strcmp(arg, "DOWN") == 0) {
		turtle_setpen(PEN_DOWN);
	}

	else {
		printf("The PEN command should be followed by UP or DOWN.\n");
	}
}


/*
 * PRINT command.
 */
void do_print(const char *arg) {
	
	/* to be implemented */
	
}


/*
 * RIGHT command.
 */
void do_right(const char *arg) {
	int degree;
	degree = atoi(arg);
	if (degree != 45 && degree != 90 && degree != 135 && degree != 180) {
		printf("Please enter a degree of 45, 90, 135 or 180.\n");
	}
	else {
		turtle_turn(degree);
	}
}

/*
 * RUN command.
 */
void do_run(const char *arg) {
	
	/* to be implemented */
    program_execute(arg);
	
}


/*
 * SAVE command.
 */
void do_save(const char *arg) {
	
	/* Errors, we always need an arg. */
	if (arg && !arg[0]) {
		printf("[Error]: The save command requires an argument.\n");
		return;
	}
	FILE *fTemp = fopen(strcat(arg, ".txt"), "r");
	if (fTemp != NULL) {
		fclose(fTemp);
		printf("Filename already exists!\n");
	}
	else {
		FILE *f = fopen(arg, "w");
		program_write(f);
	}
	return;
}
