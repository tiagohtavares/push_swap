/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorter_large_extra_one.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:20:25 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/21 16:13:59 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	movesup_down_bigger(t_stack **lst, int top, int type)
{
	int	moves;

	moves = 0;
	if (type == 0)
	{
		while ((*lst)->val >= top && (*lst)->next != NULL)
		{
			shiftup(lst, 'x');
			moves++;
		}
	}
	else if (type == 1)
	{
		while ((*lst)->val >= top && (*lst)->next != NULL)
		{
			shiftdown(lst, 'x');
			moves++;
		}
	}
	return (moves);
}

int	calc_moves(t_stack **head_a, t_stack **head_b, int big)
{
	t_stack	*tempa;
	t_stack	*tempb;
	int		movesup;
	int		movesdown;

	tempa = NULL;
	tempb = NULL;
	dupe_list(&tempa, &tempb, head_a, head_b);
	movesup = movesup_down_bigger(&tempa, big, 0);
	clear(&tempa, &tempb);
	dupe_list(&tempa, &tempb, head_a, head_b);
	movesdown = movesup_down_bigger(&tempa, big, 1);
	clear(&tempa, &tempb);
	if (movesup <= movesdown)
		return (0);
	else
		return (1);
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
