/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_index_assignment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:58:13 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/19 11:23:28 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arway, int min, int max)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arway[max];
	i = min - 1;
	j = min;
	while (j < max)
	{
		if (arway[j] <= pivot)
		{
			i++;
			swap_arway(&arway[i], &arway[j]);
		}
		j++;
	}
	swap_arway(&arway[i + 1], &arway[max]);
	return (i + 1);
}

void	sorting_index(int *tab, int min, int max)
{
	int	i;

	if (min < max)
	{
		i = partition(tab, min, max);
		sorting_index(tab, min, i - 1);
		sorting_index(tab, i + 1, max);
	}
}

int	find_index(int *arway, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arway[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_index(t_list **stack_a, int *arway, int size)
{
	t_list	*tmp;
	int		idx;

	tmp = *stack_a;
	while (tmp)
	{
		idx = find_index(arway, size, *(int *)tmp->content);
		free(tmp->index);
		tmp->index = malloc(sizeof(int));
		if (!tmp->index)
			return ;
		*(int *)tmp->index = idx;
		tmp = tmp->next;
	}
}
