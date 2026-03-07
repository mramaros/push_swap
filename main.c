/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:20:27 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/07 22:47:38 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	free_splits(char ***splits)
{
	int	i;
	int	j;

	i = 0;
	while (splits[i])
	{
		j = 0;
		while (splits[i][j])
		{
			free(splits[i][j]);
			j++;
		}
		free(splits[i]);
		i++;
	}
	free(splits);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	char	***splits;
	double	disorder;
	char	strategy;
	int		result_bench;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	splits = parsing_all(argc, argv);
	if (!splits)
		error();
	verify_another_num_strategy(splits);
	stack_a = parsing_num(splits);
	if (!stack_a)
		free_splits(splits);
	disorder = compute_disorder(stack_a);
	strategy = parsing_strategy(splits);
	result_bench = search_bench(splits);
	if (result_bench == 1)
		bench_print(disorder, strategy);
	ft_lstclear(&stack_a, free);
	free_splits(splits);
}
