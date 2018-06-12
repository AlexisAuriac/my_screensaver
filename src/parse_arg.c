/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Parses the arguments of the program.
*/

#include <unistd.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph.h"
#include "screensaver.h"

exit_t error_display(char **envp)
{
	int found = 0;
	int i = 0;

	for (; envp[i] ; ++i) {
		if (my_strncmp("DISPLAY=", envp[i], 8) == 0) {
			found = 1;
			break;
		}
	}
	if (!found || my_strlen(envp[i]) == my_strlen("DISPLAY=")) {
		ERROR_DISPLAY_NOT_SET;
		return (FAILURE);
	} else if (my_strcmp(envp[i], "DISPLAY=:0.0")) {
		ERROR_INVALID_DISPLAY;
		return (FAILURE);
	}
	return (CONTINUE);
}

exit_t option(char **av)
{
	if (av[1][0] != '-')
		return (CONTINUE);
	if (my_strcmp(av[1], "-h") == 0)
		my_printf(usage, av[0], MAX_ID);
	else if (my_strcmp(av[1], "-d") == 0)
		my_putstr(description);
	else {
		ERROR_UNKNOWN_OPT(av[1]);
		return (FAILURE);
	}
	return (SUCCESS);
}

exit_t error_arg(int ac, char **av, int *id)
{
	if (ac != 2) {
		ERROR_INV_NB_ARG;
		return (FAILURE);
	}
	if (av[1][0] == '-')
		return (option(av));
	else if (!my_str_is(av[1], NUM)) {
		ERROR_ARG_NOT_NUM;
		return (FAILURE);
	}
	*id = my_getnbr(av[1]);
	if (*id <= 0 || *id > MAX_ID) {
		ERROR_INV_ID;
		return (FAILURE);
	}
	return (CONTINUE);
}

exit_t parse_arg(int ac, char **av, char **envp, int *id)
{
	exit_t error = CONTINUE;

	error = error_display(envp);
	if (error)
		return (error);
	error = error_arg(ac, av, id);
	return (error);
}