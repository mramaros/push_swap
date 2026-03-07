/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_another_num_strategy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@42antananarivo.mg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:35:28 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/07 22:57:11 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verify_another_num_strategy(char ***splits)
{
	int	i;
	int	j;

	i = 0;
	while (splits[i])
	{
		j = 0;
		while (splits[i][j])
		{
			if (!is_int(splits[i][j]) && verify_commands(splits[i][j]) == '0' &&
					(ft_strncmp(splits[i][j], "--bench", 8)))
				error();
			j++;
		}
		i++;
	}
}
