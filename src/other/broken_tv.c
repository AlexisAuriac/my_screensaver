/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Imitates a broken tv.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

void rand_buff(framebuffer_t *buff)
{
	sfColor color = {.a = 255};

	for (int x = 0 ; x < buff->width ; ++x) {
		for (int y = 0 ; y < buff->height ; ++y) {
			color.r = my_randrange(0, 256);
			color.g = color.r;
			color.b = color.r;
			fb_setpixel(buff, x, y, color);
		}
	}
}

interaction_t broken_tv(sfRenderWindow * window)
{
	disp_tool_t *disp = disp_tool_create(W_WIDTH, W_HEIGHT);
	interaction_t quit = NONE;

	if (disp == NULL)
		return (QUIT);
	while (quit == NONE) {
		rand_buff(disp->buff);
		disp_tool_display(window, disp);
		sfRenderWindow_display(window);
		quit = get_event(window);
	}
	disp_tool_destroy(disp);
	return (quit);
}