##
## EPITECH PROJECT, 2017
## my_screensaver
## File description:
## Makefile for my_screensaver
##

MADSQ_DIR	=	$(realpath src/mad_squares)

MAZE_DIR	=	$(realpath src/maze)

SPIR_DIR	=	$(realpath src/spiral)

OTHER_DIR	=	$(realpath src/other)

SRC_MADSQ	=	$(MADSQ_DIR)/mad_squares.c	\
			$(MADSQ_DIR)/square.c

SRC_MAZE	= 	$(MAZE_DIR)/maze.c		\
			$(MAZE_DIR)/make_maze.c		\
			$(MAZE_DIR)/cell_tests.c	\
			$(MAZE_DIR)/solve_maze.c

SRC_SPIR	=	$(SPIR_DIR)/spiral.c

SRC_OTHER	=	$(OTHER_DIR)/lines.c		\
			$(OTHER_DIR)/fractal.c		\
			$(OTHER_DIR)/broken_tv.c

SRC		=	src/main.c		\
			src/parse_arg.c		\
			src/utilities.c		\
			src/disp_tool.c		\
			src/screensaver.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_MADSQ:.c=.o)	\
			$(SRC_MAZE:.c=.o)	\
			$(SRC_SPIR:.c=.o)	\
			$(SRC_OTHER:.c=.o)

CFLAGS		+=	-Wall -Wextra

CPPFLAGS	+=	-I include

LDFLAGS		+=	-lm -lc_graph_prog -Llib -lgraph -lmy

NAME		=	my_screensaver

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		$(RM) -f $(OBJ)

fclean	:	clean
		$(RM) -f $(NAME)

re	:	fclean	all

.PHONY	:	all clean fclean re
