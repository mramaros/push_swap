/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:39:57 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/16 10:16:59 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_index(t_list **stack_a)
{
	int	index;
	int	index_min;
	int	min;

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

void	rotate_forward(t_list **stack_a, int cost_ra)
{
	int	i;

	i = 0;
	while (i < cost_ra)
	{
		rotate(stack_a);
		ft_printf("ra\n");
		i++;
	}
}

void	rotate_backward(t_list **stack_a, int cost_rra)
{
	int	i;

	i = 0;
	while (i < cost_rra)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
		i++;
	}
}

static void	int_min_max(t_list **stack_a, t_list **stack_b)
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
		rotate_forward(stack_a, index_min);
	else if (i < index_min)
		rotate_backward(stack_a, i);
	else
		rotate_forward(stack_a, index_min);
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

t_list	*simple(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
		int_min_max(stack_a, stack_b);
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	return (*stack_a);
}
