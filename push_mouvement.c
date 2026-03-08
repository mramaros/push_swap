/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_mouvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:02:09 by mramaros          #+#    #+#             */
/*   Updated: 2026/03/08 15:18:51 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
}

void	print_stack(char *name, t_list *stack)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", *(int *)stack->content);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	int	a = 1;
	int	b = 2;
	int	c = 3;
	int	d = 4;

	ft_lstadd_back(&stack_a, ft_lstnew(&a));
	ft_lstadd_back(&stack_a, ft_lstnew(&b));
	ft_lstadd_back(&stack_a, ft_lstnew(&c));
	ft_lstadd_back(&stack_a, ft_lstnew(&d));

	printf("Initial stacks\n");
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n--- pb ---\n");
	push_b(&stack_a, &stack_b);
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n--- pb ---\n");
	push_b(&stack_a, &stack_b);
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n--- pa ---\n");
	push_a(&stack_a, &stack_b);
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	return (0);
}
