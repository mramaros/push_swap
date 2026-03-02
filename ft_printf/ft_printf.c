/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:57:21 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/26 11:58:42 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	print_len;

	if (!str)
		return (-1);
	print_len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print_len = print_len + character_check(*str, ap);
		}
		else
		{
			write(1, str, 1);
			print_len++;
		}
		str++;
	}
	va_end(ap);
	return ((int)print_len);
}
