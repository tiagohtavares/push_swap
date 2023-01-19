/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:18:35 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/19 15:53:10 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct a_list {
	int	val;
	struct a_list * next;
} a_list_t;

typedef struct b_list {
	int val;
	struct b_list * next;
}b_list_t;

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		return (0);
	if (argc != 2)
	{
		ft_printf("Error\n");
	}
	return (0);
}
