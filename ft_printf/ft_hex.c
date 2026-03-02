/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:51:22 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/26 12:30:55 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	malloc_size(unsigned long n)
{
	unsigned long	res;

	res = 0;
	while (n != 0)
	{
		res++;
		n = n / 16;
	}
	return (res);
}

static char	*hex_0(void)
{
	char	*res;

	res = (char *)malloc(2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_hex(unsigned long n, char c)
{
	char	*res;
	char	*hex;
	int		size;
	int		len;

	if (n == 0)
		return (hex_0());
	size = malloc_size(n);
	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	len = size - 1;
	while (n != 0)
	{
		res[len--] = hex[n % 16];
		n = n / 16;
	}
	res[size] = '\0';
	return (res);
}
