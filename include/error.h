/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Error messages.
*/

#ifndef ERROR_H
#define ERROR_H

//parse_arg
#define ERROR_DISPLAY_NOT_SET		\
my_fputs(2, "Aborting: DISPLAY variable not set\n")
#define ERROR_INVALID_DISPLAY		\
my_fputs(2, "Aborting: DISPLAY variable set incorrectly\n")
#define ERROR_INV_NB_ARG		\
my_putstr("You must give 1 argument\n")
#define ERROR_ARG_NOT_NUM		\
my_putstr("You must give an id as argument\n")
#define ERROR_INV_ID		\
my_putstr("id must be between 1 and MAX_ID, try -d\n")
#define ERROR_UNKNOWN_OPT(opt)		\
my_printf("Unknown option: %s\n", opt)

//window
#define ERROR_CREATE_WIN		\
my_fputs(2, "Failed to create window\n")

//general
#define ERROR_MALLOC		\
my_fputs(2, "Malloc failed\n")

#endif