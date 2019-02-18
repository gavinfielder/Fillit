
NAME=test
CC=clang
CFLAGS=-Wall -Wextra -I. -g

DEF=tetrimino.h shape.h
SRC=input.c output.c shape.c test_cli.c test_functions.c tetrimino.c libft/*.c # backtracking.c

all: $(NAME)

$(NAME): $(SRC) $(DEF)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
