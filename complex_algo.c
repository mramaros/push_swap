/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:40:54 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/15 13:09:00 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *long_convertion(t_list **stack_a)
{
	t_list *temp = *stack_a;

	while (temp)
	{
		*(long *)temp->content = (long)2147483648 + *(int *)temp->content;
		temp = temp->next;
	}
	return (*stack_a);
}

static t_list *back_to_normal(t_list **stack_a)
{
	t_list *temp = *stack_a;

	while (temp)
	{
		*(int *)temp->content = (long)2147483648 - *(int *)temp->content;
		temp = temp->next;
	}
	return (*stack_a);
}

// static void push_loop(t_list **stack_a, t_list **stack_b)
// {
// 	while (*stack_a)
// 		push(stack_a, stack_b);
// }

static int *value_counter(t_list **stack_a, int pass)
{
	t_list *temp;
	int *table;

	temp = *stack_a;
	table = ft_calloc(256, sizeof(int));
	if (!table)
		error();
	while (temp)
	{
		int index = ((*(long *)temp->content) >> (pass * 8)) & 0xFF;
		table[index]++;
		temp = temp->next;
	}
	return (table);
}

t_list *radix(t_list **stack_a, t_list **stack_b)
{
	int i;
	int *table;

	(void)stack_b;
	i = 0;
	*stack_a = long_convertion(stack_a);
	while (i < 4)
	{
		int j = 0;
		table = value_counter(stack_a, i);
		while (j >= 0 && j < 256)
		{
			if (table[j])
				ft_printf("%d = %d ", j, table[j]);
			j++;
		}
		ft_printf("\n");
		i++;
		free(table);
	}
	back_to_normal(stack_a);
	return (*stack_a);
}

/*
6 = 00000000 00000000 00000000 00000110  00000110
20 = 00000000 00000000 00000000 00010100 00010100
13 = 00000000 00000000 00000000 00001101 00001101
15 = 00000000 00000000 00000000 00001111 00001111
7 = 00000000 00000000 00000000 00000111  00000111

2147483654 = 10000000 00000000 00000000 00000110
2147483668 = 10000000 00000000 00000000 00010100
2147483661 = 10000000 00000000 00000000 00001101
2147483663 = 10000000 00000000 00000000 00001111
2147483655 = 10000000 00000000 00000000 00000111

*/
