LIB = ./lib_heros.a
NAME = IDLE
SRC = main.c heros.c file.c global.c
OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	gcc -Wall -Werror -Wextra -o $(NAME) $(LIB)
	rm -f $(OBJ) $(LIB)


re: fclean all

.PHONY:	all clean fclean re