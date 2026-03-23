##
## EPITECH PROJECT, 2025
## Day10
## File description:
## task01 Makefile
##

INCLUDE_PATH = ./include/

CFLAGS = -I$(INCLUDE_PATH) -g -Wall

NAME = my_top

SRC	= src/main.c \
	src/read_files.c \
	src/parse_flags.c \
	src/display.c \
	src/init.c \
	src/calculs.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	clang $(OBJ) -o $(NAME) -lncurses

push: fclean
	git add .
	git commit -m "$(COMMIT)"
	git push

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
