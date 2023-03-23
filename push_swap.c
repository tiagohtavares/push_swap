/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:18:35 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/23 15:42:50 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_size_filter(t_stack **head_a, t_stack **head_b)
{
	if (stacklen(*head_a) == 2)
		sort_two(head_a);
	else if (stacklen(*head_a) == 3)
		sort_three(head_a, stacklen(*head_a), 'a');
	else if (stacklen(*head_a) == 4 || stacklen(*head_a) == 5)
		sort_small(head_a, head_b, stacklen(*head_a));
	else if (stacklen(*head_a) > 5 && stacklen(*head_a) <= 200)
		sort_large(head_a, head_b, stacklen(*head_a), 5);
	else
		sort_large(head_a, head_b, stacklen(*head_a), 15);
}

int	one_argument_check(char **str, t_stack **head_a, t_stack **head_b)
{
	char	**argv;

	argv = ft_split(str[1], ' ');
	if (!check_range(argv))
	{
		argv_free(argv);
		return (0);
	}
	if (!check_char(argv))
	{
		argv_free(argv);
		return (0);
	}
	if (!check_doubles(argv))
	{
		argv_free(argv);
		return (0);
	}
	add_stack(argv, head_a);
	arg_size_filter(head_a, head_b);
	argv_free(argv);
	return (1);
}

int	argument_check(t_stack **head_a, t_stack **head_b, char **argv)
{
	argv++;
	if (!check_range(argv))
		return (0);
	if (!check_char(argv))
		return (0);
	if (!check_doubles(argv))
		return (0);
	add_stack(argv, head_a);
	arg_size_filter(head_a, head_b);
	return (1);
}

int	arg_sorter(int argc, char **argv, t_stack **head_a, t_stack **head_b)
{
	if (argc == 2)
	{
		if (!(one_argument_check(argv, head_a, head_b)))
		{
			clear(head_a, head_b);
			return (0);
		}
	}
	else
	{
		if (!(argument_check(head_a, head_b, argv)))
		{
			clear(head_a, head_b);
			return (0);
		}
	}
	clear(head_a, head_b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
	{
		clear(&head_a, &head_b);
		return (0);
	}
	else if (!(arg_sorter(argc, argv, &head_a, &head_b)))
	{
		clear(&head_a, &head_b);
		return (0);
	}
	return (0);
}
