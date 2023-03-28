# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 11:13:01 by ttavares          #+#    #+#              #
#    Updated: 2023/03/28 11:11:53 by ttavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SRCPUSHSWAP =	push_swap.c operations.c arg_checker.c \
				simple_stack_orderer.c \
				stack_utils.c stack_utils_extra.c \
				sorter_small.c sorter_small_utils.c \
				sorter_large.c sorter_large_utils.c sorter_large_utils_extra.c sorter_large_utils_extra_one.c

NAME = push_swap

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT)
	$(CC) $(SRCPUSHSWAP) $(LIBFT) -o $(NAME)

bonus:


clean:
	make clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean $(NAME)

.PHONY:	all clean fclean re bonus
