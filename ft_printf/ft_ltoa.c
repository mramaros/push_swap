/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:44:21 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/25 23:15:29 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	malloc_size(long n)
{
	int	res;

	res = 0;
	while (n != 0)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

static char	*is_negative(long n)
{
	char	*res;
	int		size;

	if (n == 0)
	{
		res = malloc(2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	n = -n;
	size = malloc_size(n);
	res = malloc(size + 2);
	if (!res)
		return (NULL);
	res[0] = '-';
	res[size + 1] = '\0';
	while (n != 0)
	{
		res[size--] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}

char	*ft_ltoa(long nbr)
{
	char	*res;
	int		size;
	int		len;

	size = malloc_size(nbr);
	len = size - 1;
	if (nbr <= 0)
	{
		res = is_negative(nbr);
		return (res);
	}
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	while (nbr != 0)
	{
		res[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	res[size] = '\0';
	return (res);
}
