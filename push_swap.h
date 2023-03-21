/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:31:42 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/21 16:12:57 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;
//push_swap.c
void	arg_size_filter(t_stack **head_a, t_stack **head_b);
int		one_argument_check(char **argv, t_stack **head_a, t_stack **head_b);
//arg_checker.c
int		check_char(char **argv);
long	ft_atol(char *str);
int		check_range(char **argv);
int		check_doubles(char **argv);
void	add_stack(char **argv, t_stack **head_a);
//operations.c
void	swap(t_stack **head, char c);
void	push(t_stack **head_1, t_stack **head_2, char c);
void	shiftup(t_stack **head, char c);
void	shiftdown(t_stack **head, char c);
//utils_stack.c
void	printlist(t_stack **head_a, t_stack **head_b);
void	insert_head(t_stack **head, int value);
void	insert_tail(t_stack **head, int value);
int		stacklen(t_stack *head);
int		list_is_sorted(t_stack **head_a, int size);
//utils_stack_extra.c
void	clear(t_stack **head_a, t_stack **head_b);
//sorter_small.c
void	sort_two(t_stack **head_a);
void	sort_three(t_stack **head_a, int size, char c);
void	sort_small(t_stack **head_a, t_stack **head_b, int size);
//utils_sorter_small.c
void	sort_small_utils(t_stack **head_a, t_stack **head_b, char c);
void	sort_small_utils_extra(t_stack **head_a, char c);
//sorter_large.c
void	sort_a_calculated(t_stack **head_a, t_stack **head_b);
void	sort_large(t_stack **head_a, t_stack **head_b, int size, int div);
int		calc_moves_toa(t_stack **head_a, t_stack **head_b, int big);
//utils_sorter_large_extra_one.c
int		movesup_down_bigger(t_stack **lst, int top, int type);
int		calc_moves(t_stack **head_a, t_stack **head_b, int big);
void	push_to_top(t_stack **head_a, t_stack **head_b, int b, int size);
//utils_sorter_large_extra.c
void	dupe_list(t_stack **a, t_stack **b, t_stack **head_a, t_stack **head_b);
void	order_simple_list(t_stack **head_a, t_stack **head_b, int size);
int		calc_median(t_stack **a, int chunk);
int		find_median(t_stack **head_a, t_stack **head_b, int chunk);
int		movesup_down(t_stack **lst, int top, int type);
//utils_sorter_large.c
void	push_easy(t_stack **head_a, t_stack **head_b, int *maxa, int *mina);
void	push_middle(t_stack **head_a, t_stack **head_b, int *maxa, int *mina);
void	find_minmax(t_stack **head_a, int *maxa, int *mina);
int		push_open_move(t_stack **head_a, t_stack **head_b, int chunk);
void	push_to_a_top(t_stack **head_a, t_stack **head_b, int chunk);

#endif
