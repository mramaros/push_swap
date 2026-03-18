/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:20:27 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/18 10:47:26 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splits(char **splits)
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
	char	**splits;
	double	disorder;
	char	strategy;
	int		result_bench;
	t_list	*stack_b;
	int		tab[13];

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	tab_content(tab);
	splits = parsing_all(argv);
	if (!splits)
	{
		free_splits(splits);
		error();
	}
	verify_another_num_strategy(splits);
	stack_a = parsing_num(splits);
	if (!stack_a)
		free_splits(splits);
	disorder = compute_disorder(stack_a);
	strategy = parsing_strategy(splits);
	if (strategy == 's' && disorder != 0)
		simple(&stack_a, &stack_b, tab);
	else if (strategy == 'm' && disorder != 0)
		medium_algo(&stack_a, &stack_b, tab);
	else if (strategy == 'c' && disorder != 0)
		complex(&stack_a, &stack_b, tab);
	else if (strategy == 'a'&& disorder != 0)
		strategy = adaptive_algo(&stack_a, &stack_b, disorder, tab);
	result_bench = search_bench(splits);
	if (result_bench == 1)
		bench_print(disorder, strategy, tab);
	ft_lstclear(&stack_a, free);
	free_splits(splits);
}
