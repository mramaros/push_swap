/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:33:02 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/19 08:44:53 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	character_check(int fd, int c, va_list ap)
{
	if (c == 'c')
		return (char_c(fd, (char)(va_arg(ap, unsigned int))));
	if (c == 's')
		return (char_s(fd, va_arg(ap, char *)));
	if (c == 'p')
		return (char_p(fd, (unsigned long)(va_arg(ap, void *))));
	if (c == 'd' || c == 'i')
		return (char_d(fd, va_arg(ap, int)));
	if (c == 'u')
		return (char_u(va_arg(ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (char_x(va_arg(ap, unsigned int), c));
	if (c == '%')
		return (char_c(fd, c));
	if (c == 'f')
		return (char_f(fd, va_arg(ap, double)));

	return (0);
}

size_t	char_c(int fd, char c)
{
	ft_putchar_fd(c, fd);
	return (1);
}

size_t	char_s(int fd, char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

size_t	char_p(int fd, unsigned long n)
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
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(hex_value, fd);
	free(hex_value);
	return (hex_len + 2);
}

size_t	char_d(int fd, int num)
{
	char	*str;
	long	n;
	size_t	str_len;

	n = num;
	str = ft_ltoa(n);
	str_len = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (str_len);
}
