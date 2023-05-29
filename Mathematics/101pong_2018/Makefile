##
## EPITECH PROJECT, 2018
## 101pong | Makefile
## File description:
## Makefile
##

NAME		=	101pong

SRC		=	al1.c		\
			error.c		\
			velocity.c	\
			display.c	\
			coordinates.c	\
			incidence_angle.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):
		gcc -o $(NAME) -lm $(SRC) -I./include/


clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
