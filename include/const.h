/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** Constants header file.
*/

#ifndef CONST_H
#define CONST_H

static const int MAX_ID	= 6;

//window
static const int W_WIDTH = 1920;
static const int W_HEIGHT = 1080;
static const int W_FRAMERATE = 60;
static const char W_NAME[] = "My screen savers";

static const int SC_FRAMERATE[] = {
	60,
	30,
	45,
	80,
	30,
	8
};

//options
static const char usage[] =
"animation rendering in a CSFML window.\n\n"
"USAGE\n"
"   %s [OPTIONS] animation_id\n"
"   animation_id    ID of the animation to process "
"between 1 and %d.\n\n"
"OPTIONS\n"
"   -d                print the description of all the "
"animations and quit.\n"
"   -h                print the usage and quit.\n\n"
"USER INTERACTIONS\n"
"   SPACE             reload the current animation\n"
"   LEFT_ARROW        switch to the previous animation.\n"
"   RIGHT_ARROW       switch to the next animation.\n";
static const char description[] =
"1: Squares moving in the window and bouncing when touches a border\n"
"2: Randomly creates a maze and solves it\n"
"3: Creates spirals\n"
"4: Random rapidly appearing on the screen\n"
"5: Draws a fractal with random colors and effects\n"
"6: Imitates a broken tv\n";

//colors
static const sfColor COLORS[] = {
	{255, 255, 255, 255},
	{255, 0, 0, 255},
	{0, 255, 0, 255},
	{0, 0, 255, 255},
	{255, 255, 0, 255},
	{255, 0, 255, 255},
	{0, 255, 255, 255}
};

static const int NB_COLORS = 7;

#endif