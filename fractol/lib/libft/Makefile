# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 17:10:17 by inoteboo          #+#    #+#              #
#    Updated: 2023/05/03 08:37:21 by inoteboo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := libft.a
CC := gcc
HEADERFILES := libft.h
CFLAGS ?= -Wall -Wextra -Werror -g
OBJFILES :=	ft_atoi.o		\
			ft_bzero.o		\
			ft_calloc.o		\
			ft_isalnum.o	\
			ft_isalpha.o	\
			ft_isascii.o	\
			ft_isdigit.o	\
			ft_isprint.o	\
			ft_itoa.o		\
			ft_memchr.o		\
			ft_memcmp.o		\
			ft_memcpy.o		\
			ft_memmove.o	\
			ft_memset.o		\
			ft_putchar_fd.o	\
			ft_putendl_fd.o	\
			ft_putnbr_fd.o	\
			ft_putstr_fd.o	\
			ft_strchr.o		\
			ft_strdup.o		\
			ft_strjoin.o	\
			ft_strlcat.o	\
			ft_split.o		\
			ft_strlcpy.o	\
			ft_strlen.o		\
			ft_strncmp.o	\
			ft_strnstr.o	\
			ft_strrchr.o	\
			ft_strtrim.o	\
			ft_substr.o		\
			ft_tolower.o	\
			ft_toupper.o	\
			ft_strmapi.o	\
			ft_striteri.o	\

$(NAME): $(OBJFILES)
	ar -rcs $@ $^

all: $(OBJFILES)
	ar -rcs $(NAME) $^
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

re: fclean
	@$(MAKE) all

clean:
	rm -f $(OBJFILES)

fclean:
	rm -f $(NAME) $(OBJFILES)

.PHONY: all clean fclean re