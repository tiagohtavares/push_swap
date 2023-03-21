/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:32:02 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/21 16:16:16 by ttavares         ###   ########.fr       */
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
