/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 09:05:19 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/12 13:04:59 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	strlen;
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	strlen = ft_strlen((char *)s);
	dup = malloc(strlen + 1);
	if (dup == 0)
		return (NULL);
	i = 0;
	while (s[i] && i < strlen)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
