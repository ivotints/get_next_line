/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:56:28 by ivotints          #+#    #+#             */
/*   Updated: 2024/11/02 00:26:14 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	while (str && *str && *str != c)
		++str;
	if (str && *str && *str == c)
		return (str);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

char	*ft_strjoin(char *buffer, char *line)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(ft_strlen(buffer) + ft_strlen(line) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (buffer && buffer[i])
	{
		result[i] = buffer[i];
		++i;
	}
	j = 0;
	while (line && line[j])
	{
		result[i + j] = line[j];
		++j;
	}
	result[i + j] = 0;
	free(buffer);
	return (result);
}
