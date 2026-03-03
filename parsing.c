/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:35:47 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/03 14:12:13 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	verify_commands(char *argv)
{
	char	command;

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
	else
		command = '0';
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
	// incrementation apres verification
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
