/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:20:27 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/16 10:14:19 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_splits(char **splits)
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
	char	strategy;
	double	disorder;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	splits = parsing_all(argc, argv);
	if (!splits)
		error();
	verify_another_num_strategy(splits);
	stack_a = parsing_num(splits);
	strategy = parsing_strategy(splits);
	disorder = compute_disorder(stack_a);
	if (!disorder)
		return (0);
	if (strategy == 's')
		stack_a = simple(&stack_a, &stack_b);
	if (strategy == 'c')
		stack_a = radix(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
		ft_printf("%i ", *(int *)(stack_a)->content);
		stack_a = stack_a->next;
	}
	// bench_print(disorder, strategy);
	// ft_printf("\n%c", strategy);
	ft_lstclear(&stack_a, free);
	free_splits(splits);
}
