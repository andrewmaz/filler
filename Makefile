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

NAME_FIL = amazurok.filler

MFIL = make -C filler

all:
	$(MFIL)
	mv ./filler/$(NAME_FIL) .

clean:
	$(MFIL) clean

fclean: clean
	rm -f $(NAME_FIL)
	$(MFIL) fclean

re: fclean all
