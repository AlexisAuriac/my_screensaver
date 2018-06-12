/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** my_screensaver
*/

#ifndef LINES_H
#define LINES_H

/* LINES */
interaction_t lines(sfRenderWindow *window);


/* FRACTAL */
interaction_t fractal(sfRenderWindow *window);

typedef struct fract {
	sfColor color;
	int rev;
	int crazy;
	int jump;
} fract_t;

static const double X1 = -2.1;
UNUSED static const double X2 = 0.6;
static const double Y1 = -1.2;
UNUSED static const double Y2 = 1.2;
static const double ZOOM_X = 1920 / (0.6 - -2.1);//W_WIDTH / (X2 - X1)
static const double ZOOM_Y = 1080 / (1.2 - -1.2);//W_HEIGHT / (Y2 - Y1)

static const int ITER_MAX = 40;
static const int INTENSITY_DILUTE = 15;


/* BROKEN_TV */
interaction_t broken_tv(sfRenderWindow * window);

#endif