##
## EPITECH PROJECT, 2018
## 102architect
## File description:
## main Makefile
##

SRC	=	fill_matrix.c		\
		main.c			\
		print.c			\
		error.c		\
		matrix_gestion.c	\
		architect.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -lm

NAME	=	102architect

all:	$(NAME)

$(NAME):
	gcc -c -g3 $(SRC) $(CFLAGS)
	gcc -o $(NAME) -g3 $(OBJ) $(CFLAGS)

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)

re:	clean fclean all

.PHONY:	all clean fclean re
