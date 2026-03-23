/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:35:47 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/23 17:38:05 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	verify_commands(char *argv)
{
	char	command;

	command = '0';
	if (ft_strcmp(argv, "--simple") == 0)
		command = 's';
	else if (ft_strcmp(argv, "--medium") == 0)
		command = 'm';
	else if (ft_strcmp(argv, "--complex") == 0)
		command = 'c';
	else if (ft_strcmp(argv, "--adaptive") == 0)
		command = 'a';
	return (command);
}

char	**parsing_all(char **argv)
{
	char	**splits;
	char	*temp;
	char	*new;
	int		i;

	if (!argv)
		error();
	i = 1;
	temp = ft_strdup("");
	while (argv[i])
	{
		new = ft_strjoin(temp, argv[i]);
		free(temp);
		temp = new;
		new = ft_strjoin(temp, " ");
		free(temp);
		temp = new;
		i++;
	}
	splits = ft_split(temp, ' ');
	free(temp);
	return (splits);
}

t_list	*parsing_num(char **splits)
{
	t_list	*stack_a;
	t_list	*number;
	int		i;

	stack_a = NULL;
	i = -1;
	while (splits[++i])
	{
		if (is_int(splits[i]))
		{
			number = ft_lstnew(int_convertion(splits[i], &stack_a, splits));
			if (!number)
				lst_clear(&stack_a, splits);
			number->index = NULL;
			ft_lstadd_back(&stack_a, number);
		}
	}
	if (duplicate(&stack_a))
		lst_clear_parsing(&stack_a, splits);
	return (stack_a);
}

char	parsing_strategy(char **argv)
{
	int		i;
	char	strategy;

	i = 0;
	strategy = 'a';
	while (argv[i] != NULL)
	{
		if (verify_commands(argv[i]) != '0')
		{
			strategy = verify_commands(argv[i]);
			return (strategy);
		}
		i++;
	}
	return (strategy);
}
