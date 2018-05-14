# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurok <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by amazurok          #+#    #+#              #
#    Updated: 2018/03/23 16:46:32 by amazurok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_F = amazurok.filler
NAME_V = my_visual_am

SRC_F= ./filler/ft_add_piece.c ./filler/ft_del.c ./filler/ft_error.c ./filler/ft_new.c \
		./filler/ft_read.c ./filler/ft_set_val.c ./filler/ft_src_best_coor.c ./filler/main.c

SRC_V = ./visual/ft_new.c ./visual/ft_print.c ./visual/ft_read_key.c ./visual/ft_help.c \
		./visual/ft_visual.c ./visual/main.c

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME_F) $(NAME_V)

$(NAME_F): $(SRC_F)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC_F) $(LIB) -o $(NAME_F)

$(NAME_V): $(SRC_V)
	$(MLIB) 
	gcc -Wall -Wextra -Werror $(SRC_V) $(LIB) -o $(NAME_V)
	
clean:
	$(MLIB) clean

fclean: clean
	rm -f $(NAME_F)
	rm -f $(NAME_V)
	$(MLIB) fclean

re: fclean all
