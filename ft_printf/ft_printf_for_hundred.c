/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_for_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:20:28 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/11 21:22:02 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	char_f(double n)
{
	long	int_part;
	double	decimal;
	int		i;
	int		count;

	count = 0;
	int_part = (long)n;
	decimal = n - int_part;

	count += char_d(int_part);
	count += char_c('.');

	if (decimal < 0)
		decimal = -decimal;

	i = 0;
	while (i < 6)
	{
		decimal *= 10;
		count += char_c((int)decimal + '0');
		decimal -= (int)decimal;
		i++;
	}
	return (count);
}
