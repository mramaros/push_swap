/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:31:04 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/19 12:28:47 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	seq_ab(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "ss\n"))
		swap_ab(stack_a, stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		rotate_ab(stack_a, stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		reverse_rotate_ab(stack_a, stack_b);
}

static void	run_sequence(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(line, "pb\n"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(line, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(stack_b);
	else
		seq_ab(stack_a, stack_b, line);
}

static void	fail(void)
{
	ft_printf(1, "KO\n");
	exit(EXIT_FAILURE);
}

static void	success(void)
{
	ft_printf(1, "OK\n");
	exit(EXIT_SUCCESS);
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	double	disorder;
	char	*line;

	disorder = compute_disorder(*stack_a);
	if (!disorder)
		success();
	line = get_next_line(0);
	while (line)
	{
		run_sequence(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	disorder = compute_disorder(*stack_a);
	if (!disorder && !*stack_b)
		success();
	fail();
}
