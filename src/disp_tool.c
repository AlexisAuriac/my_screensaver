/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Handles disptools which are used to display frame buffers.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

disp_tool_t *disp_tool_create(int width, int height)
{
	disp_tool_t *disp = malloc(sizeof(disp_tool_t));

	if (disp == NULL) {
		ERROR_MALLOC;
		return (disp);
	}
	disp->buff = fb_create(width, height);
	if (disp->buff == NULL) {
		ERROR_MALLOC;
		free(disp);
		return (disp);
	}
	disp->texture = sfTexture_create(width, height);
	disp->sprite = sfSprite_create();
	disp->size = (sfVector2i) {width, height};
	return (disp);
}

void disp_tool_destroy(disp_tool_t *disp)
{
	fb_destroy(disp->buff);
	sfTexture_destroy(disp->texture);
	sfSprite_destroy(disp->sprite);
	free(disp);
}

void disp_tool_display(sfRenderWindow *window, disp_tool_t *disp)
{
	sfTexture_updateFromPixels(disp->texture, disp->buff->pixels,
		disp->size.x, disp->size.y, 0, 0);
	sfSprite_setTexture(disp->sprite, disp->texture, sfFalse);
	sfRenderWindow_drawSprite(window, disp->sprite, NULL);
}