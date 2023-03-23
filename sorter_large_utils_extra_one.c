/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_large_utils_extra_one.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:20:25 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/23 16:25:09 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
