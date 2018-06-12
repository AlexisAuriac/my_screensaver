/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Header file for the spiral screen saver.
*/

#ifndef SPIRAL_H
#define SPIRAL_H

/* STRUCT */
typedef struct spiral {
	framebuffer_t *buff;
	sfTexture *texture;
	sfSprite *sprite;
	sfColor color;
} spiral_t;

/* PROTOTYPE */
//spiral.c
interaction_t spiral(sfRenderWindow *window);

#endif