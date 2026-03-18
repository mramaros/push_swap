/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:50:55 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/25 17:02:51 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char *str, char c)
{
	int	words;
	int	i;
	int	inword;

	if (!str || !c)
		return (0);
	words = 0;
	i = 0;
	inword = 0;
	while (str[i])
	{
		if (str[i] != c && !inword)
		{
			inword = 1;
			words++;
		}
		else if (str[i] == c)
			inword = 0;
		i++;
	}
	return (words);
}

static char	*find(char *s, char c)
{
	char	*res;
	int		i;
	int		j;
	int		lenght;

	i = 0;
	lenght = 0;
	while (s[i] && s[i] != c)
	{
		lenght++;
		i++;
	}
	i = 0;
	res = malloc(lenght + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (j < lenght)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}

static void	array_free(char **s, int index)
{
	while (index > 0)
		free(s[--index]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	words;

	i = 0;
	j = 0;
	words = countwords((char *)s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < words && s[j])
	{
		while (s[j] == c && s[j])
			j++;
		res[i] = find((char *)s + j, c);
		if (!res[i])
		{
			array_free(res, i);
			return (NULL);
		}
		j = j + (ft_strlen(res[i++]));
	}
	res[i] = NULL;
	return (res);
}
