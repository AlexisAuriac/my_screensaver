/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Traces lines of random colors.
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

static void draw_random_line(framebuffer_t *buff)
{
	sfVector2i p1 = {my_randrange(0, W_WIDTH), my_randrange(0, W_HEIGHT)};
	sfVector2i p2 = {my_randrange(0, W_WIDTH), my_randrange(0, W_HEIGHT)};
	sfColor color = random_color();

	fb_drawline(buff, p1, p2, color);
}

interaction_t lines(sfRenderWindow *window)
{
	disp_tool_t *disp = disp_tool_create(W_WIDTH, W_HEIGHT);
	interaction_t quit = NONE;

	if (disp == NULL) {
		ERROR_MALLOC;
		return (QUIT);
	}
	while (quit == NONE) {
		draw_random_line(disp->buff);
		quit = get_event(window);
		disp_tool_display(window, disp);
		sfRenderWindow_display(window);
	}
	disp_tool_destroy(disp);
	return (quit);
}