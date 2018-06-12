/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Creates a maze using the randomized prim's algorithm.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

interaction_t rand_cells(maze_t *maze, sfRenderWindow *window, int old_x,
			int old_y)
{
	bool (*tests[4])(cell_t **, int *, int *) = {left, right, up, down};
	bool (*mem)(cell_t **, int *, int *) = NULL;
	int random = 0;
	int new_x = old_x;
	int new_y = old_y;
	interaction_t quit;

	for (int i = 4 ; i > 0 ; --i) {
		new_x = old_x;
		new_y = old_y;
		random = rand() % i;
		if (tests[random](maze->cells, &new_x, &new_y)) {
			quit = add_cell(maze, window, new_x, new_y);
			if (quit != NONE)
				return (quit);
		}
		mem = tests[random];
		tests[random] = tests[i - 1];
		tests[i - 1] = mem;
	}
	return (0);
}

interaction_t add_cell(maze_t *maze, sfRenderWindow *window, int x, int y)
{
	interaction_t quit = NONE;

	if (get_nbpass(maze->cells, x, y) > 1)
		return (0);
	maze->cells[x][y] = PATH;
	if ((x + y) % 4 == 0)
		maze_display(window, maze);
	quit = get_event(window);
	if (quit != NONE)
		return (quit);
	quit = rand_cells(maze, window, x, y);
	if (quit != NONE)
		return (quit);
	maze->cells[x][y] = PASSAGE;
	return (0);
}

static void put_exit(maze_t *maze)
{
	int out = 0;
	int try = 1;

	while (try) {
		out = my_randrange(1, HEIGHT_MZ - 2);
		if (maze->cells[WIDTH_MZ - 2][out] == PASSAGE) {
			maze->cells[WIDTH_MZ - 1][out] = EXIT;
			try = 0;
		}
	}
}

int build_maze(maze_t *maze, sfRenderWindow *window)
{
	int start = 0;
	interaction_t quit = NONE;

	start = my_randrange(1, HEIGHT_MZ - 2);
	quit = add_cell(maze, window, 0, start);
	if (quit != NONE)
		return (-quit);
	maze->cells[0][start] = START;
	put_exit(maze);
	return (start);
}
