/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@42antananarivo.mg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:12:34 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/18 10:43:04 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*algo_print(char strategy)
{
	if (strategy == 's' || strategy == 'S')
		return ("n^2");
	else if (strategy == 'm' || strategy == 'M')
		return ("O(n√n)");
	else if (strategy == 'c' || strategy == 'C')
		return ("O(n log n)");
	return ("adaptive");
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

static void	total_check(int	*tab)
{
	int	i;

	i = 1;
	while (i <= 11)
	{
		tab[12] += tab[i];
		i++;
	}
}

void	bench_print(double disorder, char strategy, int	*tab)
{
	total_check(tab);

	ft_printf("[bench] disorder:  %f%%\n", (disorder * 100));
	ft_printf("[bench] strategy:  %s / %s\n", ft_print_strategy(strategy),
		algo_print(strategy));
	ft_printf("[bench] total_ops:\t%d\n", tab[12]);
	ft_printf("[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\tpb:\t%d\n", tab[1], tab[2], tab[3], tab[4], tab[5]);
	ft_printf("[bench] ra:\t%d\trb:\t%d\trr:\t%d\trra:\t%d\t", tab[6], tab[7], tab[8], tab[9]);
	ft_printf("rrb:\t%d\trrr:\t%d\n", tab[10], tab[11]);
}

