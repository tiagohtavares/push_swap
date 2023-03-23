/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:22:04 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/23 15:57:14 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_calculated(t_stack **head_a, t_stack **head_b)
{
	t_stack	*current;
	int		top;

	current = *head_a;
	top = (*head_a)->val;
	while (current != NULL)
	{
		if (top > current->val)
			top = current->val;
		current = current->next;
	}
	while ((*head_a)->val != top)
	{
		if (!calc_moves_toa(head_a, head_b, top))
			shiftup(head_a, 'a');
		else
			shiftdown(head_a, 'a');
	}
}

void	push_to_a_top(t_stack **head_a, t_stack **head_b, int chunk)
{
	int		i;
	int		maxa;
	int		mina;

	i = push_open_move(head_a, head_b, chunk);
	find_minmax(head_a, &maxa, &mina);
	while (i < chunk)
	{
		if (*head_b != NULL)
			push_easy(head_a, head_b, &maxa, &mina);
		if (*head_b != NULL)
			push_middle(head_a, head_b, &maxa, &mina);
		i++;
	}
}

void	push_to_top(t_stack **head_a, t_stack **head_b, int big, int chunk)
{
	int		i;

	i = 0;
	while ((i < chunk) && *head_a != NULL)
	{
		while ((*head_a)->val >= big && (*head_a)->next != NULL)
		{
			if (!calc_moves(head_a, head_b, big))
				shiftup(head_a, 'a');
			else
				shiftdown(head_a, 'a');
		}
		push(head_a, head_b, 'b');
		i++;
	}
}

void	sort_large(t_stack **head_a, t_stack **head_b, int size, int div)
{
	int		switcher;

	switcher = 1;
	while (!list_is_sorted(head_a, size) && stacklen(*head_a) != 0)
	{
		while (stacklen(*head_a) != 0)
		{
			push_to_top(head_a, head_b,
				find_median(head_a, head_b, size / div), size / div);
			switcher++;
		}
		switcher--;
		while (stacklen(*head_b) != 0)
		{
			if (switcher == (div + 1) && (switcher % div != 0))
				push_to_a_top(head_a, head_b, size % div);
			else if (switcher % div == 0 && switcher != div + 1)
				push_to_a_top(head_a, head_b, size / div);
			switcher--;
		}
		sort_a_calculated(head_a, head_b);
	}
}
