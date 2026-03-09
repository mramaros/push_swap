/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:39:57 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/09 17:05:50 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

int min_index(t_list **stack_a)
{
	int index;
	int index_min;
	int min;

	index = -1;
	min = *(int *)(*stack_a)->content;
	while (*stack_a != NULL)
	{
		index++;
		if (*(int *)(*stack_a)->content < min)
		{
			min = *(int *)(*stack_a)->content;
			index_min = index;
		}
		*stack_a = (*stack_a)->next;
	}
	return (index_min);
}

t_list	*int_min_max(t_list **stack_a, t_list **stack_b)
{
	int index_min;
	int size;
	int i;
	int j;

	index_min = min_index(stack_a);
	size = ft_lstsize(*stack_a);
	i = size - index_min;
	if (index_min < i)
	{
		j = 0;
		while (j < index_min)
		{
			rotate(stack_a);
			j++;
		}
	}
	else if (i < index_min)
	{
		j = 0;
		while (j < i)
		{
			reverse_rotate(stack_a);
			j++;
		}
	}
	push(stack_a, stack_b);
	return (*stack_b);
}

