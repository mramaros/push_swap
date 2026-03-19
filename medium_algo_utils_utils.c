/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_utils_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:35:04 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/16 23:27:58 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

void	swap_arway(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*stack_arway(t_list **stack_a, int size)
{
	int		*arway;
	t_list	*tmp;
	int		i;

	i = 0;
	arway = malloc(sizeof(int) * (size + 1));
	if (!arway)
		return (NULL);
	tmp = *stack_a;
	while (tmp)
	{
		arway[i] = *(int *)tmp->content;
		i++;
		tmp = tmp->next;
	}
	arway[i] = 0;
	return (arway);
}
