/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:39:57 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/19 11:23:47 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_list **stack_a)
{
	int	index;
	int	index_min;
	int	min;

	index = -1;
	index_min = 0;
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

void	rotate_forward_to_min(t_list **stack_a, int cost_ra, int *tab)
{
	int	i;

	i = 0;
	while (i < cost_ra)
	{
		rotate(stack_a);
		tab[6]++;
		ft_printf("ra\n");
		i++;
	}
}

void	rotate_backward_to_min(t_list **stack_a, int cost_rra, int *tab)
{
	int	i;

	i = 0;
	while (i < cost_rra)
	{
		reverse_rotate(stack_a);
		tab[9]++;
		ft_printf("rra\n");
		i++;
	}
}

static void	int_min_max(t_list **stack_a, t_list **stack_b, int *tab)
{
	int		index_min;
	int		size;
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	index_min = min_index(&tmp);
	size = ft_lstsize(*stack_a);
	i = size - index_min;
	if (index_min < i)
		rotate_forward_to_min(stack_a, index_min, tab);
	else if (i < index_min)
		rotate_backward_to_min(stack_a, i, tab);
	else
		rotate_forward_to_min(stack_a, index_min, tab);
	push(stack_a, stack_b);
	tab[5]++;
	ft_printf("pb\n");
}

t_list	*simple(t_list **stack_a, t_list **stack_b, int *tab)
{
	while (*stack_a)
		int_min_max(stack_a, stack_b, tab);
	while (*stack_b)
	{
		push(stack_b, stack_a);
		tab[4]++;
		ft_printf("pa\n");
	}
	return (*stack_a);
}
