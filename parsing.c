/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:35:47 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/03 07:55:01 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	verify_parsing(char *argv)
{
	char	strategy;

	if (ft_strncmp(argv, "--simple", 8) == 0)
		strategy = 's';
	else if (ft_strncmp(argv, "--medium", 8) == 0)
		strategy = 'm';
	else if (ft_strncmp(argv, "--complex", 9) == 0)
		strategy = 'c';
	else if (ft_strncmp(argv, "--adaptive", 10) == 0)
		strategy = 'a';
	else
	 	strategy = '0';
	return (strategy);
}

t_list	*parsing_num(char **argv)
{
	t_list	*stack_a;
	t_list	*number;
	int		i;

	if (!argv)
		error();
	stack_a = NULL;
	number = NULL;
	i = 0;
	while (argv[i])
	{
		if (verify_parsing(argv[i]) != '0' && argv[i + 1])
			i++;
		if (verify_parsing(argv[i]) != '0' && !argv[i + 1])
			break;
		number = ft_lstnew(int_convertion(argv[i]));
		if (!number)
			lst_clear(&stack_a);
		ft_lstadd_back(&stack_a, number);
		i++;
	}
	if (duplicate(&stack_a))
		lst_clear(&stack_a);
	return (stack_a);
}

char	parsing_strategy(char **argv)
{
	char	strategy;
	int		i;

	if (!argv)
		return (0);
	i = 0;
	strategy = 'a';
	while (argv[i] && is_int(argv[i]))
		i++;
	if (ft_strncmp(argv[i], "--simple", 8) == 0)
		strategy = 's';
	else if (ft_strncmp(argv[i], "--medium", 8) == 0)
		strategy = 'm';
	else if (ft_strncmp(argv[i], "--complex", 9) == 0)
		strategy = 'c';
	else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
		strategy = 'a';
	return (strategy);
}
