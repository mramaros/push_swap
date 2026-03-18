/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:54:23 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/18 10:40:58 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

typedef struct s_chunk
{
	int	min;
	int	max;
	int	needed;
	int	pushed;
}				t_chunk;

char	**parsing_all(char **argv);
t_list	*parsing_num(char **splits);
char	parsing_strategy(char **argv);
int		duplicate(t_list **stack);
int		ft_strcmp(char *str1, char *str2);
double	compute_disorder(t_list *a);

long	ft_atoi_long(const char *nptr);
int		*int_convertion(char *str);
int		is_int(char *str);

void	bench_print(double disorder, char strategy, int *tab);
void	tab_content(int *tab);

void	error(void);
void	lst_clear(t_list **stack);
char	verify_commands(char *argv);
void	verify_another_num_strategy(char **splits);
int		search_bench(char **argv);

t_list	*simple(t_list **stack_a, t_list **stack_b, int *tab);
void	rotate_backward_to_min(t_list **stack_a, int cost_rra, int *tab);
void	rotate_forward_to_min(t_list **stack_a, int cost_ra, int *tab);
int		min_index(t_list **stack_a);

int		ft_sqrt(int nb);
void	swap_arway(int *a, int *b);
int		partition(int *arway, int min, int max);
void	sorting_index(int *tab, int min, int max);
int		*stack_arway(t_list **stack_a, int size);
void	assign_index(t_list **stack_a, int *arway, int size);
void	assing_index(t_list **stack_a);

int		find_index_in_b(t_list *stack_b, int target);
void	bring_to_top(t_list **stack_b, int pos, int size, int *tab);
void	push_to_b(t_list **stack_a, t_list **stack_b, t_chunk *c, int *tab);
void	push_all_to_b(t_list **stack_a, t_list **stack_b, int *tab);
void	push_back_to_a(t_list **stack_a, t_list **stack_b, int *tab);
void	medium_algo(t_list **stack_a, t_list **stack_b, int *tab);

void	complex(t_list **stack_a, t_list **stack_b, int *tab);

char	adaptive_algo(t_list **stack_a, t_list **stack_b, double disorder,
		 int *tab);

void	swap(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

#endif
