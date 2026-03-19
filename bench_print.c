/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@42antananarivo.mg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:12:34 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/19 14:31:12 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*algo_print(char strategy)
{
	if (strategy == 's' || strategy == 'S')
		return ("O n^2");
	else if (strategy == 'm' || strategy == 'M')
		return ("O(n√n)");
	else if (strategy == 'c' || strategy == 'C')
		return ("O(n log n)");
	return ("adaptive");
}

char	*ft_print_strategy(char strategy)
{
	if (strategy == 'a')
		return ("Adaptive");
	else if (strategy == 's')
		return ("Simple");
	else if (strategy == 'm')
		return ("Medium");
	else if (strategy == 'c')
		return ("Complex");
	return ("Adaptive");
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
	ft_printf(2, "[bench] disorder:  %f%%\n", (disorder * 100));
	ft_printf(2, "[bench] strategy:  %s / %s\n", ft_print_strategy(strategy),
		algo_print(strategy));
	ft_printf(2, "[bench] total_ops:\t%d\n", tab[12]);
	ft_printf(2, "[bench] sa:\t%d\tsb:\t%d\tss:\t%d\t", tab[1], tab[2], tab[3]);
	ft_printf(2, "pa:\t%d\t", tab[4]);
	ft_printf(2, "pb:\t%d\n", tab[5]);
	ft_printf(2, "[bench] ra:\t%d\trb:\t%d\trr:\t%d\t", tab[6], tab[7], tab[8]);
	ft_printf(2, "rra:\t%d\t", tab[9]);
	ft_printf(2, "rrb:\t%d\trrr:\t%d\n", tab[10], tab[11]);
}
