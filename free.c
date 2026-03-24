/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:39:31 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/24 15:01:43 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear_parsing(char **splits, t_list **stack_a)
{
	int	i;

	i = 0;
	ft_lstclear(stack_a, free);
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
	error();
}

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

void	free_with_tab(char **splits, t_list **stack_a, int *tab)
{
	int	i;

	i = 0;
	ft_lstclear(stack_a, free);
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
	free(tab);
	exit(EXIT_SUCCESS);
}
