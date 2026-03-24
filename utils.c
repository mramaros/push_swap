/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:02:13 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/24 13:59:19 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_convertion(char *str, t_list **stack_a, char **splits)
{
	int		*res;
	long	i_long;

	i_long = ft_atoi_long(str);
	if (i_long < -2147483648 || i_long > 2147483647)
		lst_clear_parsing(splits, stack_a);
	res = (int *)malloc(sizeof(int));
	if (!res)
	{
		free(res);
		error();
	}
	*res = i_long;
	return (res);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	duplicate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *stack;
	while (temp != NULL)
	{
		temp1 = temp->next;
		while (temp1 != NULL)
		{
			if (*(int *)temp->content == *(int *)temp1->content)
				return (1);
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
	return (0);
}
