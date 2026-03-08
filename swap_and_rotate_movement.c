/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@42antananarivo.mg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 09:03:21 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/08 14:51:01 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_list	*swap_a(t_list *stack_a)
{
	void	*tmp;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	return (stack_a);
}

t_list	*rotate_ra(t_list *stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	stack_a = stack_a->next;
	first->next = NULL;
	last = ft_lstlast(stack_a);
	last->next = first;
	return (stack_a);
}
