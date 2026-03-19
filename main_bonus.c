/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:19:03 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/19 16:33:17 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_splits_bonus(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
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
	verify_another_num_strategy(splits);
	stack_a = parsing_num(splits);
	if (parsing_strategy(splits))
		error();
	stack_b = NULL;
	if (!stack_a)
	{
		free_splits_bonus(splits);
		exit(EXIT_FAILURE);
	}
	checker(&stack_a, &stack_b);
}
