/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@42antananarivo.mg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:12:34 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/06 14:31:27 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
char *algo_print(char strategy);

void	bench_print(double disorder, t_list	*a, char strategy)
{
	printf("[bench]\tdisorder:  %f%%\n", disorder);
	ft_printf("[bench]\tstrategy:  %s / %s", ft_print_strategy(strategy), algo_print(strategy));
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
