# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:22:07 by inoteboo          #+#    #+#              #
#    Updated: 2023/05/29 14:54:36 by inoteboo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := gcc
HEADERFILES := -I ./lib/MLX42/include/MLX42	\
			   -I ./lib/libft				\
			   -I ./lib/printf
CFLAGS ?= -Wall -Wextra -Werror -g
LIBMLX := ./lib/MLX42
LIBFT := ./lib/libft
LIBFTPRINTF := ./lib/printf
SANITIZE = -fsanitize=address
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -Iinclude -lglfw3 -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit	\
		$(LIBFT)/libft.a																									\
		$(LIBFTPRINTF)/libftprintf.a
SRCS := $(shell find ./src -iname "*.c")
OBJFILES :=	${SRCS:.c=.o}

all: libft libftprintf $(NAME)

libmlx:
	@cmake $(LIBMLX -B) $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	make -C $(LIBFT)

libftprintf:
	make -C $(LIBFTPRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERFILES)

$(NAME): $(OBJFILES)
	$(CC) $(SANITIZE) $(OBJFILES) $(LIBS) $(HEADERFILES) -o $(NAME)
	
re: fclean
	$(MAKE) all

clean:
	rm -f $(OBJFILES)
	make -C $(LIBFT) clean
	make -C $(LIBFTPRINTF) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
	make -C $(LIBFTPRINTF) fclean

.PHONY: all clean fclean re libmlx libft libftprintf
