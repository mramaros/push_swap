/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@42antananarivo.mg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:12:34 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/06 17:38:10 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf/ft_printf.h"
#include "push_swap.h"
char *algo_print(char strategy);

void	bench_print(double disorder, char strategy)
{
	printf("[bench]\tdisorder:  %f%%\n", (disorder * 100));
	ft_printf("[bench]\tstrategy:  %s / %s\n", ft_print_strategy(strategy), algo_print(strategy));
	ft_printf("[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\n", 125, 45, 32, 45);
	ft_printf("[bench] ra:\t%d\trb:\t%d\trr:\t%d\trra:\t%d\trrb:\t%d\trrr:\t%d\n", 1254524, 45, 32, 45, 68, 54);
}

char *ft_print_strategy(char strategy)
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

char *algo_print(char strategy)
{
	if (strategy == 's')
		return ("O(n2)");
	else if (strategy == 'm')
		return ("O(n√n");
	else if (strategy == 'c')
		return ("O(n log n)");
	return ("adaptive");
}
