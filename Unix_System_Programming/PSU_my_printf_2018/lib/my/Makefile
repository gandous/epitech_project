## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_str_isprintable.c	\
		my_strlen.c		\
		my_printf.c		\
		print_base.c		\
		my_putstr_mod.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a
HEADER	=	my.h

all: $(NAME)

$(NAME):	$(SRC)
	gcc -c $(SRC) -I./
	ar rc $(NAME) $(OBJ)
	mkdir ../../include -p
	cp $(NAME) ../
	cp $(NAME) ../../
	cp $(HEADER) ../../include
	rm $(OBJ)

copy:
	cp $(NAME) ../
	cp $(HEADER) ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f  ../$(NAME)
	rm -f ../../$(NAME)
	rm -f ../../include/$(HEADER)

re: 	fclean all
