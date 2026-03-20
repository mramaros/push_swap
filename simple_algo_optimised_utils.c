/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo_optimised_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:35:01 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/20 20:15:13 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
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

void	push_and_rotate(t_list **stack_a, t_list **stack_b, int *tab)
{
	rotate(stack_a);
	ft_printf(1, "ra\n");
	tab[6]++;
	push(stack_b, stack_a);
	ft_printf(1, "pa\n");
	tab[4]++;
}

void	reverse_rotate_and_swap(t_list **stack_a, int *tab)
{
	reverse_rotate(stack_a);
	ft_printf(1, "rra\n");
	tab[6]++;
	swap(stack_a);
	ft_printf(1, "sa\n");
	tab[1]++;
}
