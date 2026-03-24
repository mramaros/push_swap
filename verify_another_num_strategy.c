/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_another_num_strategy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:35:28 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/24 17:46:56 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verify_another_num_strategy(char **splits)
{
	int	j;

	j = 0;
	while (splits[j])
	{
		if (!is_int(splits[j]) && verify_commands(splits[j]) == '0'
			&& (ft_strncmp(splits[j], "--bench", 8)))
			lst_clear_parsing(splits, NULL);
		j++;
	}
}
