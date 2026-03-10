/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:20:27 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/09 17:13:51 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static void	free_splits(char **splits)
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	char	**splits;
	char	strategy;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	splits = parsing_all(argc, argv);
	if (!splits)
		error();
	verify_another_num_strategy(splits);
	stack_a = parsing_num(splits);
	strategy = parsing_strategy(splits);
	if (!strategy)
		strategy = 'a';
	if (parsing_strategy(splits) == 's')
		stack_a = res(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
		ft_printf("%i ", *(int *)(stack_a)->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n%c", strategy);
	ft_lstclear(&stack_a, free);
	free_splits(splits);
}
