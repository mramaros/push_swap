/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:19:03 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/24 14:46:32 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_strategy(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (verify_commands(argv[i]) != '0')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**splits;

	if (argc < 2)
		return (0);
	splits = parsing_all(argv);
	if (!splits)
		error();
	if (check_strategy(splits))
	{
		free_splits_bonus(splits);
		error();
	}
	verify_another_num_strategy(splits);
	stack_a = parsing_num(splits);
	free_splits_bonus(splits);
	if (!stack_a)
		exit(EXIT_FAILURE);
	stack_b = NULL;
	checker(&stack_a, &stack_b);
}
