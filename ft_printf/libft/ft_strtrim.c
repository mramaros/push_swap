/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:24:46 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/12 13:23:18 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	find(char const *str, char const *set, int str_start)
{
	int	res;

	if (str_start == 0)
	{
		res = 0;
		while (str[str_start] && inset(str[str_start], set) == 1)
		{
			res++;
			str_start++;
		}
		return (res);
	}
	else if (str_start != 0)
	{
		res = str_start;
		while (str[str_start] && inset(str[str_start], set) == 1)
		{
			res--;
			str_start--;
		}
		return (res);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = find(s1, set, 0);
	end = find(s1, set, ft_strlen((char *)s1) - 1);
	if (start > end)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	str = malloc((end - start) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
