/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:20:35 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/12 13:51:37 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	int		res;

	if (!big && !len)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	little_len = ft_strlen((char *)little);
	while (i < len && big[i] && little[0] != big[i])
		i++;
	if (i == len)
		return (NULL);
	while (i + little_len <= len && big[i])
	{
		res = ft_strncmp(little, big + i, little_len);
		if (res == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
