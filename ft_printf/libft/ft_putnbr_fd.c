/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:55:38 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/12 11:10:15 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*c;

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		c = ft_itoa(n);
		if (!c)
			return ;
		ft_putstr_fd(c, fd);
		free(c);
	}
}
