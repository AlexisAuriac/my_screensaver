/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** Contains the prototypes of the project's functions.
*/

#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include "const.h"
#include "struct.h"
#include "macro.h"
#include "error.h"
#include "mad_squares.h"
#include "maze.h"
#include "spiral.h"
#include "other.h"


//parse_arg.c
exit_t parse_arg(int ac, char **av, char **envp, int *id);

//utilities.c
sfRenderWindow *prepare_window(void);
interaction_t get_event(sfRenderWindow *window);
int my_randrange(int min, int max);
sfColor random_color(void);

//disp_tool.c
disp_tool_t *disp_tool_create(int width, int height);
void disp_tool_destroy(disp_tool_t *disp);
void disp_tool_display(sfRenderWindow *window, disp_tool_t *disp);

//screensaver.c
void screensaver(sfRenderWindow *window, int id);


static interaction_t (*const screens[])(sfRenderWindow *) = {
	madsquares,
	maze,
	spiral,
	lines,
	fractal,
	broken_tv
};

#endif