/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Creates spirals.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "screensaver.h"

spiral_t *spiral_create(void)
{
	spiral_t *spiral = malloc(sizeof(spiral_t));

	if (spiral == NULL)
		return (NULL);
	spiral->buff = fb_create(W_WIDTH, W_HEIGHT);
	spiral->texture = sfTexture_create(W_WIDTH, W_HEIGHT);
	spiral->sprite = sfSprite_create();
	spiral->color = random_color();
	return (spiral);
}

void spiral_destroy(spiral_t *spiral)
{
	fb_destroy(spiral->buff);
	sfTexture_destroy(spiral->texture);
	sfSprite_destroy(spiral->sprite);
	free(spiral);
}

void spiral_display(sfRenderWindow *window, spiral_t *spiral)
{
	sfTexture *text = spiral->texture;
	sfUint8 *pixels = spiral->buff->pixels;

	sfTexture_updateFromPixels(text, pixels, W_WIDTH, W_HEIGHT, 0, 0);
	sfSprite_setTexture(spiral->sprite, spiral->texture, sfFalse);
	sfRenderWindow_drawSprite(window, spiral->sprite, 0);
	sfRenderWindow_display(window);
}

interaction_t draw_spiral(int start, int radius, spiral_t *spiral)
{
	float x = 0;
	float y = 0;
	float angle = 0.0;
	interaction_t quit = NONE;
	int i = 0;

	while (quit == NONE) {
		angle = 0.1 * i;
		x = (start + radius * angle) * cos(angle) + W_WIDTH / 2;
		y = (start + radius * angle) * sin(angle) + W_HEIGHT / 2;
		fb_setpixel(spiral->buff, (int) x, (int) y, spiral->color);
		if (x <= 0 || x > W_WIDTH)
			quit = RELOAD;
		++i;
	}
	return (quit);
}

interaction_t spiral(sfRenderWindow *window)
{
	int start = 0;
	int radius = 0;
	spiral_t *spiral = spiral_create();
	interaction_t quit = NONE;
	int i = 0;

	fb_fill(spiral->buff, sfBlack);
	sfRenderWindow_setFramerateLimit(window, 45);
	while (quit == NONE) {
		start = my_randrange(0, 10);
		radius = my_randrange(1, 30);
		quit = draw_spiral(start, radius, spiral);
		spiral_display(window, spiral);
		if (++i == 300)
			quit = RELOAD;
		else
			quit = get_event(window);
	}
	spiral_destroy(spiral);
	return (quit);
}