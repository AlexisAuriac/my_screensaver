/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Squares multiplying and bouncing around.
*/

#include <stdlib.h>
#include <stdarg.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

madsq_t *madsq_create(void)
{
	madsq_t *madsq = malloc(sizeof(madsq_t));

	if (madsq == NULL) {
		ERROR_MALLOC;
		return (NULL);
	}
	madsq->buff = fb_create(W_WIDTH, W_HEIGHT);
	if (madsq->buff == NULL) {
		free(madsq);
		return (NULL);
	}
	madsq->list = square_create(NULL);
	if (madsq->list == NULL) {
		my_free_arg(3, madsq->buff->pixels, madsq->buff, madsq);
		return (NULL);
	}
	madsq->nb_sq = 1;
	madsq->wait_spawn = sfClock_create();
	madsq->texture = sfTexture_create(W_WIDTH, W_HEIGHT);
	madsq->sprite = sfSprite_create();
	return (madsq);
}

void madsq_destroy(madsq_t *madsq)
{
	square_t *to_delete = NULL;

	sfClock_destroy(madsq->wait_spawn);
	while (madsq->list) {
		to_delete = madsq->list;
		madsq->list = madsq->list->next;
		free(to_delete);
	}
	fb_destroy(madsq->buff);
	sfTexture_destroy(madsq->texture);
	sfSprite_destroy(madsq->sprite);
	free(madsq);
}

void madsq_display(sfRenderWindow *window, madsq_t *madsq)
{
	fb_fill(madsq->buff, sfBlack);
	square_draw(madsq->buff, madsq->list);
	sfTexture_updateFromPixels(madsq->texture, madsq->buff->pixels,
		W_WIDTH, W_HEIGHT, 0, 0);
	sfSprite_setTexture(madsq->sprite, madsq->texture, sfFalse);
	sfRenderWindow_drawSprite(window, madsq->sprite, 0);
	sfRenderWindow_display(window);
}

interaction_t madsquares(sfRenderWindow *window)
{
	int quit = NONE;
	long time;
	madsq_t *madsq = NULL;

	madsq = madsq_create();
	if (madsq == NULL)
		return (QUIT);
	while (quit == NONE) {
		quit = get_event(window);
		time = sfClock_getElapsedTime(madsq->wait_spawn).microseconds;
		if (time > WAIT_SQ * 1000000000 && madsq->nb_sq < MAX_SQ) {
			square_create(madsq->list);
			++madsq->nb_sq;
			sfClock_restart(madsq->wait_spawn);
		}
		madsq_display(window, madsq);
	}
	madsq_destroy(madsq);
	return (quit);
}