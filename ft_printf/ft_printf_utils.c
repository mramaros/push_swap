/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:33:02 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/26 12:27:42 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	character_check(int c, va_list ap)
{
	if (c == 'c')
		return (char_c((char)(va_arg(ap, unsigned int))));
	if (c == 's')
		return (char_s(va_arg(ap, char *)));
	if (c == 'p')
		return (char_p((unsigned long)(va_arg(ap, void *))));
	if (c == 'd' || c == 'i')
		return (char_d(va_arg(ap, int)));
	if (c == 'u')
		return (char_u(va_arg(ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (char_x(va_arg(ap, unsigned int), c));
	if (c == '%')
		return (char_c(c));
	return (0);
}

size_t	char_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	char_s(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	char_p(unsigned long n)
{
	char	*hex_value;
	size_t	hex_len;

	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	hex_value = ft_hex(n, 'x');
	hex_len = ft_strlen(hex_value);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex_value, 1);
	free(hex_value);
	return (hex_len + 2);
}

size_t	char_d(int num)
{
	char	*str;
	long	n;
	size_t	str_len;

	n = num;
	str = ft_ltoa(n);
	str_len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (str_len);
}
