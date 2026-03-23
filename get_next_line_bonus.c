/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:16:06 by ialrandr          #+#    #+#             */
/*   Updated: 2026/03/23 10:08:59 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buffer_read(int buffer, int fd)
{
	char	*res;
	ssize_t	bytes_readed;

	if (!buffer || fd < 0)
		return (NULL);
	res = (char *)malloc(buffer + 1);
	if (!res)
		return (NULL);
	bytes_readed = read(fd, res, buffer);
	if (bytes_readed <= 0)
		return (free(res), NULL);
	res[bytes_readed] = '\0';
	return (res);
}

char	*extract_line(char *buffer_line)
{
	int		i;
	char	*res;
	int		newline_index;

	if (!buffer_line)
		return (NULL);
	newline_index = find_newline(buffer_line);
	if (newline_index == -1)
		newline_index = ft_strlen_gnl(buffer_line) - 1;
	res = (char *)malloc(newline_index + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (i <= newline_index && buffer_line[i])
	{
		res[i] = buffer_line[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*leftover(char *buffer_line, char *extracted_line)
{
	int		i;
	int		j;
	int		buffer_len;
	int		extracted_len;
	char	*res;

	if (!buffer_line || !extracted_line)
		return (NULL);
	i = 0;
	buffer_len = ft_strlen_gnl(buffer_line);
	extracted_len = ft_strlen_gnl(extracted_line);
	if (buffer_len == extracted_len)
		return (free(buffer_line), NULL);
	res = (char *)malloc(buffer_len - extracted_len + 1);
	if (!res)
		return (free(buffer_line), NULL);
	i = extracted_len;
	j = 0;
	while (buffer_line[i])
		res[j++] = buffer_line[i++];
	res[j] = '\0';
	return (free(buffer_line), res);
}

char	*empty_leftover(char **buffer_line, char **leftover_line, int fd)
{
	char	*extracted_line;

	*buffer_line = read_until_newline(*buffer_line, fd);
	extracted_line = extract_line(*buffer_line);
	if (!extracted_line)
	{
		free(*leftover_line);
		*leftover_line = NULL;
		return (NULL);
	}
	*leftover_line = leftover(*buffer_line, extracted_line);
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	char		*buffer_line;
	char		*temp;
	char		*extracted_line;
	static char	*leftover_line;

	if (fd < 0)
		return (NULL);
	buffer_line = buffer_read(BUFFER_SIZE, fd);
	if (!leftover_line)
		return (empty_leftover(&buffer_line, &leftover_line, fd));
	if (buffer_line)
	{
		buffer_line = read_until_newline(buffer_line, fd);
		temp = string_combo(leftover_line, buffer_line);
		extracted_line = extract_line(temp);
		leftover_line = leftover(temp, extracted_line);
		return (extracted_line);
	}
	free(buffer_line);
	extracted_line = extract_line(leftover_line);
	leftover_line = leftover(leftover_line, extracted_line);
	return (extracted_line);
}
