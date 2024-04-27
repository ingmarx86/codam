# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:22:07 by inoteboo          #+#    #+#              #
#    Updated: 2023/08/02 14:28:00 by inoteboo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC := gcc
HEADERFILES := philo.h
CFLAGS ?= -pthread -Wall -Wextra -Werror -g #-fsanitize=address
OBJFILES :=	main.o\
			thread_ops.o\
			support_ops.o

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