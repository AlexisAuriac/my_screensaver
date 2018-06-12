/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef enum {
	CONTINUE,
	SUCCESS,
	FAILURE
} exit_t;

typedef enum {
	NONE,
	QUIT,
	RELOAD,
	GO_LEFT,
	GO_RIGHT
} interaction_t;

typedef struct disp_tool {
	framebuffer_t *buff;
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2i size;
} disp_tool_t;

#endif