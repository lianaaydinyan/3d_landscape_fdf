/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:50:59 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/17 19:51:03 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(int *arr[], t_mapolo *map)
{
	int	i;

	i = -1;
	while (++i <= map->heigth)
		free(arr[i]);
	free(arr);
}

void	char2d(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free(str);
}

void	get_map_heigth(t_mapolo *map, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		open_error();
	line = get_next_line(fd);
	if (!line)
		next_line();
	map->heigth = 0;
	while (line)
	{
		map->heigth++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_map_width(t_mapolo *map, char **av)
{
	int		fd;
	char	*line;
	int		i;

	map->width = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		open_error();
	line = get_next_line(fd);
	if (!line)
		next_line();
	i = 0;
	while (line)
	{
		i = digit_count(line, map);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (digit_count(line, map) != i)
			width_error(i);
	}
	close(fd);
}
