/*
 * ICT1002 Assignment 2, 2016-17 Trimester 1.
 *
 * This file contains the definitions and function prototypes for all of
 * features of the BLogo interpreter.
 */
 
#include <stdio.h>
 
 
/* the maximum number of characters we expect in a line of input */
#define MAX_INPUT	256
 
/* the dimensions of the canvas */
#define MAX_X 79
#define MAX_Y 24
 
/* directions of travel */
#define NORTH       0
#define NORTHEAST  45
#define EAST       90
#define SOUTHEAST 135
#define SOUTH     180
#define SOUTHWEST 225
#define WEST      270
#define NORTHWEST 315

/* pen states */
#define PEN_DOWN	0
#define PEN_UP		1

/* Commands */
#define FORWARD 1
#define BACKWARDS 2
#define LEFT 3
#define RIGHT 4
#define PEN 5
#define MOD 160 // 52


//Array orderedIds;

/* functions defined in main.c */
int compare_token(const char *token1, const char *token2);
int parse_line(const char *line, int *line_no, char *command, char *arg);


/* functions defined in canvas.c */
void canvas_init();
int canvas_putc(int x, int y, char c);
int canvas_puts(int x, int y, const char *s);
void canvas_write(FILE *f);


/* functions defined in commands.c */
int do_command(const char *command, const char *arg);
void do_backward(int arg);
void do_forward(int arg);
void do_left(int arg);
void do_list(const char *arg);
void do_load(const char *arg);
void do_output(const char *arg);
void do_pen(const char *arg);
void do_print(const char *arg);
void do_right(int arg);
void do_run(const char *run);
void do_save(const char *arg);
 
 
/* functions defined in program.c */
void program_close();
void program_init();
int program_execute();
int program_read(FILE *f);
int program_update(int line_no, const char *command, const char *arg);
void program_write(FILE *f);


/* functions defined in turtle.c */
void turtle_init();
int turtle_move(int steps);
int turtle_print(const char *s);
int turtle_setpen(int pen);
int turtle_turn(int degrees);
