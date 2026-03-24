/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:26:14 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/24 14:45:50 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "ft_printf/ft_printf.h"
# include "get_next_line_bonus.h"
# include "push_swap.h"

void	checker(t_list **stack_a, t_list **stack_b);

void	free_stack(t_list **stack_a, t_list **stack_b, char *line);
void	lst_clear_parsing(char **splits, t_list **stack_a);
void	free_splits_bonus(char **splits);

#endif
