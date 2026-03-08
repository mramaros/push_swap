/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@42antananarivo.mg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:12:34 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/08 08:59:23 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

char	*algo_print(char strategy);

void	bench_print(double disorder, char strategy)
{
	printf("[bench] disorder:  %f%%\n", (disorder * 100));
	ft_printf("[bench] strategy:  %s / %s\n", ft_print_strategy(strategy),
		algo_print(strategy));
	ft_printf("[bench] total_ops:\t%d\n", 42);
	ft_printf("[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\n", 125, 45, 32, 45);
	ft_printf("[bench] ra:\t%d\trb:\t%d\trr:\t%d\trra:\t%d\t", 125, 15, 84, 32);
	ft_printf("rrb:\t%d\trrr:\t%d\n", 12, 32);
}

char	*ft_print_strategy(char strategy)
{
	if (strategy == 'a')
		return ("adaptive");
	else if (strategy == 's')
		return ("simple");
	else if (strategy == 'm')
		return ("medium");
	else if (strategy == 'c')
		return ("comlex");
	return ("adaptive");
}

char	*algo_print(char strategy)
{
	if (strategy == 's')
		return ("n√n");
	else if (strategy == 'm')
		return ("O(n√n)");
	else if (strategy == 'c')
		return ("O(n log n)");
	return ("adaptive");
}
