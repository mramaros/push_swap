/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:18:39 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/19 14:25:36 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_list **stack_a, t_list **stack_b, int *tab)
{
	int	size;
	int	target;
	int	pos;

	size = ft_lstsize(*stack_b);
	target = size - 1;
	while (*stack_b)
	{
		pos = find_index_in_b(*stack_b, target);
		bring_to_top(stack_b, pos, size, tab);
		push(stack_b, stack_a);
		ft_printf(1, "pa\n");
		tab[4]++;
		size--;
		target--;
	}
}

void	push_all_to_b(t_list **stack_a, t_list **stack_b, int *tab)
{
	int		total;
	int		chunk_size;
	int		chunk;
	t_chunk	c;

	total = ft_lstsize(*stack_a);
	chunk_size = ft_sqrt(total);
	chunk = 0;
	while (chunk * chunk_size < total)
	{
		c.min = chunk * chunk_size;
		c.max = c.min + chunk_size - 1;
		if (c.max >= total)
			c.max = total - 1;
		c.needed = c.max - c.min + 1;
		c.pushed = 0;
		push_to_b(stack_a, stack_b, &c, tab);
		chunk++;
	}
}

void	medium_algo(t_list **stack_a, t_list **stack_b, int *tab)
{
	assing_index(stack_a);
	push_all_to_b(stack_a, stack_b, tab);
	push_back_to_a(stack_a, stack_b, tab);
}
