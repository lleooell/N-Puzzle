# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 15:37:03 by rpuccine          #+#    #+#              #
#    Updated: 2015/04/02 14:41:54 by eruffieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
INCLUDE_FOLDER = -Iincludes/ -Ilibft/includes/
SRC_FOLDER = src/
SRCS = main.c init.c state.c list.c win.c tools.c heuristic.c a_star.c parser.c \
		del.c index.c heuristic2.c state2.c heuristic3.c win_tab.c
SRC = $(addprefix $(SRC_FOLDER), $(SRCS))
OBJ = $(SRC:.c=.o)
NAME = npuzzle
LIB = -Llibft/ -lft

all: libfte $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIB)

libfte:
	make -C libft/

%.o: %.c includes/npuzzle.h
	$(CC) -o $@ -c $<  $(CFLAGS) $(INCLUDE_FOLDER)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ s_fclean
	rm -rf $(NAME)

re: fclean all
