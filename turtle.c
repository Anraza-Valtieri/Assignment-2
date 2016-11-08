/*
* ICT1002 Assignment 2, 2016-17 Trimester 1.
*
* This file contains all of the functions for manipulating the turtle.
*/

#include <stdlib.h>
#include "blogo.h"

/* declare all of the types and global variables associated with your turtle here */

typedef struct {
	int x, y;
	int orientation;
	int pen;
} Turtle;

Turtle turtle;

/*
* Initialise the turtle. The turtle starts at the centre of the canvas,
* facing the top, with the pen down.
*/
void turtle_init() {
	turtle.x = (MAX_X + (2 - 1)) / 2;
	turtle.y = (MAX_Y + (2 - 1)) / 2;
	turtle.orientation = NORTH;
	turtle.pen = PEN_DOWN;
}

void putc_if_pen_down(int x, int y, char c) {
	if (turtle.pen == PEN_DOWN) {
		canvas_putc(x, y, c);
	}
}

/*
* Move the turtle.
*
* Input:
*   steps - the number of steps to take (a negative number means move backwards)
*
* Return:
*   the actual number of steps taken
*/
int turtle_move(int steps) {
	int is_negative;
	int i;

	if (steps < 0) {
		is_negative = -1;
	}
	else {
		is_negative = 1;
	}

	steps = abs(steps);

	switch (turtle.orientation) {
	case NORTH:
		for (i = 0; i < steps; i++) {
			putc_if_pen_down(turtle.x, turtle.y, '#');
			turtle.y -= 1 * is_negative;
		}
		break;
	case SOUTH:
		for (i = 0; i < steps; i++) {
			putc_if_pen_down(turtle.x, turtle.y, '#');
			turtle.y += 1 * is_negative;;
		}
		break;
	case EAST:
		for (i = 0; i < steps; i++) {
			putc_if_pen_down(turtle.x, turtle.y, '#');
			turtle.x += 1 * is_negative;
		}
		break;
	case WEST:
		for (i = 0; i < steps; i++) {
			putc_if_pen_down(turtle.x, turtle.y, '#');
			turtle.x -= 1 * is_negative;
		}
		break;
	case NORTHEAST:
		for (i = 0; i < steps; i++) {
			putc_if_pen_down(turtle.x, turtle.y, '#');
			turtle.x += 1 * is_negative;
			turtle.y -= 1 * is_negative;
		}
		break;
	case NORTHWEST:
		for (i = 0; i < steps; i++) {
			putc_if_pen_down(turtle.x, turtle.y, '#');
			turtle.x -= 1 * is_negative;
			turtle.y -= 1 * is_negative;
		}
		break;
	case SOUTHEAST:
		for (i = 0; i < steps; i++) {
			putc_if_pen_down(turtle.x, turtle.y, '#');
			turtle.x += 1 * is_negative;
			turtle.y += 1 * is_negative;
		}
		break;
	case SOUTHWEST:
		for (i = 0; i < steps; i++) {
			putc_if_pen_down(turtle.x, turtle.y, '#');
			turtle.x -= 1 * is_negative;
			turtle.y += 1 * is_negative;
		}
		break;
	default:
		printf("Something went horribly wrong.\n");
		break;
	};

	return 0;

}


/*
* Print a string at the turtle's location. The string will only be printed
* if the pen is down. This does not move the turtle.
*
* Input:
*   s - the string to be printed
*
* Returns:
*   the number of characters printed
*/
int turtle_print(const char *s) {

	/* to be implemented */

	return 0;

}


/*
* Lift the pen up or down.
*
* Input:
*   pen - PEN_UP or PEN_DOWN
*
* Returns:
*   the new state of the pen
*/
int turtle_setpen(int pen) {
	turtle.pen = pen;
	return turtle.pen;
}


/*
* Turn the turtle. A positive value turns the turtle to the right and
* a negative values turns the turtle to the left.
*
* Input:
*   degrees - the number of degrees to turn the turtle
*
* Returns:
*   the new bearing of the turtle
*/
int turtle_turn(int degrees) {
	int x;

	x = turtle.orientation + degrees;

	if (x == 360 || x == -360) {
		turtle.orientation = 0;
	}
	else if (x > 360) {
		turtle.orientation = x - 360;
	}
	else if (x < 0) {
		turtle.orientation = x + 360;
	}
	else {
		turtle.orientation = x;
	}

	return turtle.orientation;
}
