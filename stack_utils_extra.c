/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:32:02 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/23 15:48:00 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	if (!head_a || !head_b)
		return ;
	while (*head_a != NULL)
	{
		temp = (*head_a)->next;
		free(*head_a);
		*head_a = temp;
	}
	while (*head_b != NULL)
	{
		temp = (*head_b)->next;
		free(*head_b);
		*head_b = temp;
	}
}

void	clear_one(t_stack **head_a)
{
	t_stack	*temp;

	if (!head_a)
	{
		free (head_a);
		return ;
	}
	while (*head_a)
	{
		temp = (*head_a)->next;
		free(*head_a);
		*head_a = temp;
	}
	free (*head_a);
}

void	argv_free(char	**argv)
{
	int		i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
