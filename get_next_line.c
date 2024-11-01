/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:50:46 by ivotints          #+#    #+#             */
/*   Updated: 2024/11/02 00:27:21 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_return_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (buffer[i] == '\n')
		++i;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = 0;
	while (i)
	{
		--i;
		line[i] = buffer[i];
	}
	return (line);
}

char	*get_trimmed_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (buffer[i] == '\n')
		++i;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (buffer[i + j])
	{
		new_buffer[j] = buffer[i + j];
		++j;
	}
	new_buffer[j] = 0;
	return (free(buffer), new_buffer);
}

char	*ft_reader(int fd, char *buffer)
{
	char	*line;
	int		readed;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	readed = 1;
	while (!ft_strchr(buffer, '\n') && readed)
	{
		readed = read(fd, line, BUFFER_SIZE);
		if (readed == -1 || readed == 0)
		{
			free(line);
			return (NULL);
		}
		line[readed] = 0;
		buffer = ft_strjoin(buffer, line);
	}
	return (free(line), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_reader(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_return_line(buffer);
	buffer = get_trimmed_buffer(buffer);
	return (line);
}
