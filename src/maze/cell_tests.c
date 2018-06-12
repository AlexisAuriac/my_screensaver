/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Tests a cell.
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "screensaver.h"

bool left(cell_t **maze, int *x, int *y)
{
	if (*x <= 0 || maze[*x - 1][*y] != WALL)
		return (0);
	--(*x);
	return (1);
}

bool right(cell_t **maze, int *x, int *y)
{

	if (*x >= WIDTH_MZ || maze[*x + 1][*y] != WALL)
		return (0);
	++(*x);
	return (1);
}

bool up(cell_t **maze, int *x, int *y)
{
	if (*y <= 0 || maze[*x][*y - 1] != WALL)
		return (0);
	--(*y);
	return (1);
}

bool down(cell_t **maze, int *x, int *y)
{
	if (*y >= HEIGHT_MZ || maze[*x][*y + 1] != WALL)
		return (0);
	++(*y);
	return (1);
}

int get_nbpass(cell_t **maze, int x, int y)
{
	int left = (x > 0 && maze[x - 1][y] == WALL) ? 0 : 1;
	int right = (x < WIDTH_MZ - 1 && maze[x + 1][y] == WALL) ? 0 : 1;
	int up = (y > 0 && maze[x][y - 1] == WALL) ? 0 : 1;
	int down = (y < HEIGHT_MZ - 1 && maze[x][y + 1] == WALL) ? 0 : 1;

	return (left + right + up + down);
}