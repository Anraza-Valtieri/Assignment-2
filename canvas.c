/*
 * ICT1002 Assignment 2, 2016-17 Trimester 1.
 *
 * This file contains all of the functions for manipulating the canvas.
 */

#include <stdio.h>
#include "blogo.h"

/* declare all of the types and global variables associated with your canvas here */
char grid[MAX_X][MAX_Y] = { 0 };

/*
 * Initialise the canvas. This method should make every cell blank.
 */
void canvas_init() {
	
	/*Loop to set all cell values to blank*/
	int x, y = 0;
	for (y = 0; y < MAX_Y; y++) {
		for (x = 0; x < MAX_X; x++) {
			canvas_putc(x, y, '.');
		}
	}
	/* to be implemnented */
}


/*
 * Place a character on the canvas, overwriting whatever is in the cell.
 *
 * Input:
 *   x - the x coordinate at which to place the character
 *   y - the y coordinate at which to place the character
 *   c - the character
 *
 * Returns:
 *   the number of characters written (may be zero of x aor y are illegal)
 */
int canvas_putc(int x, int y, char c) {
	//Checks that coordinates are within the bounds of the canvas []
	if (x > -1 && y > -1 && x < MAX_X && y < MAX_Y) {
		grid[x][y] = c;
		return 1;
	}
	else{
		printf("Coordinates not on canvas\n");
		return 0;
	}
    
}


/*
 * Print a string on the canvas, overwriting whatever is in the cells.
 *
 * Input:
 *   x - the x coordinate at which to start the string
 *   y - the y coordinate at which to start the string
 *   s - the string
 *
 * Returns:
 *   the number of characters written
 */
int canvas_puts(int x, int y, const char *s) {
	for (size_t i = 0; i < strlen(s); i++){
		if (x > -1 && y > -1 && x < MAX_X && y < MAX_Y) {
			grid[x][y] = s[i];
		}
		x++;
	}
	
	/* to be implemented */
	canvas_write(NULL);
    return 0;
}


/*
 * Write the canvas to a file.
 *
 * Input:
 *  f - the file
 */
void canvas_write(FILE *f) {
	int x, y = 0;
	//Check if there is a file, otherwise treat as null i.e OUTPUT *
	if (f) {
		printf("Not Null\n");

		for (y = 0; y < MAX_Y; y++) {
			for (x = 0; x < MAX_X; x++) {
				fprintf(f,"%c", grid[x][y]);
			}
			fprintf(f, "\n");
		}
		fclose(f);
	}
	//Print canvas to screen
	else {
		for (y = 0; y < MAX_Y; y++) {
			for (x = 0; x < MAX_X; x++) {
				printf("%c", grid[x][y]);
			}
			printf("\n");
		}
	}
}
