LIB = ./lib_heros.a
NAME = IDLE
FOLDER = ./src/
SRC = ./src/main.c ./src/heros.c ./src/file.c ./src/global.c
LOC_OBJ = $(subst ./src/,./,$(OBJ))
OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

clean:
	rm -f $(LOC_OBJ)

fclean: clean
	rm -f $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(LIB) $(LOC_OBJ)
	ranlib $(LIB)
	gcc -Wall -Werror -Wextra -o $(NAME) $(LIB)
	rm -f $(LOC_OBJ) $(LIB)


re: fclean all

.PHONY:	all clean fclean re