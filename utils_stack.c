/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:50:50 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/15 18:14:38 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack **head_a, t_stack **head_b)
{
	t_stack	*current;

	current = *head_a;
	while (current != NULL)
	{
		ft_printf("%d ", current->val);
		current = current->next;
	}
	ft_printf("A");
	ft_printf("\n");
	current = *head_b;
	while (current != NULL)
	{
		ft_printf("%d ", current->val);
		current = current->next;
	}
	ft_printf("B");
	ft_printf("\n");
}

void	insert_head(t_stack **head, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->val = value;
	new->next = *head;
	*head = new;
}

void	insert_tail(t_stack **head, int value)
{
	t_stack	*new;
	t_stack	*curr;

	curr = *head;
	new = malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	new->next = NULL;
	new->val = value;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

int	stacklen(t_stack *head)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	list_is_sorted(t_stack **head_a, int size)
{
	t_stack	*current;

	if (*head_a == NULL)
		return (0);
	current = *head_a;
	while (current->next != NULL && (current->val < current->next->val))
	{
		current = current->next;
	}
	if (current->next == NULL && size == stacklen(*head_a))
		return (1);
	return (0);
}
