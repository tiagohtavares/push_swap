/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_stack_orderer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:06:46 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/23 16:07:24 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_stack_order(t_stack **head_a, t_stack **head_b, char c)
{
	t_stack	*current;
	int		val_a;
	int		val_b;

	current = *head_a;
	val_a = (*head_a)->val;
	val_b = (*head_b)->val;
	while (current != NULL)
	{
		if (val_b > current->val)
			val_a = current->val;
		current = current->next;
	}
	while (val_a != (*head_a)->val)
		shiftup(head_a, c);
	if (val_b > val_a)
		shiftup(head_a, c);
	push(head_b, head_a, c);
	simple_stack_order_helper(head_a, c);
}

void	simple_stack_order_helper(t_stack **head_a, char c)
{
	t_stack	*current;
	int		val_a;

	val_a = (*head_a)->val;
	current = *head_a;
	while (current != NULL)
	{
		if (val_a > current->val)
			val_a = current->val;
		current = current->next;
	}
	while (val_a != (*head_a)->val)
		shiftup(head_a, c);
}
