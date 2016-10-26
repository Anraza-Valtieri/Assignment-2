/*
 * ICT1002 Assignment 2, 2016-17 Trimester 1.
 *
 * This file implements the main program, including the main loop that
 * reads commands and executes them.
 */

 #include <ctype.h>
 #include <stdio.h>
 #include <string.h>
 #include "blogo.h"
 
 
 /*
  * Main method. Do not modify this function.
  */
int main(char *argv[], int argc) {

	char line[MAX_INPUT];		/* buffer for holding a line of input from the user */
	int line_no;				/* the line number input by the user */
	int num_tokens;				/* the number of tokens in the input */
	char command[MAX_INPUT];	/* buffer for holding the current command */
	char arg[MAX_INPUT];		/* buffer for holding the current argument */
	int done = 0;				/* set to 1 to end the main loop */
	
	/* initialise the canvas, the turtle and the program */
	canvas_init();
	turtle_init();
	program_init();
	
	/* print a welcome message */
	printf("Welcome to the ICT1002 Logo interpreter.\n");
	printf("Type commands one line at a time, after the ? prompt.\n");
	printf("Execute EXIT to finish.\n\n");
	// Test
	/* main interpreter loop */
	while (!done) {
	
		/* read a line of input */
		printf("? ");
		fgets(line, MAX_INPUT - 1, stdin);
		parse_line(line, &line_no, command, arg);
		
		/* process the input */
		if (line_no > 0) {
			/* got a line number; update the program */
			program_update(line_no, command, arg);
		} else if (line_no == 0) {
			/* no line number; execute the command immediately */
			done = do_command(command, arg);
		} else {
			/* invalid line number */
			printf("Invalid line number: %d\n", line_no);
		}
		
	}
	
	printf("Goodbye!\n");
	
	/* de-allocate the program */
	program_close();
	
	return 0;
	
}


/*
 * Utility function for comparing commands, arguments, etc. case-insensitively.
 *
 * Input:
 *   token1 - the first token
 *   token2 - the second token
 *
 * Returns:
 *   as strcmp()
 */
int compare_token(const char *token1, const char *token2) {
	
	int i = 0;
	while (token1[i] != '\0' && token2[i] != '\0') {
		if (toupper(token1[i]) < toupper(token2[i]))
			return -1;
		else if (toupper(token1[i]) > toupper(token2[i]))
			return 1;
		i++;
	}
	
	if (token1[i] == '\0' && token2[i] == '\0')
		return 0;
	else if (token1[i] == '\0')
		return -1;
	else
		return 1;
	
}


/*
 * Parse a line of Logo. The buffers for the command and the argument should be
 * at least as long as the line provided.
 *
 * Input:
 *   line - the line to be parsed
 *   line_no - a memory location in which the line number will be stored
 *   command - a buffer in which the command (if any) will be stored
 *   arg - a buffer in which the argument (if any) will be stored
 *
 * Returns:
 *   the number of tokens successfully parsed on the line
 */
int parse_line(const char *line, int *line_no, char *command, char *arg) {
	
	/* get the line number, if any */
	const char *endp;
	*line_no = strtol(line, &endp, 10);
	if (line == 0)
		endp = line;
		
	/* get the command and its argument, if any */
	int num_tokens = sscanf(endp, "%s%s", command, arg);
	if (num_tokens < 1)
		command[0] = '\0';
	if (num_tokens < 2)
		arg[0] = '\0';
	
	return num_tokens;
	
}