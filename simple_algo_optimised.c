/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo_optimised.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:21:56 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/21 18:42:22 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static void	sort_three(t_list **stack_a, int *tab)
{
	double		disorder;
	int			min;
	t_list		*tmp;

	disorder = compute_disorder(*stack_a);
	tmp = *stack_a;
	min = min_index(&tmp);
	while (disorder != 0.0 && min != 0)
	{
		reverse_rotate(stack_a);
		ft_printf(1, "rra\n");
		tab[9]++;
		disorder = compute_disorder(*stack_a);
		tmp = *stack_a;
		min = min_index(&tmp);
	}
	disorder = compute_disorder(*stack_a);
	if (disorder != 0.0)
	{
		reverse_rotate_and_swap(stack_a, tab);
	}
}

static void	sort_stack_b(t_list **stack_b, int *tab)
{
	if (ft_lstsize(*stack_b) < 2)
		return ;
	if (*(int *)(*stack_b)->content < *(int *)(*stack_b)->next->content)
	{
		rotate(stack_b);
		ft_printf(1, "rb\n");
		tab[7]++;
	}
}

static void	sort_five(t_list **stack_a, t_list **stack_b, int *tab)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		push(stack_a, stack_b);
		ft_printf(1, "pb\n");
		tab[5]++;
	}
	sort_three(stack_a, tab);
	while (*stack_b)
	{
		sort_stack_b(stack_b, tab);
		if (max_value(*stack_a) < *(int *)(*stack_b)->content)
		{
			push(stack_b, stack_a);
			ft_printf(1, "pa\n");
			tab[4]++;
			rotate(stack_a);
			ft_printf(1, "ra\n");
			tab[6]++;
		}
		else
			check_content(stack_a, stack_b, tab);
	}
}

void	simple_algo_optimised(t_list **stack_a, t_list **stack_b, int *tab)
{
	if (ft_lstsize(*stack_a) == 2)
		simple(stack_a, stack_b, tab);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a, tab);
	else if (ft_lstsize(*stack_a) == 4)
		simple(stack_a, stack_b, tab);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b, tab);
}
