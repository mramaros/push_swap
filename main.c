/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:20:27 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/09 13:55:22 by ialrandr         ###   ########.fr       */
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
	char	**splits;
	char	strategy;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	splits = parsing_all(argc, argv);
	if (!splits)
		error();
	stack_a = parsing_num(splits);
	free_splits(splits);
	strategy = parsing_strategy(argv);
	if (!strategy)
		strategy = 'a';
	while (stack_a != NULL)
	{
		ft_printf("%i ", *(int *)(stack_a)->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n%c", strategy);
	ft_lstclear(&stack_a, free);
}
