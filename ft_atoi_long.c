/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:36:23 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/02 10:12:22 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

long	ft_atoi_long(const char *nptr)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (isspace(nptr[i]) == 1)
		i++;
	if (issign(nptr[i]) == 1)
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
