/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:54:23 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/04 18:59:18 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

char	***parsing_all(int argc, char **argv);
t_list	*parsing_num(char ***splits);
char	parsing_strategy(char **argv);

long	ft_atoi_long(const char *nptr);
void	error(void);
void	lst_clear(t_list **stack);
int		*int_convertion(char *str);
int		duplicate(t_list **stack);
int		is_int(char *str);
char	verify_commands(char *argv);
#endif
