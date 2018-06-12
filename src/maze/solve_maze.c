/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Solves the maze created in mz_maker using dead-end filling.
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "screensaver.h"

static void follow_deadend(sfRenderWindow *window, maze_t *maze, int x, int y)
{
	int i = 0;

	do {
		maze->cells[x][y] = WALL;
		if (i % 4 == 0)
			maze_display(window, maze);
		if (x > 0 && maze->cells[x - 1][y] == PASSAGE)
			--x;
		else if (x < WIDTH_MZ - 1 && maze->cells[x + 1][y] == PASSAGE)
			++x;
		else if (y >= 0 && maze->cells[x][y - 1] == PASSAGE)
			--y;
		else if (y < HEIGHT_MZ - 1 && maze->cells[x][y + 1] == PASSAGE)
			++y;
		++i;
	} while (get_nbpass(maze->cells, x, y) == 1);
}

static interaction_t fill_deadends(sfRenderWindow *window, maze_t *maze)
{
	int nb_pass = 0;
	interaction_t quit = NONE;

	for (int x = 0 ; x < WIDTH_MZ ; ++x) {
		for (int y = 0 ; y < HEIGHT_MZ ; ++y) {
			nb_pass = get_nbpass(maze->cells, x, y);
			if (maze->cells[x][y] == PASSAGE && nb_pass == 1)
				follow_deadend(window, maze, x, y);
			quit = get_event(window);
			if (quit != NONE)
				return (quit);
		}
	}
	return (NONE);
}

static void draw_sol(maze_t *maze, int *x, int *y)
{
	if (*x > 0 && maze->cells[*x - 1][*y] == PASSAGE)
		--(*x);
	else if (*x < WIDTH_MZ - 1 && maze->cells[*x + 1][*y] == PASSAGE)
		++(*x);
	else if (*y > 0 && maze->cells[*x][*y - 1] == PASSAGE)
		--(*y);
	else if (*y < HEIGHT_MZ - 1 && maze->cells[*x][*y + 1] == PASSAGE)
		++(*y);
	maze->cells[*x][*y] = EXIT;
}

int maze_solver(sfRenderWindow *window, maze_t *maze, int start)
{
	sfVector2i prev = {0};
	sfVector2i pos = {0, start};
	interaction_t quit = NONE;

	quit = fill_deadends(window, maze);
	if (quit != NONE)
		return (quit);
	while (pos.x != prev.x || pos.y != prev.y) {
		quit = get_event(window);
		if (quit != NONE)
			return (quit);
		prev = pos;
		draw_sol(maze, &pos.x, &pos.y);
		if ((pos.x + pos.y) % 3 == 0)
			maze_display(window, maze);
	}
	return (NONE);
}