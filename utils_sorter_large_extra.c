/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorter_large_extra.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:35:31 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/21 16:13:20 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dupe_list(t_stack **a, t_stack **b, t_stack **head_a, t_stack **head_b)
{
	t_stack	*current;

	(void)b;
	(void)head_b;
	current = *head_a;
	while (current != NULL)
	{
		insert_tail(a, current->val);
		current = current->next;
	}
}

void	order_simple_list(t_stack **head_a, t_stack **head_b, int size)
{
	int		i;

	i = 0;
	while (!list_is_sorted(head_a, size) && stacklen(*head_a) != 0)
	{
		if (stacklen(*head_a) == 2)
		{
			sort_two(head_a);
			return ;
		}
		while (stacklen(*head_a) > 3)
		{
			push(head_a, head_b, 'x');
			i++;
		}
		sort_three(head_a, size - i, 'x');
		while (stacklen(*head_b) != 0)
		{
			sort_small_utils(head_a, head_b, 'x');
		}
	}
}

int	calc_median(t_stack **a, int chunk)
{
	t_stack	*current;
	int		i;

	current = *a;
	i = 0;
	while (i < chunk && current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (current->val);
}

int	find_median(t_stack **head_a, t_stack **head_b, int chunk)
{
	t_stack	*a;
	t_stack	*b;
	int		median;

	a = NULL;
	b = NULL;
	dupe_list(&a, &b, head_a, head_b);
	order_simple_list(&a, &b, stacklen(a));
	median = calc_median(&a, chunk);
	clear(&a, &b);
	return (median);
}

int	movesup_down(t_stack **lst, int top, int type)
{
	int	moves;

	moves = 0;
	if (type == 0)
	{
		while ((*lst)->val != top && (*lst)->next != NULL)
		{
			shiftup(lst, 'x');
			moves++;
		}
	}
	else if (type == 1)
	{
		while ((*lst)->val != top && (*lst)->next != NULL)
		{
			shiftdown(lst, 'x');
			moves++;
		}
	}
	return (moves);
}