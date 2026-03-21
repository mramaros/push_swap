/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_for_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:20:28 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/21 18:46:01 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	char_f(int fd, double n)
{
	long	int_part;
	double	decimal;
	int		i;
	int		count;

	count = 0;
	int_part = (long)n;
	decimal = n - int_part;
	count += char_d(fd, int_part);
	count += char_c(fd, '.');
	if (decimal < 0)
		decimal = -decimal;
	i = 0;
	while (i < 2)
	{
		decimal *= 10;
		count += char_c(fd, (int)decimal + '0');
		decimal -= (int)decimal;
		i++;
	}
	return (count);
}
