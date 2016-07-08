# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 15:37:03 by rpuccine          #+#    #+#              #
#    Updated: 2015/03/27 18:38:32 by rpuccine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_FOLDER = includes/
SRCS = ft_putchar.c ft_putstr.c \
	   ft_atoi.c ft_memchr.c ft_putnbr_fd.c ft_striter.c ft_strnew.c \
	   ft_bzero.c ft_memcmp.c ft_putstr.c ft_striteri.c ft_strnstr.c \
	   ft_isalnum.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c \
	   ft_isalpha.c ft_memdel.c ft_strcat.c ft_strlcat.c ft_strsplit.c \
	   ft_isascii.c ft_memmove.c ft_strchr.c ft_strlen.c ft_strstr.c \
	   ft_isdigit.c ft_memset.c ft_strclr.c ft_strmap.c ft_strsub.c \
	   ft_isprint.c ft_putchar.c ft_strcmp.c ft_strmapi.c ft_strtrim.c \
	   ft_isspace.c ft_putchar_fd.c ft_strcpy.c ft_strncat.c ft_tolower.c \
	   ft_itoa.c ft_putendl.c ft_strdel.c ft_strncmp.c ft_toupper.c \
	   ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c \
	   ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_strlen.c \
	   ft_strconcat.c ft_strnconcat.c \
	   get_next_line.c
SRC = $(addprefix src/, $(SRCS))
OBJ = $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

src/get_next_line.o: $(INCLUDE_FOLDER)get_next_line.h

%.o: %.c $(INCLUDE_FOLDER)libft.h
	$(CC) -o $@ -c $<  $(CFLAGS) -I $(INCLUDE_FOLDER)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

s_fclean:
	rm -rf $(NAME)

re: fclean all
