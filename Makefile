# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 21:12:41 by akorunsk          #+#    #+#              #
#    Updated: 2017/11/24 16:23:59 by ddenkin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBNAME = libft/libft.a

SRC = src/main.c src/fillit.c src/reader.c src/intersects.c src/validator.c \
	  src/checkshape.c src/recount.c src/output.c src/cleaner.c

INC = -I src/

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

FLAGS = -Wall -Wextra -Werror

CFLAGS = -c $(FLAGS)

LIBINC = -L./libft -lft

all: liball $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(OBJ)
		gcc $(FLAGS) $^ -o $(NAME)

%.o: %.c
		gcc $(CFLAGS) $(INC) -o $@ $<

clean: libclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

$(LIBNAME): liball

liball:
		@make -C libft/ all

libclean:
		@make -C libft/ clean

libfclean:
		@make -C libft/ fclean

libre: libfclean liball
