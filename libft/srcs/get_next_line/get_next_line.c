/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:29:01 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/11 20:39:19 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*get_line(char *str)
{
	char	*line;
	int		len;

	if (!str[0])
		return (NULL);
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	line = malloc((len * sizeof(char) + 1 + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
	{
		line[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		line[len] = '\n';
		len++;
	}
	line[len] = '\0';
	return (line);
}

static char	*get_rest(char *str)
{
	int			len;
	int			len_rest;
	char		*rest;

	len = 0;
	len_rest = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\0')
	{
		free(str);
		return (NULL);
	}
	rest = malloc((ft_strlen(str) - len) * sizeof(char) + 1);
	if (!rest)
		return (NULL);
	len++;
	while (str[len] != '\0')
		rest[len_rest++] = str[len++];
	rest[len_rest] = '\0';
	free(str);
	return (rest);
}

static char	*get_buffer(char *str, int fd)
{
	char	*array;
	int		bytes;

	array = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!array)
		return (NULL);
	bytes = 1;
	while (!ft_strchr_gnl(str, '\n') && bytes != 0)
	{
		bytes = read(fd, array, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(array);
			return (NULL);
		}
		array[bytes] = '\0';
		str = ft_strjoin_gnl(str, array);
	}
	free(array);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_buffer(str, fd);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_rest(str);
	return (line);
}
