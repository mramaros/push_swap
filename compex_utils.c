/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:32:42 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/18 17:33:54 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_loop(t_list **stack_a, t_list **stack_b, int *tab)
{
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
		tab[4]++;
	}
}
