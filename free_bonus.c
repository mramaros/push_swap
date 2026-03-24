/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:44:02 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/24 15:02:03 by ialrandr         ###   ########.fr       */
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

void	free_splits_bonus(char **splits)
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

void	free_stack(t_list **stack_a, t_list **stack_b, char *line)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	free(line);
	error();
}
