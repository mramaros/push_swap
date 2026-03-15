/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:12:34 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/11 15:54:33 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*algo_print(char strategy)
{
	if (strategy == 's')
		return ("n√n");
	else if (strategy == 'm')
		return ("O(n√n)");
	else if (strategy == 'c')
		return ("O(n log n)");
	return ("adaptive");
}

static char	*ft_print_strategy(char strategy)
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

void	bench_print(double disorder, char strategy)
{
	int	dis;
	int	front;
	int	back;

	dis = disorder * 10000;
	front = dis / 100;
	back = dis % 100;
	ft_printf("[bench] disorder:  %i.%i%%", front, back);
	ft_printf("[bench] strategy:  %s / %s\n", ft_print_strategy(strategy),
		algo_print(strategy));
	ft_printf("[bench] total_ops:\t%d\n", 42);
	ft_printf("[bench] sa:\t%d\tsb:\t%d\tss:\t%d\tpa:\t%d\n", 125, 45, 32, 45);
	ft_printf("[bench] ra:\t%d\trb:\t%d\trr:\t%d\trra:\t%d\t", 125, 15, 84, 32);
	ft_printf("rrb:\t%d\trrr:\t%d\n", 12, 32);
}
