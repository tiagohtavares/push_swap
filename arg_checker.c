/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:33:45 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/17 17:42:54 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
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
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	long	signal;
	long	res;

	i = 0;
	signal = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		signal = -1;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * signal);
}

int	check_range(char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (argv[i] != NULL)
	{
		tmp = ft_atol(argv[i]);
		if (!(tmp > -2147483648 && tmp < 2147483647))
		{
			ft_printf("Error\n");
			return (0);
		}
	i++;
	}
	return (1);
}

int	check_doubles(char **argv)
{
	int	i;
	int	j;

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
	return (1);
}

void	add_stack(char **argv, t_stack **head_a)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		insert_tail(head_a, ft_atoi(argv[i]));
		i++;
	}
}
