/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:20:27 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/23 14:09:30 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splits(char **splits, t_list **stack_a)
{
	int	i;
	int	*tab;

	i = 0;
	tab = ft_calloc(13, sizeof(int));
	if (search_bench(splits) == 1 && !*stack_a)
		bench_print(0, 'a', tab);
	ft_lstclear(stack_a, free);
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
	free(tab);
	exit(EXIT_FAILURE);
}

static void	push_swap(t_list **stack_a, t_list **stack_b, char strategy,
		char **splits)
{
	double	disorder;
	int		*tab;

	tab = ft_calloc(13, sizeof(int));
	disorder = compute_disorder(*stack_a);
	if (disorder == 0 && search_bench(splits) == 1)
	{
		bench_print(disorder, strategy, tab);
		return ;
	}
	else if (disorder == 0)
		return ;
	if (strategy == 's')
		simple(stack_a, stack_b, tab);
	else if (strategy == 'm')
		medium_algo(stack_a, stack_b, tab);
	else if (strategy == 'c')
		complex(stack_a, stack_b, tab);
	else if (strategy == 'a')
		strategy = adaptive_algo(stack_a, stack_b, disorder, tab);
	if (search_bench(splits) == 1)
		bench_print(disorder, strategy, tab);
	free(tab);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**splits;
	char	strategy;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	splits = parsing_all(argv);
	if (!splits)
		error();
	verify_another_num_strategy(splits);
	stack_a = parsing_num(splits);
	if (!stack_a)
		free_splits(splits, &stack_a);
	strategy = parsing_strategy(splits);
	push_swap(&stack_a, &stack_b, strategy, splits);
	free_splits(splits, &stack_a);
}
