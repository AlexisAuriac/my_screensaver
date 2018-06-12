/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Generaly useful functions.
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "my.h"
#include "screensaver.h"

sfRenderWindow *prepare_window(void)
{
	sfVideoMode mode = {W_WIDTH, W_HEIGHT, 32};
	sfRenderWindow *window = NULL;

	window = sfRenderWindow_create(mode, W_NAME, sfFullscreen, 0);
	if (window == NULL) {
		ERROR_CREATE_WIN;
		return (NULL);
	}
	return (window);
}

interaction_t get_event(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		switch (event.type) {
		case sfEvtKeyPressed :
			if (event.key.code == sfKeyEscape)
				return (QUIT);
			else if (event.key.code == sfKeySpace)
				return (RELOAD);
			else if (event.key.code == sfKeyLeft)
				return (GO_LEFT);
			else if (event.key.code == sfKeyRight)
				return (GO_RIGHT);
			break;
		default :
			break;
		}
	}
	return (NONE);
}

int my_randrange(int min, int max)
{
	int random = 0;

	if (max == min)
		return (min);
	random = rand() % (max - min) + min;
	return (random);
}

sfColor random_color(void)
{
	sfColor color;

	color.r = rand() % 255;
	color.g = rand() % 255;
	color.b = rand() % 255;
	color.a = 255;
	return (color);
}