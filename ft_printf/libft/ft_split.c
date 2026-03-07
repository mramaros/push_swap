/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:07:17 by mramaros          #+#    #+#             */
/*   Updated: 2026/02/04 10:18:34 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_word(const char	*s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (k);
}

static char	*get_word(const char	*s, char c, int *i)
{
	char	*str;
	int		start;
	int		k;
	int		len;

	k = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	start = (*i);
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	len = (*i) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (k < len)
	{
		str[k] = s[start + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

static void	free_tab(char **tab, int j)
{
	while (j >= 0)
	{
		free (tab[j]);
		j--;
	}
	free (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		count;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	count = count_word(s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (j < count)
	{
		tab[j] = get_word(s, c, &i);
		if (!tab[j])
		{
			free_tab(tab, j);
			return (NULL);
		}
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
