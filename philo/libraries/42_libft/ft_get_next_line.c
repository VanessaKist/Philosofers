/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:44:39 by coder             #+#    #+#             */
/*   Updated: 2022/11/25 21:06:25 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char	*str)
{
	char	*line;
	size_t	size;

	if (!*str)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, size + 1);
	if (str[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

static char	*get_to_next(char	*str)
{
	char	*result;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	if (str[i])
		i++;
	result = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (result == NULL)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

static char	*read_file(int fd, char *s)
{
	char	*buff;
	int		readed;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed = 1;
	while ((ft_strchr(s, '\n') == NULL) && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed <= 0)
			break ;
		buff[readed] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	if (readed < 0)
		return (NULL);
	else
		return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s = read_file(fd, s);
	if (!s)
		return (NULL);
	line = get_line(s);
	s = get_to_next(s);
	return (line);
}
