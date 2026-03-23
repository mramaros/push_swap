/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 06:18:29 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/23 12:50:33 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assing_index(t_list **stack_a)
{
	int	*result;
	int	size;

	size = ft_lstsize(*stack_a);
	result = stack_arway(stack_a, size);
	if (!result)
		error();
	sorting_index(result, 0, size - 1);
	assign_index(stack_a, result, size);
	free(result);
}

static void	do_push_or_rotate(t_list **stack_a, t_list **stack_b, t_chunk *c,
		int *tab)
{
	int	idx;

	idx = *(int *)(*stack_a)->index;
	if (idx >= c->min && idx <= c->max)
	{
		push(stack_a, stack_b);
		ft_printf(1, "pb\n");
		tab[5]++;
		c->pushed++;
	}
	else
	{
		rotate(stack_a);
		ft_printf(1, "ra\n");
		tab[6]++;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b, t_chunk *c, int *tab)
{
	while (c->pushed < c->needed)
	{
		if (ft_lstsize(*stack_a) == 0)
			break ;
		do_push_or_rotate(stack_a, stack_b, c, tab);
	}
}

int	find_index_in_b(t_list *stack_b, int target)
{
	int	pos;

	pos = 0;
	while (stack_b)
	{
		if (*(int *)stack_b->index == target)
			return (pos);
		pos++;
		stack_b = stack_b->next;
	}
	return (-1);
}

void	bring_to_top(t_list **stack_b, int pos, int size, int *tab)
{
	if (pos < 0)
		return ;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			rotate(stack_b);
			ft_printf(1, "rb\n");
			tab[7]++;
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			reverse_rotate(stack_b);
			ft_printf(1, "rrb\n");
			tab[10]++;
		}
	}
}
