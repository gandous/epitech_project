##
## EPITECH PROJECT, 2018
## make file for do op
## File description:
## make fill for do op
##

SRC	=	step4.c		\
		step4_2.c		\
		lib/libmy.a	\

OBJ 	=	$(SRC:.c=.o)

NAME 	=	rush2

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
