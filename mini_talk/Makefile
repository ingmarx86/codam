# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:22:07 by inoteboo          #+#    #+#              #
#    Updated: 2023/04/27 08:09:26 by inoteboo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minitalk
CC := gcc
HEADERFILES := client.h server.h
CFLAGS ?= -c -Wall -Wextra -Werror -g
SOURCES := $(wildcard *.c)
OBJFILES :=	$(SOURCES:.c=.o)
EXECS :=$(SOURCES:%.c=%)
RM := rm

all: $(OBJFILES) $(EXECS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.o.:
	$(CC) $^ -o $@

re: fclean
	@$(MAKE) all

clean:
	$(RM) -f *.o

fclean: clean
	$(RM) -f $(EXECS)

.PHONY: all clean fclean re