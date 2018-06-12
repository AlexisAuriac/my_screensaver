/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Header file for the mad_squares screen saver.
*/

#ifndef MAD_SQUARES_H
#define MAD_SQUARES_H

/* STRUCTS, ENUMS */
typedef	enum {
	LEFT,
	RIGHT,
} hor_t;

typedef enum {
	UP,
	DOWN,
} ver_t;

typedef	struct square {
	int speed_hor;
	hor_t dir_hor;
	int speed_ver;
	ver_t dir_ver;
	sfVector2i pos;
	sfColor color;
	struct square *next;
} square_t;

typedef struct madsq {
	sfClock *wait_spawn;
	square_t *list;
	int nb_sq;
	framebuffer_t *buff;
	sfTexture *texture;
	sfSprite *sprite;
} madsq_t;

/* CONSTANTS */
static const int WAIT_SQ = 12;
static const int MAX_SQ = 1275;

static const int SPEED_MIN = 25;
static const int SPEED_MAX = 50;
static const int SIZE_SQ = 20;
static const int NB_SQ = 1275;

/* PROTOYPES */
//mad_squares.c
interaction_t madsquares(sfRenderWindow *window);

//square.c
square_t *square_create(square_t *first);
void square_draw(framebuffer_t *buff, square_t *first);

#endif