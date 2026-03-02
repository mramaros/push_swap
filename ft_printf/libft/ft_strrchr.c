/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:41:50 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/12 13:45:50 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (NULL);
	c = (unsigned char)c;
	len = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)(s + len));
	len = len - 1;
	while (len > 0 && s[len])
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	if (s[len] && s[len] == c)
		return ((char *)s + len);
	return (NULL);
}
