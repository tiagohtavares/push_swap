# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 11:13:01 by ttavares          #+#    #+#              #
#    Updated: 2023/03/13 17:11:04 by ttavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SRCPUSHSWAP = push_swap.c

PUSHSWAP = push_swap

all:	$(PUSHSWAP)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PUSHSWAP): $(LIBFT)
	$(CC) -g $(SRCPUSHSWAP) $(LIBFT) -o $(PUSHSWAP)

bonus:


clean:
	make clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(PUSHSWAP)
	make fclean -C $(LIBFT_DIR)

re:	fclean $(PUSHSWAP)

.PHONY:	all clean fclean re bonus
