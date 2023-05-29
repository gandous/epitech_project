##
## EPITECH PROJECT, 2018
## 103cipher
## File description:
## Makefile
##

SRC	=	main.c		\
		cipher.c	\
		error_gestion.c	\
		matrix.c	\
		calc.c		\
		print.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

NAME	=	103cipher

all:	$(NAME)

$(NAME):
	gcc -c -g3 $(SRC) $(CFLAGS)
	gcc -o $(NAME) -g3 $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all fclean re
