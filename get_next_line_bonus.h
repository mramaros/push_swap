/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:16:11 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/19 12:05:14 by mramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*buffer_read(int buffer, int fd);
int		find_newline(char *buffer_line);
char	*extract_line(char *buffer_line);
int		ft_strlen_gnl(char *s);
char	*leftover(char *buffer_line, char *extracted_line);
char	*string_combo(char *str1, char *str2);
char	*read_until_newline(char *buffer_line, int fd);
char	*empty_leftover(char **buffer_line, char **leftover_line, int fd);

#endif
