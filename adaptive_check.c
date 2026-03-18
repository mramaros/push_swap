/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:05:14 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/18 10:40:50 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	adaptive_algo(t_list **stack_a, t_list **stack_b, double disorder, int *tab)
{
	char	strategy;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size < 5 || disorder < 0.2)
	{
		simple(stack_a, stack_b, tab);
		strategy = 'S';
	}
	else if ((size > 5 && size <= 100)
			|| (disorder >= 0.2 && disorder <= 0.5))
	{
		medium_algo(stack_a, stack_b, tab);
		strategy = 'M';
	}
	else
	{
	 	complex(stack_a, stack_b, tab);
		strategy = 'C';
	}
	return (strategy);
}
