#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/11 10:30:01 by mmarchan          #+#    #+#              #
#    Updated: 2016/02/11 10:30:07 by mmarchan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libfts.a

FUNC = ft_isalpha		\
		ft_isdigit		\
		ft_isalnum		\
		ft_isascii		\
		ft_isprint		\
		ft_toupper		\
		ft_tolower 		\
		ft_bzero		\
		ft_memset		\
		ft_strlen		\
		ft_puts			\
		ft_memcpy		\
		ft_strdup		\
		ft_strcat		\
		ft_cat			

OBJ = $(addsuffix .o, $(FUNC))

all: $(NAME)

$(NAME):
	nasm -f macho64 ft_isalpha.s
	nasm -f macho64 ft_isdigit.s
	nasm -f macho64 ft_isalnum.s
	nasm -f macho64 ft_isascii.s
	nasm -f macho64 ft_isprint.s
	nasm -f macho64 ft_toupper.s
	nasm -f macho64 ft_tolower.s
	nasm -f macho64 ft_bzero.s
	nasm -f macho64 ft_puts.s
	nasm -f macho64 ft_strlen.s
	nasm -f macho64 ft_memset.s
	nasm -f macho64 ft_memcpy.s
	nasm -f macho64 ft_strdup.s
	nasm -f macho64 ft_strcat.s
	nasm -f macho64 ft_cat.s

	@echo "fin nasm -------------------"

	@ar rc $(NAME) $(OBJ)
	@mkdir objects
	@mv $(OBJ) objects/

clean:
	@rm -rf $(OBJ)
	@rm -rf objects/

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

test: re
	gcc -Wextra -Wall -Werror libfts.a main.c
	@echo "fin gcc --------------------"
	@./a.out
