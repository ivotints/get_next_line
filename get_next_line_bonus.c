/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:17:41 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/13 13:26:24 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_new_line(char *string)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	new_line = (char *)malloc((ft_strlen(string) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (string[i])
		new_line[j++] = string[i++];
	new_line[j] = '\0';
	free(string);
	return (new_line);
}

char	*ft_next_line(char *string)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	next_line = (char *)malloc((i + 2) * sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		next_line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		next_line[i] = string[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_reader(int fd, char *string)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while ((!ft_strchr(string, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		string = ft_strjoin(string, buf);
	}
	free(buf);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string[10000];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	string[fd] = ft_reader(fd, string[fd]);
	if (!string[fd])
		return (NULL);
	next_line = ft_next_line(string[fd]);
	string[fd] = ft_new_line(string[fd]);
	return (next_line);
}

/* int main()
{
	char *string;
	int fd = open("txt", O_RDONLY);
	int fd2 = open("txt2", O_RDONLY);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd2); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd2); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd2); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd2); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd2); printf("Your string: %s", string); free(string);
	string = get_next_line(fd); printf("Your string: %s", string); free(string);
	string = get_next_line(fd2); printf("Your string: %s", string); free(string);
	close(fd);
	close(fd2);
} */
