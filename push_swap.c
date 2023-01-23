/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:18:35 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/23 17:04:54 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *current_a)
{
	while (current_a != NULL)
	{
		ft_printf("%d  ", current_a->val);
		current_a = current_a->next;
	}
}

void	insert_head(t_stack **head, int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->val = value;
	new->next = *head;
	*head = new;
}
void	insert_tail(t_stack **head, int value)
{
	t_stack *new;
	t_stack *curr;

	curr = *head;
	new = malloc(sizeof(t_stack));
	if(!new)
		exit(1);
	new->next = NULL;
	new->val = value;
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

void	insert_after(t_stack *prev, int value)
{
	t_stack *new;

	if (prev == NULL)
		return;
	new = malloc(sizeof(t_stack));
	if (!new)
		exit (1);
	new->val = value;
	new->next = prev->next;
	prev->next = new;
}

void	swap(t_stack **head, char c)
{
	t_stack	*swapa;
	t_stack	*swapc;

	if ((*head)->next == NULL)
		return;
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

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	int		i;
	int		j;
	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				{
					ft_printf("Error\n");
					return (0);
				}
				j++;
		}
		insert_tail(&head_a, ft_atoi(argv[i]));
		insert_tail(&head_b, ft_atoi(argv[i]));
		i++;
	}
	printlist(head_a);
	ft_printf("A\n");
	printlist(head_b);
	ft_printf("B\n");
	swap(&head_a, 's');
	swap(&head_b,'e');
	printlist(head_a);
	ft_printf("A\n");
	printlist(head_b);
	ft_printf("B\n");
	return (0);
}
