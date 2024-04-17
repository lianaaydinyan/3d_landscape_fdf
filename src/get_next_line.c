/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <liaydiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:07:41 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/11 01:36:26 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	freee(char *str)
{
	free(str);
	str = 0;
}

char	*get_tox(char *str)
{
	char	*buf;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	buf = malloc(sizeof(char) * i + 1);
	if (!buf)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buf[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char	*get_hajord(char *line)
{
	char	*hajord;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free (line);
		return (NULL);
	}
	hajord = malloc(sizeof(char) *(ft_strlen(line) - i + 1));
	if (!hajord)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		hajord[j++] = line[i++];
	hajord[j] = '\0';
	free (line);
	return (hajord);
}

char	*readingg(int fd, char *strr)
{
	char	*buf;
	char	*line;
	int		rb;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rb = 1;
	while (!ft_strchr(strr, '\n') && rb != 0)
	{
		rb = read(fd, buf, BUFFER_SIZE);
		if (rb == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[rb] = '\0';
		line = ft_strdup(strr);
		freee (strr);
		strr = ft_strjoin(line, buf);
		freee (line);
	}
	free (buf);
	return (strr);
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*buf;

	s = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = readingg(fd, buf);
	if (!buf)
		return (NULL);
	s = get_tox (buf);
	buf = get_hajord(buf);
	if (!s[0])
	{
		freee (s);
		freee (buf);
		return (NULL);
	}
	return (s);
}
