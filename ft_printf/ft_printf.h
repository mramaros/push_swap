/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:57:24 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/08 08:36:31 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
int		character_check(int c, va_list ap);
char	*ft_hex(unsigned long n, char c);
char	*ft_ltoa(long nbr);
size_t	char_c(char c);
size_t	char_s(char *str);
size_t	char_p(unsigned long n);
size_t	char_d(int n);
size_t	char_u(unsigned int n);
size_t	char_x(unsigned int n, char c);

#endif
