/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:54:23 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/11 11:19:17 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

char	**parsing_all(int argc, char **argv);
t_list	*parsing_num(char **splits);
char	parsing_strategy(char **argv);
int		duplicate(t_list **stack);
int		ft_strcmp(char *str1, char *str2);

long	ft_atoi_long(const char *nptr);
int		*int_convertion(char *str);
int		is_int(char *str);

void	error(void);
void	lst_clear(t_list **stack);
char	verify_commands(char *argv);
void	verify_another_num_strategy(char **splits);

t_list	*simple(t_list **stack_a, t_list **stack_b);

void	swap(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
#endif
