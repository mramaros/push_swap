/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:41:59 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/12 13:47:25 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	unsigned const char	*ptr_src;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	if (dest > src)
	{
		while (n--)
			ptr_dest[n] = ptr_src[n];
	}
	else
	{
		while (n--)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}
