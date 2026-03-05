/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:35:47 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/05 06:42:11 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	verify_commands(char *argv)
{
	char	command;

	command = '0';
	if (ft_strncmp(argv, "--simple", 8) == 0)
		command = 's';
	else if (ft_strncmp(argv, "--medium", 8) == 0)
		command = 'm';
	else if (ft_strncmp(argv, "--complex", 9) == 0)
		command = 'c';
	else if (ft_strncmp(argv, "--adaptive", 10) == 0)
		command = 'a';
	else if (ft_strncmp(argv, "--bench", 7) == 0)
		command = 'b';
	return (command);
}

char	***parsing_all(int argc, char **argv)
{
	char	***splits;
	char	**res;
	int		i;
	int		j;

	if (!argc || !argv)
		return (NULL);
	i = 1;
	j = 0;
	// size of argv
	splits = (char ***)malloc((argc) * sizeof(char **));
	if (!splits)
		return (NULL);
	while (argv[i])
	{
		res = ft_split(argv[i], ' ');
		splits[j] = res;
		i++;
		j++;
	}
	splits[j] = NULL;
	return (splits);
}

t_list	*parsing_num(char ***splits)
{
	t_list	*stack_a;
	int		i;
	int		j;
	t_list	*number;

	stack_a = NULL;
	i = -1;
	while (splits[++i])
	{
		j = 0;
		while (splits[i][j])
		{
			if (is_int(splits[i][j]))
			{
				number = ft_lstnew(int_convertion(splits[i][j]));
				if (!number)
					lst_clear(&stack_a);
				ft_lstadd_back(&stack_a, number);
			}
			j++;
		}
	}
	if (duplicate(&stack_a))
		lst_clear(&stack_a);
	return (stack_a);
}

char	parsing_strategy(char ***argv)
{
	int		i;
	int		j;
	char	res;

	i = 0;
	while (argv && argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			res = verify_commands(argv[i][j]);
			if (res != '0')
				return (res);
			j++;
		}
		i++;
	}
	return ('a');
}
