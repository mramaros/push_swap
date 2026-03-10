/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:39:57 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/10 12:39:07 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

int	min_index(t_list **stack_a)
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

void	int_min_max(t_list **stack_a, t_list **stack_b)
{
	int		index_min;
	int		size;
	int		i;
	int		j;
	t_list	*tmp;

	tmp = *stack_a;
	index_min = min_index(&tmp);
	size = ft_lstsize(*stack_a);
	i = size - index_min;
	if (index_min < i)
	{
		j = 0;
		while (j < index_min)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			j++;
		}
	}
	else if (i < index_min)
	{
		j = 0;
		while (j < i)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			j++;
		}
	}
	else
	{
		j = 0;
		while (j < index_min)
		{
			rotate(stack_a);
			ft_printf("ra\n");
			j++;
		}
	}
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

t_list	*simple(t_list **stack_a, t_list **stack_b)
{
	// int	size_a;
	// int	size_b;
	// size_a = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		int_min_max(stack_a, stack_b);
		// size_a = ft_lstsize(*stack_a);
	}
	// size_b = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
		// size_b = ft_lstsize(*stack_b);
	}
	return (*stack_a);
}
