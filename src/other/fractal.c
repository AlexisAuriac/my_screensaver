/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Draws a fractal.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "screensaver.h"

static void init_fract(fract_t *fractal)
{
	fractal->color = COLORS[rand() % NB_COLORS];
	fractal->rev = rand() & 1;
	fractal->crazy = rand() & 1;
	fractal->jump = rand() & 1;
}

static void draw_fractal(framebuffer_t *buff, int max_iter, fract_t *conf)
{
	double c_r = 0;
	double c_i = 0;
	double z_r = 0;
	double z_i = 0;
	double tmp = 0;

	for (int x = 0 ; x < W_WIDTH ; ++x) {
		for (int y = 0, i = 0 ; y < W_HEIGHT ; ++y, i = 0) {
			c_r = x / ZOOM_X + X1;
			c_i = y / ZOOM_Y + Y1;
			z_r = 0;
			z_i = 0;
			do {
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * tmp * z_i + c_i;
			} while (z_r * z_r + z_i * z_i < 4 && ++i < max_iter);
			if (i == max_iter - conf->rev)
				fb_setpixel(buff, x, y, conf->color);
		}
	}
}

interaction_t fractal(sfRenderWindow *window)
{
	disp_tool_t *disp = disp_tool_create(W_WIDTH, W_HEIGHT);
	fract_t conf;
	interaction_t quit = NONE;

	if (disp == NULL)
		return (QUIT);
	init_fract(&conf);
	for (int iter = 1, sign = 1 ; quit == NONE ; iter += sign) {
		fb_dilute(disp->buff, INTENSITY_DILUTE, conf.crazy);
		if (!conf.rev || (iter & conf.jump) == 0)
			draw_fractal(disp->buff, iter, &conf);
		sfRenderWindow_clear(window, sfBlack);
		disp_tool_display(window, disp);
		sfRenderWindow_display(window);
		if (iter % ITER_MAX == 0)
			sign *= -1;
		quit = get_event(window);
	}
	disp_tool_destroy(disp);
	return (quit);
}