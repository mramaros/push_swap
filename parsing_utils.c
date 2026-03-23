#include "push_swap.h"

void	lst_clear_parsing(t_list **stack, char **splits)
{
	free_parsing(splits, stack);
	error();
}

void	free_parsing(char **splits, t_list **stack_a)
{
	int	i;

	i = 0;
	ft_lstclear(stack_a, free);
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}