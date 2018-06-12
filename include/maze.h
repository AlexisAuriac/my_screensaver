/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Header file for the maze screen saver.
*/

#ifndef MAZE_H
#define MAZE_H

/* STRUCTS, ENUMS */
typedef enum {
	WALL,
	PASSAGE,
	PATH,
	START,
	EXIT
} cell_t;

typedef struct maze {
	cell_t **cells;
	framebuffer_t *buff;
	sfTexture *texture;
	sfSprite *sprite;
} maze_t;

/* PROTOTYPES */
//maze.c
void maze_display(sfRenderWindow *window, maze_t *maze);
interaction_t maze(sfRenderWindow *window);

//make_maze.c
interaction_t rand_cells(maze_t *maze, sfRenderWindow *window, int x, int y);
interaction_t add_cell(maze_t *maze, sfRenderWindow *window, int x, int y);
int build_maze(maze_t *maze, sfRenderWindow *window);

//cell_tests.c
bool left(cell_t **maze, int *x, int *y);
bool right(cell_t **maze, int *x, int *y);
bool up(cell_t **maze, int *x, int *y);
bool down(cell_t **maze, int *x, int *y);
int get_nbpass(cell_t **maze, int x, int y);

//solve_maze.c
int maze_solver(sfRenderWindow *window, maze_t *maze, int start);

/* CONSTANTS */
static const int SIZE_CELL = 20;
static const int WIDTH_MZ = 1920 / 20;//W_WIDTH / SIZE_CELL
static const int HEIGHT_MZ = 1080 / 20;//W_HEIGHT / SIZE_CELL

#endif