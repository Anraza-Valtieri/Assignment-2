/*
 * ICT1002 Assignment 2, 2016-17 Trimester 1.
 *
 * This file contains all of the functions for manipulating the canvas.
 */

#include <stdio.h>
#include "blogo.h"

/* declare all of the types and global variables associated with your canvas here */


/*
 * Initialise the canvas. This method should make every cell blank.
 */
void canvas_init() {
		
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

	/* to be implemented */

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
	
	/* to be implemented */
	
}


/*
 * Write the canvas to a file.
 *
 * Input:
 *  f - the file
 */
void canvas_write(FILE *f) {

	/* to be implemented */
	
}