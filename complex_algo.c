/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:40:54 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/16 11:37:57 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*long_convertion(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		*(long *)temp->content = (long)2147483648 + *(int *)temp->content;
		temp = temp->next;
	}
	return (*stack_a);
}

static t_list	*back_to_normal(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		*(int *)temp->content = *(long *)temp->content - (long)2147483648;
		temp = temp->next;
	}
	return (*stack_a);
}

static int	*value_counter(t_list **stack_a, int pass)
{
	t_list	*temp;
	int		*table;
	int		index;

	temp = *stack_a;
	table = ft_calloc(256, sizeof(int));
	if (!table)
		error();
	while (temp)
	{
		index = (((*(long *)temp->content) >> (pass * 8)) & 0xFF);
		table[index]++;
		temp = temp->next;
	}
	return (table);
}

static int	search_index(t_list **stack_a, int i, int pass)
{
	int		index;
	t_list	*temp;

	index = -1;
	temp = *stack_a;
	while (temp)
	{
		index++;
		if (((*(long *)temp->content >> (pass * 8)) & 0xFF) == i)
			return (index);
		temp = temp->next;
	}
	return (-1);
}

static void	algo(t_list **stack_a, t_list **stack_b, int *table, int pass)
{
	int	i;
	int	j;
	int	size;
	int	index;

	i = 0;
	while (i < 256)
	{
		if (table[i])
		{
			size = ft_lstsize(*stack_a);
			j = 0;
			while (j < table[i])
			{
				index = search_index(stack_a, i, pass);
				if (index == -1)
				{
					ft_printf("index = -1, error");
					return ;
				}
				if (index < size - index)
				{
					rotate_forward(stack_a, index);
					push(stack_a, stack_b);
					ft_printf("pb\n");
				}
				else if (size - index < index)
				{
					rotate_backward(stack_a, size - index);
					push(stack_a, stack_b);
					ft_printf("pb\n");
				}
				else
				{
					rotate_forward(stack_a, index);
					push(stack_a, stack_b);
					ft_printf("pb\n");
				}
				j++;
			}
		}
		i++;
	}
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

t_list	*radix(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	*table;

	i = 0;
	*stack_a = long_convertion(stack_a);
	while (i < 4)
	{
		table = value_counter(stack_a, i);
		algo(stack_a, stack_b, table, i);
		i++;
		free(table);
	}
	back_to_normal(stack_a);
	return (*stack_a);
}
