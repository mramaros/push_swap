/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_bench.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:24:35 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/19 11:24:05 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_bench(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			return (1);
		i++;
	}
	return (0);
}
