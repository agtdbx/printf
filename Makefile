# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderouba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 15:01:30 by aderouba          #+#    #+#              #
#    Updated: 2022/10/04 15:55:33 by aderouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --no-print-directory

NAME = libftprintf.a

LIBFT_PATH = libft

SRC =	ft_printf.c

OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I . -I libft/

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME) : $(OBJ)
	@(cd $(LIBFT_PATH)/ && make bonus)
	ar cr $@ $^

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

test: $(NAME)
	gcc -g test.c -L. -lftprintf -L./libft -lft
	./a.out

.PHONY: all clean fclean re test
