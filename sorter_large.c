/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:22:04 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/21 16:14:14 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves_toa(t_stack **head_a, t_stack **head_b, int top)
{
	t_stack	*tempa;
	t_stack	*tempb;
	int		movesup;
	int		movesdown;

	tempa = NULL;
	tempb = NULL;
	dupe_list(&tempa, &tempb, head_a, head_b);
	movesup = movesup_down(&tempa, top, 0);
	clear(&tempa, &tempb);
	dupe_list(&tempa, &tempb, head_a, head_b);
	movesdown = movesup_down(&tempa, top, 1);
	clear(&tempa, &tempb);
	if (movesup <= movesdown)
		return (0);
	else
		return (1);
}

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
