/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:18:35 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/13 19:20:01 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack **head_a,t_stack **head_b)
{
	t_stack *current;

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

int	stacklen(t_stack *head)
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

int	list_is_sorted(t_stack **head_a, int size)
{
	t_stack *current;

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

void	sort_two(t_stack **head_a)
{
	if((*head_a)->val > (*head_a)->next->val)
		swap(head_a, 'a');
	else
		return;
}

void	sort_three(t_stack **head_a, int size)
{
	while (!list_is_sorted(head_a, size) && stacklen(*head_a) != 0)
	{
		if (((*head_a)->val > (*head_a)->next->val) && (*head_a)->val < (*head_a)->next->next->val)
			swap(head_a, 'a');
		if ((((*head_a)->val < (*head_a)->next->val)) && ((*head_a)->val > (*head_a)->next->next->val))
			shiftdown(head_a, 'a');
		if(((*head_a)->val > (*head_a)->next->val) && ((*head_a)->next->val < (*head_a)->next->next->val))
			shiftup(head_a, 'a');
		if (((*head_a)->val > (*head_a)->next->val) && (((*head_a)->val > (*head_a)->next->next->val)))
		{
			swap(head_a, 'a');
			shiftdown(head_a,'a');
		}
		if(((*head_a)->val < (*head_a)->next->val) && (((*head_a)->next->val > (*head_a)->next->next->val)))
		{
			swap (head_a,'a');
			shiftup(head_a,'a');
		}
	}

}

void	sort_small(t_stack **head_a,t_stack **head_b, int size)
{
	t_stack *current;
	int val_a;
	int val_b;
	int i;

	i = 0;
	while (!list_is_sorted(head_a, size) && stacklen(*head_a) != 0)
	{
		while (stacklen(*head_a) > 3)
		{
			push(head_a,head_b,'b');
			i++;
		}
		sort_three(head_a, size - i);
		while(stacklen(*head_b) != 0)
		{
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
				shiftup(head_a,'a');
			if(val_b > val_a)
				shiftup(head_a,'a');
			push(head_b,head_a,'a');
			val_a = (*head_a)->val;
			current = *head_a;
			while (current != NULL)
			{
				if (val_a > current->val)
					val_a = current->val;
				current = current->next;
			}
			while (val_a != (*head_a)->val)
				shiftup(head_a,'a');
		}
	}
}

void	sort_medium(t_stack **head_a,t_stack **head_b, int size)
{
	t_stack *current;
	int maxb;
	int minb;
	int temp;
	int nextmin;

	while (!list_is_sorted(head_a, size) && stacklen(*head_a) != 0)
	{
		if (stacklen(*head_b) == 0)
		{
		maxb = (*head_a)->val;
		push(head_a,head_b,'b');
		printlist(head_a,head_b);
		minb = (*head_a)->val;
		push(head_a,head_b,'b');
		printlist(head_a,head_b);
		if (maxb > minb)
		{
			swap(head_b,'b');
			printlist(head_a,head_b);
		}
		else if (maxb < minb)
		{
			temp = maxb;
			maxb = minb;
			minb = temp;
		}
		}
		if ((*head_a)->val > maxb || (*head_a)->val < minb)
		{
			while ((*head_b)->val != maxb)
			{
				shiftup(head_b,'b');
				printlist(head_a,head_b);
			}
			if ((*head_a)->val > maxb)
				maxb = (*head_a)->val;
			else if ((*head_a)->val < minb)
				minb = (*head_a)->val;
			push(head_a,head_b,'b');
			printlist(head_a,head_b);

		}
		if (*head_a != NULL)
		{
			if ((*head_a)->val > minb && ((*head_a)->val < maxb))
			{
				current = *head_b;
				nextmin = minb;
				while (current != NULL)
				{
					if ((*head_a)->val > current->val && nextmin < current->val)
						nextmin = current->val;
					current = current->next;
				}
				ft_printf("Nextmin = %d \n", nextmin);
				while ((*head_b)->val != nextmin)
				{
					shiftup(head_b,'b');
					printlist(head_a,head_b);
				}
				push(head_a,head_b,'b');
				printlist(head_a,head_b);
			}
		}
		if (*head_a == NULL)
		{
			while ((*head_b)->val != maxb)
			{
				shiftup(head_b,'b');
				printlist(head_a,head_b);
			}
			while (*head_b != NULL)
			{
				push(head_b,head_a,'a');
				printlist(head_a,head_b);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	int		i;
	int		j;
	long tmp;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		tmp = ft_atoi(argv[i]);
		if (tmp > -2147483648 && tmp < 2147483647)
		{
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] == '-')
					j++;
				if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
					{
						ft_printf("Error\n");
						return (0);
					}
				j++;
			}
		}
		else
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}

	i = 1;
	while (argv[i] != NULL)
	{
		j = 1;
		while (argv[j + i] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j + i]))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}

	i = 1;
	while (argv[i] != NULL)
	{
		insert_tail(&head_a, ft_atoi(argv[i]));
		i++;
	}

	ft_printf("BEGGINING SORTING WITH THIS LIST \n");
	printlist(&head_a,&head_b);
	if (stacklen(head_a) == 2)
		sort_two(&head_a);
	else if (stacklen(head_a) == 3)
		sort_three(&head_a, stacklen(head_a));
	else if(stacklen(head_a) == 4 || stacklen(head_a) == 5)
		sort_small(&head_a, &head_b, stacklen(head_a));
	else
		sort_medium(&head_a,&head_b, stacklen(head_a));
	ft_printf("FINISHED SORTING LIST GRATZ \n");
	printlist(&head_a,&head_b);
	return (0);
}
