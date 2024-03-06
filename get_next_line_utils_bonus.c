/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:17:30 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/11 13:30:35 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *string, char *buf)
{
	int		i;
	int		j;
	char	*str;

	if (!string)
	{
		string = (char *)malloc(1 * sizeof(char));
		string[0] = '\0';
	}
	if (!string || !buf)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(string) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (string)
		while (string[++i] != '\0')
			str[i] = string[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(string) + ft_strlen(buf)] = '\0';
	free(string);
	return (str);
}
