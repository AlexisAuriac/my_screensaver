/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Handles the square function (used by sc1_madsq).
*/

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

square_t *square_create(square_t *first)
{
	square_t *new_square = malloc(sizeof(square_t));

	if (new_square == NULL) {
		ERROR_MALLOC;
		return (NULL);
	}
	new_square->speed_hor = my_randrange(SPEED_MIN, SPEED_MAX);
	new_square->speed_ver = my_randrange(SPEED_MIN, SPEED_MAX);
	new_square->dir_hor = rand() & 1;
	new_square->dir_ver = rand() & 1;
	new_square->pos.x = W_WIDTH / 2 - SIZE_SQ / 2;
	new_square->pos.y = W_HEIGHT / 2 - SIZE_SQ / 2;
	new_square->color = random_color();
	new_square->next = NULL;
	if (first == NULL)
		return (new_square);
	while (first->next)
		first = first->next;
	first->next = new_square;
	return (NULL);
}

void bounce(square_t *square)
{
	if (square->pos.x >= W_WIDTH - SIZE_SQ) {
		square->dir_hor = LEFT;
		square->pos.x = W_WIDTH - SIZE_SQ;
	} else if (square->pos.x < 0) {
		square->dir_hor = RIGHT;
		square->pos.x = 0;
	}
	if (square->pos.y >= W_HEIGHT - SIZE_SQ) {
		square->dir_ver = UP;
		square->pos.y = W_HEIGHT - SIZE_SQ;
	} else if (square->pos.y < 0) {
		square->dir_ver = DOWN;
		square->pos.y = 0;
	}
}

void square_draw(framebuffer_t *buff, square_t *first)
{
	int i = 0;

	while (first) {
		if (first->dir_hor == LEFT)
			first->pos.x -= first->speed_hor;
		else
			first->pos.x +=	first->speed_hor;
		if (first->dir_ver == UP)
			first->pos.y -=	first->speed_ver;
		else
			first->pos.y += first->speed_ver;
		bounce(first);
		first->color.a = i % 255;
		fb_drawsqr(buff, first->pos, SIZE_SQ, first->color);
		first = first->next;
		++i;
	}
}