/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:02:13 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/02 17:08:17 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_convertion(char *str)
{
	int		i;
	int		*res;
	long	i_long;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (NULL);
		i++;
	}
	i_long = ft_atoi_long(str);
	if (i_long < -2147483648 || i_long > 2147483647)
		return (NULL);
	res = (int *)malloc(sizeof(int));
	if (!res)
		return (NULL);
	*res = i_long;
	return (res);
}
void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	lst_clear(t_list **stack)
{
	ft_lstclear(stack, free);
	error();
}

int	duplicate(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (*(int *)(temp)->content == *(int *)(temp)->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
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
