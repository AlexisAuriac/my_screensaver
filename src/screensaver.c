/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Heart of the program.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "screensaver.h"

void screensaver(sfRenderWindow *window, int id)
{
	interaction_t interaction = NONE;

	srand((size_t) window);
	while (interaction != QUIT) {
		sfRenderWindow_setFramerateLimit(window, SC_FRAMERATE[id]);
		interaction = screens[id](window);
		if (interaction == GO_LEFT && id != 0)
			--id;
		else if (interaction == GO_RIGHT && id != MAX_ID - 1)
			++id;
	}
}