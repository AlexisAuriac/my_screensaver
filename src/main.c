/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** Main file.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

int main(int ac, char **av, char **envp)
{
	sfRenderWindow *window = NULL;
	int id = 0;
	exit_t exit_status = parse_arg(ac, av, envp, &id);

	if (exit_status)
		return ((exit_status == SUCCESS) ? 0 : 84);
	window = prepare_window();
	if (window == NULL)
		return (84);
	screensaver(window, id - 1);
	sfRenderWindow_destroy(window);
	return (0);
}