/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:08:45 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/12 13:08:24 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (s1[i] && i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
