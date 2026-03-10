/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequences.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:05:22 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/10 12:35:53 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	*stack = second;
	(*stack)->next = first;
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_stack_a;
	t_list	*second_stack_a;

	if (!*stack_a)
		return ;
	first_stack_a = *stack_a;
	if (first_stack_a->next)
	{
		second_stack_a = first_stack_a->next;
		*stack_a = second_stack_a;
	}
	else
		*stack_a = NULL;
	ft_lstadd_front(stack_b, first_stack_a);
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*stack)
		return ;
	first = *stack;
	second = first->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	*stack = second;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*before_last;
	t_list	*last;
	t_list	*temp;

	first = *stack;
	last = ft_lstlast(*stack);
	temp = *stack;
	while (temp->next != last)
		temp = temp->next;
	before_last = temp;
	last->next = first;
	*stack = last;
	before_last->next = NULL;
}
