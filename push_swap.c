/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:18:35 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/25 16:34:24 by ttavares         ###   ########.fr       */
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

void	push(t_stack **head_1, t_stack **head_2, char c)
{
	t_stack	*swap;

	(void)c;
	if (*head_1 == NULL)
		return;
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
	t_stack *swap;
	t_stack *current;

	if ((*head)->next == NULL)
		return;
	swap = *head;
	*head =(*head)->next;
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
	t_stack *current;

	if ((*head)->next == NULL)
		return;
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

int	stacklenght(t_stack *head)
{
	t_stack	*current;
	int	i;

	i = 0;
	current = head;
	while(current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	sort(t_stack **head_a, t_stack **head_b)
{
	int	i;

	i = 0;
	while (i < stacklenght(*head_a))
	{
		push(head_a,head_b,'b');
		i++;
	}
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
		i++;
	}
	printlist(head_a);
	ft_printf("A\n");
	printlist(head_b);
	ft_printf("B\n");
	ft_printf("BEFORE \n\n");
	ft_printf("|COMMANDS|\n");

	sort(&head_a,&head_b);

	ft_printf("|COMMANDS|\n\n");
	printlist(head_a);
	ft_printf("A\n");
	printlist(head_b);
	ft_printf("B\n");
	ft_printf("AFTER \n");
	return (0);
}
