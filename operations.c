/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:49:57 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/15 18:14:26 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head, char c)
{
	t_stack	*swapa;
	t_stack	*swapc;

	if ((*head)->next == NULL)
		return ;
	swapa = *head;
	swapc = (*head)->next->next;
	*head = (*head)->next;
	(*head)->next = swapa;
	swapa->next = swapc;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
	if (c == 's')
		ft_printf("ss\n");
}

void	push(t_stack **head_1, t_stack **head_2, char c)
{
	t_stack	*swap;

	(void)c;
	if (*head_1 == NULL)
		return ;
	swap = (*head_1)->next;
	(*head_1)->next = *head_2;
	*head_2 = *head_1;
	*head_1 = swap;
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}

void	shiftup(t_stack **head, char c)
{
	t_stack	*swap;
	t_stack	*current;

	if ((*head)->next == NULL)
		return ;
	swap = *head;
	*head = (*head)->next;
	swap->next = NULL;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = swap;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
	if (c == 'r')
		ft_printf("rr\n");
}

void	shiftdown(t_stack **head, char c)
{
	t_stack	*current;

	if ((*head)->next == NULL)
		return ;
	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	current->next->next = *head;
	*head = current->next;
	current->next = NULL;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
	if (c == 'r')
		ft_printf("rrr\n");
}
