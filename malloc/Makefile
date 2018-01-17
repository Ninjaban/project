#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/21 16:50:10 by mmarchan          #+#    #+#              #
#    Updated: 2016/01/21 16:50:15 by mmarchan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

HEADERS =-I includes/ \
	-I libft/ \

LIBFT = libft/libft.a

SRC =	malloc.c \
	free.c \
	realloc.c \
	show_alloc_mem.c \
	large_malloc.c \
	manage_maps.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -shared -o $@ $(OBJ) $(LIBFT)
	@ln -s $(NAME) libft_malloc.so

clean:
	make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	@rm -f $(NAME)
	@rm -f libft_malloc.so

re: fclean all
