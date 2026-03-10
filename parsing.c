/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:35:47 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/10 16:51:27 by ialrandr         ###   ########.fr       */
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

char	**parsing_all(int argc, char **argv)
{
	char	**splits;
	char	*temp;
	int		i;

	if (!argc || !argv)
		error();
	i = 1;
	temp = "";
	while (argv[i])
	{
		temp = ft_strjoin(temp, argv[i]);
		temp = ft_strjoin(temp, " ");
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
	i = 0;
	while (splits[i])
	{
		if (is_int(splits[i]))
		{
			number = ft_lstnew(int_convertion(splits[i]));
			if (!number)
				lst_clear(&stack_a);
			ft_lstadd_back(&stack_a, number);
		}
		i++;
	}
	if (duplicate(&stack_a))
		lst_clear(&stack_a);
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
