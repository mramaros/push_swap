/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:40:54 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/18 10:12:59 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*indexes(t_list **stack_a)
{
	t_list	*current_node;
	t_list	*iter_node;
	int		i;
	int		size;
	int		*indexes;

	size = ft_lstsize(*stack_a);
	indexes = ft_calloc(size, sizeof(int));
	if (!indexes)
		error();
	i = 0;
	current_node = *stack_a;
	while (i < size)
	{
		iter_node = *stack_a;
		while (iter_node)
		{
			if (*(int *)iter_node->content < *(int *)current_node->content)
				indexes[i]++;
			iter_node = iter_node->next;
		}
		i++;
		current_node = current_node->next;
	}
	return (indexes);
}

static t_list	*stack_to_index(t_list **stack_a, int *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack_a;
	while (temp)
	{
		*(int *)temp->content = list[i];
		i++;
		temp = temp->next;
	}
	return (*stack_a);
}

static int	bits_count(t_list **stack_a)
{
	int	max_num;
	int	bits_count;

	bits_count = 0;
	max_num = ft_lstsize(*stack_a) - 1;
	while (max_num != 0)
	{
		bits_count++;
		max_num = max_num >> 1;
	}
	return (bits_count);
}

static void	radix(t_list **stack_a, t_list **stack_b, int i, int *tab)
{
	int	j;
	int	size;

	j = 0;
	size = ft_lstsize(*stack_a);
	while (j < size)
	{
		if (((*(int *)(*stack_a)->content >> i) & 1) == 0)
		{
			push(stack_a, stack_b);
			ft_printf("pb\n");
			tab[5]++;
		}
		else
		{
			rotate(stack_a);
			ft_printf("ra\n");
			tab[6]++;
		}
		j++;
	}
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
		tab[4]++;
	}
}

void	complex(t_list **stack_a, t_list **stack_b, int *tab)
{
	int	*list;
	int	bits;
	int	i;

	list = indexes(stack_a);
	*stack_a = stack_to_index(stack_a, list);
	bits = bits_count(stack_a);
	i = 0;
	while (i < bits)
	{
		radix(stack_a, stack_b, i, tab);
		i++;
	}
	free(list);
}
