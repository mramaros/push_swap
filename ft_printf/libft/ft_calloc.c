/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:21:17 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/12 11:50:30 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total;

	total = nmemb * size;
	if (nmemb && size != (total / nmemb))
		return (NULL);
	ptr = (unsigned char *)malloc(nmemb * size);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, 0, total);
	return ((void *)ptr);
}
