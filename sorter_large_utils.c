/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_large_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:05:03 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/23 15:57:07 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_open_move(t_stack **head_a, t_stack **head_b, int chunk)
{
	int	i;

	i = 0;
	if (*head_a == NULL && chunk % 4 == 0)
	{
		push(head_b, head_a, 'a');
		push(head_b, head_a, 'a');
		i += 2;
		if (((*head_a)->val > (*head_a)->next->val))
			swap(head_a, 'a');
	}
	else if (*head_a == NULL)
	{
		push(head_b, head_a, 'a');
		i++;
	}
	return (i);
}

void	push_easy(t_stack **head_a, t_stack **head_b, int *maxa, int *mina)
{
	if ((*head_b)->val > *maxa || (*head_b)->val < *mina)
	{
		while ((*head_a)->val != *mina)
		{
			if (!calc_moves_toa(head_a, head_b, *mina))
				shiftup(head_a, 'a');
			else
				shiftdown(head_a, 'a');
		}
		if ((*head_b)->val > *maxa)
			*maxa = (*head_b)->val;
		else if ((*head_b)->val < *mina)
			*mina = (*head_b)->val;
		push(head_b, head_a, 'a');
	}
}

void	push_middle(t_stack **head_a, t_stack **head_b, int *maxa, int *mina)
{
	t_stack	*current;
	int		nextmin;

	if ((*head_b)->val > *mina && ((*head_b)->val < *maxa))
	{
		current = *head_a;
		nextmin = *mina;
		while (current != NULL)
		{
			if ((*head_b)->val > current->val && nextmin < current->val)
				nextmin = current->val;
			current = current->next;
		}
		while ((*head_a)->val != nextmin)
		{
			if (!calc_moves_toa(head_a, head_b, nextmin))
				shiftup(head_a, 'a');
			else
				shiftdown(head_a, 'a');
		}
		shiftup(head_a, 'a');
		push(head_b, head_a, 'a');
	}
}
