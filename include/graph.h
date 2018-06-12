/*
** EPITECH PROJECT, 2017
** graph.h
** File description:
** Contains the prototypes of all the functions in libgraph.a.
*/

#ifndef GRAPH
#define GRAPH

typedef struct framebuffer {
	sfUint8 *pixels;
	int width;
	int height;
}framebuffer_t;

framebuffer_t *fb_create(int width, int height);
void fb_destroy(framebuffer_t *buff);

void fb_setpixel(framebuffer_t *buff, int x, int y, sfColor color);
void fb_drawsqr(framebuffer_t *buff, sfVector2i pos, int size, sfColor color);
void fb_drawline(framebuffer_t *buff, sfVector2i point_a, sfVector2i point_b,
	sfColor color);
int fb_drawcircle(framebuffer_t *buff, sfVector2i center, int radius);
void fb_drawimg(framebuffer_t *buff, sfImage *img, int x, int y);
void fb_fill(framebuffer_t *buff, sfColor color);
void fb_dilute(framebuffer_t *buff, int intensity, int crazy);

int move_rect(sfIntRect *rect, int offset, int max_value);

#endif
