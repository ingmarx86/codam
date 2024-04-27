# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 17:10:17 by inoteboo          #+#    #+#              #
#    Updated: 2022/12/16 14:56:10 by inoteboo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := libftprintf.a
CC := gcc
HEADERFILES := ft_printf.h
CFLAGS ?= -Wall -Wextra -Werror -g
OBJFILES :=	ft_printf.o		\
			ft_putchar_ptr.o	\
			ft_puthex_ptr.o	\
			ft_puthexx_ptr.o	\
			ft_putnbr_ptr.o	\
			ft_putnbru_ptr.o	\
			ft_putptr_ptr.o	\
			ft_putstr_ptr.o	\
			ft_strlen.o		\

$(NAME): $(OBJFILES)
	ar -rcs $@ $^

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