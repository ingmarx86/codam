# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:22:07 by inoteboo          #+#    #+#              #
#    Updated: 2023/04/04 08:38:34 by inoteboo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := gcc
HEADERFILES := push_swap.h
CFLAGS ?= -Wall -Wextra -Werror -g
OBJFILES :=	push_swap.o		\
			operations_a.o	\
			operations_b.o	\
			recursion.o		\
			sorting.o		\
			checks.o		\

$(NAME): $(OBJFILES)
	$(CC) -o $@ $^

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

re: fclean
	@$(MAKE) all

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re