/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Randomly creates a maze and solves it.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

static maze_t *maze_create(void)
{
	maze_t *maze = malloc(sizeof(maze_t));

	if (maze == NULL)
		return (NULL);
	maze->cells = malloc(sizeof(cell_t *) * WIDTH_MZ);
	if (maze->cells == NULL)
		return (NULL);
	for (int i = 0 ; i < WIDTH_MZ ; ++i) {
		maze->cells[i] = my_malloc(sizeof(cell_t) * HEIGHT_MZ);
		if (maze->cells[i] == NULL)
			return (NULL);
	}
	maze->buff = fb_create(W_WIDTH, W_HEIGHT);
	maze->texture = sfTexture_create(W_WIDTH, W_HEIGHT);
	maze->sprite = sfSprite_create();
	return (maze);
}

static void maze_destroy(maze_t *maze)
{
	for (int i = 0 ; i < WIDTH_MZ ; ++i)
		free(maze->cells[i]);
	free(maze->cells);
	fb_destroy(maze->buff);
	sfTexture_destroy(maze->texture);
	sfSprite_destroy(maze->sprite);
	free(maze);
}

void maze_display(sfRenderWindow *window, maze_t *maze)
{
	const sfColor colors[5] = {sfBlack, sfWhite, sfRed, sfBlue, sfGreen};
	sfColor color;
	sfVector2i pos;
	sfUint8 *pixels = maze->buff->pixels;
	sfTexture *text = maze->texture;

	for (int i = 0 ; i < WIDTH_MZ ; ++i) {
		for (int j = 0 ; j < HEIGHT_MZ ; ++j) {
			pos.x = i * SIZE_CELL;
			pos.y = j * SIZE_CELL;
			color = colors[maze->cells[i][j]];
			fb_drawsqr(maze->buff, pos, SIZE_CELL, color);
		}
	}
	sfTexture_updateFromPixels(text, pixels, W_WIDTH, W_HEIGHT, 0, 0);
	sfSprite_setTexture(maze->sprite, text, sfFalse);
	sfRenderWindow_drawSprite(window, maze->sprite, 0);
	sfRenderWindow_display(window);
}

interaction_t maze(sfRenderWindow *window)
{
	maze_t *maze = maze_create();
	int start = 0;

	if (maze == NULL)
		return (QUIT);
	while (1) {
		start = build_maze(maze, window);
		if (start < 0) {
			start = -start;
			break;
		}
		start = maze_solver(window, maze, start);
		if (start != NONE)
			break;
		for (int i = 0 ; i < WIDTH_MZ ; ++i) {
			for (int j = 0 ; j < HEIGHT_MZ ; ++j)
				maze->cells[i][j] = WALL;
		}
	}
	maze_destroy(maze);
	return (start);
}