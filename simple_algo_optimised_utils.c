/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo_optimised_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:35:01 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/23 13:25:15 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_list *stack_a)
{
	int	max;

	if (!stack_a)
		return (0);
	max = *(int *)stack_a->content;
	while (stack_a)
	{
		if (*(int *)stack_a->content > max)
			max = *(int *)stack_a->content;
		stack_a = stack_a->next;
	}
	return (max);
}

void	check_content(t_list **stack_a, t_list **stack_b, int *tab)
{
	int	i;

	i = 0;
	while (*(int *)(*stack_a)->content < *(int *)(*stack_b)->content)
	{
		rotate(stack_a);
		ft_printf(1, "ra\n");
		tab[6]++;
		i++;
	}
	push(stack_b, stack_a);
	ft_printf(1, "pa\n");
	tab[4]++;
	while (compute_disorder(*stack_a) != 0.0 && i >= 0)
	{
		reverse_rotate(stack_a);
		ft_printf(1, "rra\n");
		tab[9]++;
		i--;
	}
}

void	reverse_rotate_and_swap(t_list **stack_a, int *tab)
{
	reverse_rotate(stack_a);
	ft_printf(1, "rra\n");
	tab[9]++;
	swap(stack_a);
	ft_printf(1, "sa\n");
	tab[1]++;
}
