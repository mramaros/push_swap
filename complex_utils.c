/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:32:42 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/19 14:25:23 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_loop(t_list **stack_a, t_list **stack_b, int *tab)
{
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf(1, "pa\n");
		tab[4]++;
	}
}
