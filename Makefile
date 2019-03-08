# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 17:41:05 by gfielder          #+#    #+#              #
#    Updated: 2019/02/21 18:14:43 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
CC=clang
CFLAGS=-Wall -Wextra -Werror -I libft/
LIB=-L libft/ -lft

SRC=input.c output.c shape.c tetrimino.c solve.c position.c

all: $(NAME)

$(NAME): $(SRC) main.c fillit.h
	@make -C libft/
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(SRC) main.c

test: $(SRC) test_cli.c
	@$(CC) $(CFLAGS) -o test $(SRC) test_cli.c

clean:
	@make -C libft/ clean

fclean:
	@make -C libft/ fclean
	@rm -f $(NAME)

re:
	@make -C libft/ re
	@rm -f $(NAME)
	@make all
