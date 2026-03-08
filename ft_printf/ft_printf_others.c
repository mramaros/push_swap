/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:04:46 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/08 08:36:22 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	char_u(unsigned int n)
{
	char	*str;
	size_t	str_len;

	str = ft_ltoa(n);
	str_len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (str_len);
}

size_t	char_x(unsigned int n, char c)
{
	char	*res;
	size_t	res_len;

	res = ft_hex(n, c);
	res_len = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (res_len);
}
