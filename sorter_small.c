/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:56:36 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/23 16:24:31 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **head_a)
{
	if ((*head_a)->val > (*head_a)->next->val)
		swap(head_a, 'a');
	else
		return ;
}

void	sort_three(t_stack **head_a, int size, char c)
{
	while (!list_is_sorted(head_a, size) && stacklen(*head_a) != 0)
	{
		if (((*head_a)->val > (*head_a)->next->val)
			&& (*head_a)->val < (*head_a)->next->next->val)
			swap(head_a, c);
		if ((((*head_a)->val < (*head_a)->next->val))
			&& ((*head_a)->val > (*head_a)->next->next->val))
			shiftdown(head_a, c);
		if (((*head_a)->val > (*head_a)->next->val)
			&& ((*head_a)->next->val < (*head_a)->next->next->val))
			shiftup(head_a, c);
		if (((*head_a)->val > (*head_a)->next->val)
			&& (((*head_a)->val > (*head_a)->next->next->val)))
		{
			swap(head_a, c);
			shiftdown(head_a, c);
		}
		if (((*head_a)->val < (*head_a)->next->val)
			&& (((*head_a)->next->val > (*head_a)->next->next->val)))
		{
			swap (head_a, c);
			shiftup(head_a, c);
		}
	}
}

void	sort_small(t_stack **head_a, t_stack **head_b, int size)
{
	int		i;

	i = 0;
	while (!list_is_sorted(head_a, size) && stacklen(*head_a) != 0)
	{
		while (stacklen(*head_a) > 3)
		{
			push(head_a, head_b, 'b');
			i++;
		}
		sort_three(head_a, size - i, 'a');
		small_pushto_a(head_a, head_b);
		sort_a_calculated(head_a, head_b);
	}
}
