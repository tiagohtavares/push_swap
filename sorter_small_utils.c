/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_small_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:12:17 by ttavares          #+#    #+#             */
/*   Updated: 2023/03/23 16:24:37 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_pushto_a(t_stack **head_a, t_stack **head_b)
{
	int		maxa;
	int		mina;

	find_minmax(head_a, &maxa, &mina);
	while (*head_b != NULL)
	{
		if (*head_b != NULL)
			push_easy(head_a, head_b, &maxa, &mina);
		if (*head_b != NULL)
			push_middle(head_a, head_b, &maxa, &mina);
	}
}
